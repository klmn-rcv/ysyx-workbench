package cpu

import chisel3._
import chisel3.util._

class Xbar extends Module with HasYsyxModuleName {
    override protected def moduleSuffix: String = "Xbar"
    val io = IO(new Bundle {
        val arbiter = Flipped(new AXI4(32, 32, 4))
        val soc = new AXI4(32, 32, 4)
        val clint = new AXI4(32, 32, 4)
        val addrerr = new AXI4(32, 32, 4)
        val clint_r_need_skip_ref = Input(Bool())
        val r_need_skip_ref = Output(Bool())
        val b_need_skip_ref = Output(Bool())
    })

    val clint_mtime_lo = "h0200bff8".U(32.W)
    val clint_mtime_hi = "h0200bffc".U(32.W)
    val soc_mrom_base = "h20000000".U(32.W)
    val soc_mrom_end  = "h20000fff".U(32.W)
    val soc_sram_base = "h0f000000".U(32.W)
    val soc_sram_end  = "h0f001fff".U(32.W)
    val soc_flash_base = "h30000000".U(32.W)
    val soc_flash_end  = "h3fffffff".U(32.W)
    val soc_uart_base = "h10000000".U(32.W)
    val soc_uart_end = "h10000fff".U(32.W)
    val soc_psram_base = "h80000000".U(32.W)
    val soc_psram_end = "h803fffff".U(32.W)

    val ar_fire = io.arbiter.arvalid && io.arbiter.arready
    val r_fire = io.arbiter.rvalid && io.arbiter.rready
    val aw_fire = io.arbiter.awvalid && io.arbiter.awready
    val w_fire = io.arbiter.wvalid && io.arbiter.wready
    val b_fire = io.arbiter.bvalid && io.arbiter.bready

