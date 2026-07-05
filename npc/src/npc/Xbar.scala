package cpu.npc

import chisel3._
import chisel3.util._
import cpu._

class Xbar extends Module {
    val io = IO(new Bundle {
        val in = Flipped(new AXI4(32, 32, 4))
        val mem = new AXI4(32, 32, 4)
        val uart = new AXI4(32, 32, 4)
        val clint = new AXI4(32, 32, 4)
        val uart_b_need_skip_ref = Input(Bool())
        val clint_r_need_skip_ref = Input(Bool())
        val r_need_skip_ref = Output(Bool())
        val b_need_skip_ref = Output(Bool())
    })

    val uart_base = "h10000000".U(32.W)
    val clint_mtime_lo = "h10000004".U(32.W)
    val clint_mtime_hi = "h10000008".U(32.W)

    val ar_fire = io.in.arvalid && io.in.arready
    val r_fire = io.in.rvalid && io.in.rready
    val aw_fire = io.in.awvalid && io.in.awready
    val b_fire = io.in.bvalid && io.in.bready

    val (_, ar_fire_after) = bool_preserve(ar_fire, r_fire, false.B)
    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, b_fire, false.B)
    val (_, w_fire_after) = bool_preserve(io.in.wvalid && io.in.wready, b_fire, false.B)

    val hit_uart_r = io.in.araddr === uart_base
    val hit_clint_r = io.in.araddr === clint_mtime_lo || io.in.araddr === clint_mtime_hi
    val hit_mem_r = !hit_uart_r && !hit_clint_r
    val hit_uart_w = io.in.awaddr === uart_base
    val hit_clint_w = io.in.awaddr === clint_mtime_lo || io.in.awaddr === clint_mtime_hi
    val hit_mem_w = !hit_uart_w && !hit_clint_w

    val owner_mem :: owner_uart :: owner_clint :: Nil = Enum(3)
    val read_owner = RegInit(owner_mem)
    val write_owner = RegInit(owner_mem)

    when(ar_fire) {
        read_owner := Mux(hit_uart_r, owner_uart, Mux(hit_clint_r, owner_clint, owner_mem))
    }
    when(aw_fire) {
        write_owner := Mux(hit_uart_w, owner_uart, Mux(hit_clint_w, owner_clint, owner_mem))
    }

    // AR
    connectFields(io.in.ar, io.mem.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    connectFields(io.in.ar, io.uart.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    connectFields(io.in.ar, io.clint.ar, "araddr", "arid", "arlen", "arsize", "arburst")
    io.mem.arvalid := io.in.arvalid && hit_mem_r && !ar_fire_after
    io.uart.arvalid := io.in.arvalid && hit_uart_r && !ar_fire_after
    io.clint.arvalid := io.in.arvalid && hit_clint_r && !ar_fire_after
    io.in.arready := !ar_fire_after && Mux(hit_uart_r, io.uart.arready,
                     Mux(hit_clint_r, io.clint.arready, io.mem.arready))

    // R
    io.mem.rready := false.B
    io.uart.rready := false.B
    io.clint.rready := false.B
    when(read_owner === owner_uart) {
        connectFields(io.uart.r, io.in.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
    }.elsewhen(read_owner === owner_clint) {
        connectFields(io.clint.r, io.in.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
    }.otherwise {
        connectFields(io.mem.r, io.in.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
    }
    io.r_need_skip_ref := read_owner === owner_clint && io.clint_r_need_skip_ref

    // AW
    connectFields(io.in.aw, io.mem.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    connectFields(io.in.aw, io.uart.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    connectFields(io.in.aw, io.clint.aw, "awaddr", "awid", "awlen", "awsize", "awburst")
    io.mem.awvalid := io.in.awvalid && hit_mem_w && !aw_fire_after
    io.uart.awvalid := io.in.awvalid && hit_uart_w && !aw_fire_after
    io.clint.awvalid := io.in.awvalid && hit_clint_w && !aw_fire_after
    io.in.awready := !aw_fire_after && Mux(hit_uart_w, io.uart.awready,
                     Mux(hit_clint_w, io.clint.awready, io.mem.awready))

    // W
    connectFields(io.in.w, io.mem.w, "wdata", "wstrb", "wlast")
    connectFields(io.in.w, io.uart.w, "wdata", "wstrb", "wlast")
    connectFields(io.in.w, io.clint.w, "wdata", "wstrb", "wlast")
    io.mem.wvalid := io.in.wvalid && hit_mem_w && !w_fire_after
    io.uart.wvalid := io.in.wvalid && hit_uart_w && !w_fire_after
    io.clint.wvalid := io.in.wvalid && hit_clint_w && !w_fire_after
    io.in.wready := !w_fire_after && Mux(hit_uart_w, io.uart.wready,
                    Mux(hit_clint_w, io.clint.wready, io.mem.wready))

    // B
    io.mem.bready := false.B
    io.uart.bready := false.B
    io.clint.bready := false.B
    when(write_owner === owner_uart) {
        connectFields(io.uart.b, io.in.b, "bvalid", "bresp", "bid", "bready")
    }.elsewhen(write_owner === owner_clint) {
        connectFields(io.clint.b, io.in.b, "bvalid", "bresp", "bid", "bready")
    }.otherwise {
        connectFields(io.mem.b, io.in.b, "bvalid", "bresp", "bid", "bready")
    }
    io.b_need_skip_ref := write_owner === owner_uart && io.uart_b_need_skip_ref
}
