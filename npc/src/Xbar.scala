package cpu

import chisel3._
import chisel3.util._

class Xbar extends Module with HasYsyxModuleName {
    override protected def moduleSuffix: String = "Xbar"
    val io = IO(new Bundle {
        val arbiter = Flipped(new AXI4(32, 32, 4))
        val soc = new AXI4(32, 32, 4)
        val clint = new Bundle {
            val axi = new AXI4(32, 32, 4)
            val r_need_skip_ref = Input(Bool())
        }
        val r_need_skip_ref = Output(Bool())
        val b_need_skip_ref = Output(Bool())
    })

    val clint_mtime_lo = "h0200bff8".U(32.W)
    val clint_mtime_hi = "h0200bffc".U(32.W)
    val mrom_base = "h20000000".U(32.W)
    val mrom_end  = "h20000fff".U(32.W)
    val sram_base = "h0f000000".U(32.W)
    val sram_end  = "h0f001fff".U(32.W)

    val ar_fire = io.arbiter.arvalid && io.arbiter.arready
    val r_fire = io.arbiter.rvalid && io.arbiter.rready
    val aw_fire = io.arbiter.awvalid && io.arbiter.awready
    val w_fire = io.arbiter.wvalid && io.arbiter.wready
    val b_fire = io.arbiter.bvalid && io.arbiter.bready

    val (_, ar_fire_after) = bool_preserve(ar_fire, r_fire, false.B)
    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, b_fire, false.B)
    val (w_fire_preserved, w_fire_after) = bool_preserve(w_fire, b_fire, false.B)
    val write_req_complete = aw_fire_preserved && w_fire_preserved

    def inRange(addr: UInt, base: UInt, end: UInt): Bool = addr >= base && addr <= end

    val hit_clint_r = io.arbiter.araddr === clint_mtime_lo || io.arbiter.araddr === clint_mtime_hi
    val hit_clint_w = io.arbiter.awaddr === clint_mtime_lo || io.arbiter.awaddr === clint_mtime_hi
    val hit_mrom_r = inRange(io.arbiter.araddr, mrom_base, mrom_end)
    val hit_mrom_w = inRange(io.arbiter.awaddr, mrom_base, mrom_end) // 这个虽然不对，但不是地址错误，所以还是需要发给SoC
    val hit_sram_r = inRange(io.arbiter.araddr, sram_base, sram_end)
    val hit_sram_w = inRange(io.arbiter.awaddr, sram_base, sram_end)
    val hit_soc_r = hit_mrom_r || hit_sram_r
    val hit_soc_w = hit_mrom_w || hit_sram_w
    val hit_error_r = !hit_clint_r && !hit_soc_r
    val hit_error_w = !hit_clint_w && !hit_soc_w

    val owner_soc :: owner_clint :: owner_error :: Nil = Enum(3)
    val read_owner = RegInit(owner_soc)
    val write_owner = RegInit(owner_soc)
    val write_skip_ref = RegInit(false.B)

    // 地址错误相关的信号，由于没有一个专门处理错误的从设备，所以需要在Xbar里处理
    val error_write_req_complete_pulse = Wire(Bool())
    val error_rvalid = boolreg_set_clear(ar_fire && hit_error_r, r_fire && read_owner === owner_error)
    val error_bvalid = boolreg_set_clear(error_write_req_complete_pulse, b_fire && write_owner === owner_error)
    val error_rid = RegInit(0.U(4.W))
    val error_bid = RegInit(0.U(4.W))

    error_write_req_complete_pulse := write_req_complete && !error_bvalid && write_owner === owner_error

    when(ar_fire) {
        read_owner := Mux(hit_clint_r, owner_clint, Mux(hit_soc_r, owner_soc, owner_error))
        when(hit_error_r) {
            error_rid := io.arbiter.arid
        }
    }
    when(aw_fire) {
        write_owner := Mux(hit_clint_w, owner_clint, Mux(hit_soc_w, owner_soc, owner_error))
        write_skip_ref := io.arbiter.awaddr === "h10000000".U(32.W) // 仅暂时用于skip_ref逻辑，不用于Xbar分发逻辑（uart实际上在soc里）
        when(hit_error_w) {
            error_bid := io.arbiter.awid
        }
    }

    // AR
    connectFields(io.arbiter.ar, io.soc.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    connectFields(io.arbiter.ar, io.clint.axi.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    io.soc.arvalid := io.arbiter.arvalid && hit_soc_r && !ar_fire_after
    io.clint.axi.arvalid := io.arbiter.arvalid && hit_clint_r && !ar_fire_after
    io.arbiter.arready := !ar_fire_after && Mux(hit_clint_r, io.clint.axi.arready, Mux(hit_soc_r, io.soc.arready, !error_rvalid))

    // R
    io.soc.rready := false.B
    io.clint.axi.rready := false.B
    when(read_owner === owner_clint) {
        connectFields(io.clint.axi.r, io.arbiter.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
    }.elsewhen(read_owner === owner_soc) {
        connectFields(io.soc.r, io.arbiter.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
    }.otherwise {  // 地址error
        io.arbiter.rvalid := error_rvalid
        io.arbiter.rdata := 0.U
        io.arbiter.rresp := AXI4Resp.DECERR
        io.arbiter.rid := error_rid
        io.arbiter.rlast := true.B
    }
    io.r_need_skip_ref := Mux(read_owner === owner_clint, io.clint.r_need_skip_ref, false.B)

    // AW
    connectFields(io.arbiter.aw, io.soc.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    connectFields(io.arbiter.aw, io.clint.axi.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    io.soc.awvalid := io.arbiter.awvalid && hit_soc_w && !aw_fire_after
    io.clint.axi.awvalid := io.arbiter.awvalid && hit_clint_w && !aw_fire_after
    io.arbiter.awready := !aw_fire_after && Mux(hit_clint_w, io.clint.axi.awready, Mux(hit_soc_w, io.soc.awready, !error_bvalid))

    // W
    connectFields(io.arbiter.w, io.soc.w, "wdata", "wstrb", "wlast")
    connectFields(io.arbiter.w, io.clint.axi.w, "wdata", "wstrb", "wlast")
    io.soc.wvalid := io.arbiter.wvalid && hit_soc_w && !w_fire_after
    io.clint.axi.wvalid := io.arbiter.wvalid && hit_clint_w && !w_fire_after
    io.arbiter.wready := !w_fire_after && Mux(hit_clint_w, io.clint.axi.wready, Mux(hit_soc_w, io.soc.wready, !error_bvalid))

    // B
    io.soc.bready := false.B
    io.clint.axi.bready := false.B
    when(write_owner === owner_clint) {
        connectFields(io.clint.axi.b, io.arbiter.b, "bvalid", "bresp", "bid", "bready")
    }.elsewhen(write_owner === owner_soc) {
        connectFields(io.soc.b, io.arbiter.b, "bvalid", "bresp", "bid", "bready")
    }.otherwise {  // 地址error
        io.arbiter.bvalid := error_bvalid
        io.arbiter.bresp := AXI4Resp.DECERR
        io.arbiter.bid := error_bid
    }
    io.b_need_skip_ref := write_owner === owner_soc && write_skip_ref
}