    val (_, ar_fire_after) = bool_preserve(ar_fire, r_fire, false.B)
    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, b_fire, false.B)
    val (w_fire_preserved, w_fire_after) = bool_preserve(w_fire, b_fire, false.B)

    def inRange(addr: UInt, base: UInt, end: UInt): Bool = addr >= base && addr <= end

    val hit_clint_r = io.arbiter.araddr === clint_mtime_lo || io.arbiter.araddr === clint_mtime_hi
    val hit_clint_w = io.arbiter.awaddr === clint_mtime_lo || io.arbiter.awaddr === clint_mtime_hi
    val hit_soc_mrom_r = inRange(io.arbiter.araddr, soc_mrom_base, soc_mrom_end)
    val hit_soc_mrom_w = inRange(io.arbiter.awaddr, soc_mrom_base, soc_mrom_end) // 这个虽然不对，但不是地址错误，所以还是需要发给SoC
    val hit_soc_sram_r = inRange(io.arbiter.araddr, soc_sram_base, soc_sram_end)
    val hit_soc_sram_w = inRange(io.arbiter.awaddr, soc_sram_base, soc_sram_end)
    val hit_soc_flash_r = inRange(io.arbiter.araddr, soc_flash_base, soc_flash_end)
    val hit_soc_flash_w = inRange(io.arbiter.awaddr, soc_flash_base, soc_flash_end)
    val hit_soc_uart_r = inRange(io.arbiter.araddr, soc_uart_base, soc_uart_end)
    val hit_soc_uart_w = inRange(io.arbiter.awaddr, soc_uart_base, soc_uart_end)
    val hit_soc_psram_r = inRange(io.arbiter.araddr, soc_psram_base, soc_psram_end)
    val hit_soc_psram_w = inRange(io.arbiter.awaddr, soc_psram_base, soc_psram_end)
    val hit_soc_r = hit_soc_mrom_r || hit_soc_sram_r || hit_soc_flash_r || hit_soc_uart_r || hit_soc_psram_r
    val hit_soc_w = hit_soc_mrom_w || hit_soc_sram_w || hit_soc_flash_w || hit_soc_uart_w || hit_soc_psram_w
    val hit_addrerr_r = !hit_clint_r && !hit_soc_r
    val hit_addrerr_w = !hit_clint_w && !hit_soc_w

    val owner_soc :: owner_clint :: owner_addrerr :: Nil = Enum(3)
    val read_owner = RegInit(owner_soc)
    val write_owner = RegInit(owner_soc)
    val hit_soc_uart_r_preserved = bool_preserve(ar_fire && hit_soc_uart_r, r_fire, false.B)._1
    val hit_soc_uart_w_preserved = bool_preserve(aw_fire && hit_soc_uart_w, b_fire, false.B)._1

    when(ar_fire) {
        read_owner := Mux(hit_clint_r, owner_clint, Mux(hit_soc_r, owner_soc, owner_addrerr))
        // uart_r_skip_ref := hit_soc_uart_r // 仅暂时用于skip_ref逻辑，不用于Xbar分发逻辑（uart实际上在soc里）
    }
    when(aw_fire) {
        write_owner := Mux(hit_clint_w, owner_clint, Mux(hit_soc_w, owner_soc, owner_addrerr))
        // uart_w_skip_ref := hit_soc_uart_w // 仅暂时用于skip_ref逻辑，不用于Xbar分发逻辑（uart实际上在soc里）
    }

    // AR
    connectFields(io.arbiter.ar, io.soc.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    connectFields(io.arbiter.ar, io.clint.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    connectFields(io.arbiter.ar, io.addrerr.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    io.soc.arvalid := io.arbiter.arvalid && hit_soc_r && !ar_fire_after
    io.clint.arvalid := io.arbiter.arvalid && hit_clint_r && !ar_fire_after
    io.addrerr.arvalid := io.arbiter.arvalid && hit_addrerr_r && !ar_fire_after
    io.arbiter.arready := !ar_fire_after && Mux(hit_clint_r, io.clint.arready, Mux(hit_soc_r, io.soc.arready, io.addrerr.arready))

    // R
    io.soc.rready := false.B
    io.clint.rready := false.B
    io.addrerr.rready := false.B
    when(read_owner === owner_clint) {
        connectFields(io.clint.r, io.arbiter.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
    }.elsewhen(read_owner === owner_soc) {
        connectFields(io.soc.r, io.arbiter.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
    }.otherwise {   // read_owner === owner_addrerr
        connectFields(io.addrerr.r, io.arbiter.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
    }
    io.r_need_skip_ref := Mux(read_owner === owner_clint, io.clint_r_need_skip_ref,
                            Mux(read_owner === owner_soc, hit_soc_uart_r_preserved, false.B))

    // AW
    connectFields(io.arbiter.aw, io.soc.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    connectFields(io.arbiter.aw, io.clint.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    connectFields(io.arbiter.aw, io.addrerr.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    io.soc.awvalid := io.arbiter.awvalid && hit_soc_w && !aw_fire_after
    io.clint.awvalid := io.arbiter.awvalid && hit_clint_w && !aw_fire_after
    io.addrerr.awvalid := io.arbiter.awvalid && hit_addrerr_w && !aw_fire_after
    io.arbiter.awready := !aw_fire_after && Mux(hit_clint_w, io.clint.awready, Mux(hit_soc_w, io.soc.awready, io.addrerr.awready))

    // W
    connectFields(io.arbiter.w, io.soc.w, "wdata", "wstrb", "wlast")
    connectFields(io.arbiter.w, io.clint.w, "wdata", "wstrb", "wlast")
    connectFields(io.arbiter.w, io.addrerr.w, "wdata", "wstrb", "wlast")
    io.soc.wvalid := io.arbiter.wvalid && hit_soc_w && !w_fire_after
    io.clint.wvalid := io.arbiter.wvalid && hit_clint_w && !w_fire_after
    io.addrerr.wvalid := io.arbiter.wvalid && hit_addrerr_w && !w_fire_after
    io.arbiter.wready := !w_fire_after && Mux(hit_clint_w, io.clint.wready, Mux(hit_soc_w, io.soc.wready, io.addrerr.wready))

    // B
    io.soc.bready := false.B
    io.clint.bready := false.B
    io.addrerr.bready := false.B
    when(write_owner === owner_clint) {
        connectFields(io.clint.b, io.arbiter.b, "bvalid", "bresp", "bid", "bready")
    }.elsewhen(write_owner === owner_soc) {
        connectFields(io.soc.b, io.arbiter.b, "bvalid", "bresp", "bid", "bready")
    }.otherwise {
        connectFields(io.addrerr.b, io.arbiter.b, "bvalid", "bresp", "bid", "bready")
    }
    io.b_need_skip_ref := write_owner === owner_soc && hit_soc_uart_w_preserved
}
