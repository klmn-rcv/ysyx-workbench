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

    val uart_base = "h10000000".U(32.W)
    val clint_mtime_lo = "h0200bff8".U(32.W)
    val clint_mtime_hi = "h0200bffc".U(32.W)

    val ar_fire = io.arbiter.arvalid && io.arbiter.arready
    val r_fire = io.arbiter.rvalid && io.arbiter.rready
    val aw_fire = io.arbiter.awvalid && io.arbiter.awready
    val w_fire = io.arbiter.wvalid && io.arbiter.wready
    val b_fire = io.arbiter.bvalid && io.arbiter.bready

    val (_, ar_fire_after) = bool_preserve(ar_fire, r_fire, false.B)
    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, b_fire, false.B)
    val (w_fire_preserved, w_fire_after) = bool_preserve(w_fire, b_fire, false.B)
    val write_req_complete = aw_fire_preserved && w_fire_preserved

    val hit_clint_r = io.arbiter.araddr === clint_mtime_lo || io.arbiter.araddr === clint_mtime_hi
    val hit_uart_w = io.arbiter.awaddr === uart_base
    val hit_clint_w = io.arbiter.awaddr === clint_mtime_lo || io.arbiter.awaddr === clint_mtime_hi
    val hit_soc_r = !hit_clint_r
    val hit_soc_w = !hit_clint_w

    val owner_soc :: owner_clint :: Nil = Enum(2)
    val read_owner = RegInit(owner_soc)
    val write_owner = RegInit(owner_soc)
    val write_skip_ref = RegInit(false.B)

    when(ar_fire) {
        read_owner := Mux(hit_clint_r, owner_clint, owner_soc)
    }
    when(aw_fire) {
        write_owner := Mux(hit_clint_w, owner_clint, owner_soc)
        write_skip_ref := hit_uart_w
    }

    // AR
    connectFields(io.arbiter.ar, io.soc.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    connectFields(io.arbiter.ar, io.clint.axi.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    io.soc.arvalid := io.arbiter.arvalid && hit_soc_r && !ar_fire_after
    io.clint.axi.arvalid := io.arbiter.arvalid && hit_clint_r && !ar_fire_after
    io.arbiter.arready := !ar_fire_after && Mux(hit_clint_r, io.clint.axi.arready, io.soc.arready)

    // R
    when(read_owner === owner_clint) {
        connectFields(io.clint.axi.r, io.arbiter.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
        io.soc.rready := false.B
    }.otherwise {
        connectFields(io.soc.r, io.arbiter.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
        io.clint.axi.rready := false.B
    }
    io.r_need_skip_ref := Mux(read_owner === owner_clint, io.clint.r_need_skip_ref, false.B)

    // AW
    connectFields(io.arbiter.aw, io.soc.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    connectFields(io.arbiter.aw, io.clint.axi.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    io.soc.awvalid := io.arbiter.awvalid && hit_soc_w && !aw_fire_after
    io.clint.axi.awvalid := io.arbiter.awvalid && hit_clint_w && !aw_fire_after
    io.arbiter.awready := !aw_fire_after && Mux(hit_clint_w, io.clint.axi.awready, io.soc.awready)

    // W
    connectFields(io.arbiter.w, io.soc.w, "wdata", "wstrb", "wlast")
    connectFields(io.arbiter.w, io.clint.axi.w, "wdata", "wstrb", "wlast")
    io.soc.wvalid := io.arbiter.wvalid && hit_soc_w && !w_fire_after
    io.clint.axi.wvalid := io.arbiter.wvalid && hit_clint_w && !w_fire_after
    io.arbiter.wready := !w_fire_after && Mux(hit_clint_w, io.clint.axi.wready, io.soc.wready)

    // B
    when(write_owner === owner_clint) {
        connectFields(io.clint.axi.b, io.arbiter.b, "bvalid", "bresp", "bid", "bready")
        io.soc.bready := false.B
    }.otherwise {
        connectFields(io.soc.b, io.arbiter.b, "bvalid", "bresp", "bid", "bready")
        io.clint.axi.bready := false.B
    }
    io.b_need_skip_ref := write_owner === owner_soc && write_skip_ref
}
