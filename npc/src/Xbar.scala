package cpu

import chisel3._
import chisel3.util._

class Xbar extends Module {
    val io = IO(new Bundle {
        val in = Flipped(new AXI4Lite(32, 32))
        val read_is_inst = Input(Bool())
        val mem = new Bundle {
            val axi = new AXI4Lite(32, 32)
            val read_is_inst = Output(Bool())
            val r_need_skip_ref = Input(Bool())
        }
        val uart = new Bundle {
            val axi = new AXI4Lite(32, 32)
            val b_need_skip_ref = Input(Bool())
        }
        val r_need_skip_ref = Output(Bool())
        val b_need_skip_ref = Output(Bool())
    })

    val uart_base = "h10000000".U(32.W)
    val hit_uart_r = io.in.ar.araddr === uart_base
    val hit_uart_w = io.in.aw.awaddr === uart_base
    val read_owner_is_uart = RegEnable(hit_uart_r, false.B, io.in.ar.arvalid && io.in.ar.arready)
    val write_owner_is_uart = RegEnable(hit_uart_w, false.B, io.in.aw.awvalid && io.in.aw.awready)

    io.mem.read_is_inst := io.read_is_inst

    // AR
    io.mem.axi.ar.arvalid := io.in.ar.arvalid && !hit_uart_r
    io.mem.axi.ar.araddr := io.in.ar.araddr
    io.uart.axi.ar.arvalid := io.in.ar.arvalid && hit_uart_r
    io.uart.axi.ar.araddr := io.in.ar.araddr
    io.in.ar.arready := Mux(hit_uart_r, io.uart.axi.ar.arready, io.mem.axi.ar.arready)

    // R
    io.in.r.rvalid := Mux(read_owner_is_uart, io.uart.axi.r.rvalid, io.mem.axi.r.rvalid)
    io.in.r.rdata := Mux(read_owner_is_uart, io.uart.axi.r.rdata, io.mem.axi.r.rdata)
    io.in.r.rresp := Mux(read_owner_is_uart, io.uart.axi.r.rresp, io.mem.axi.r.rresp)
    io.mem.axi.r.rready := !read_owner_is_uart && io.in.r.rready
    io.uart.axi.r.rready := read_owner_is_uart && io.in.r.rready
    io.r_need_skip_ref := !read_owner_is_uart && io.mem.r_need_skip_ref

    // AW
    io.mem.axi.aw.awvalid := io.in.aw.awvalid && !hit_uart_w
    io.mem.axi.aw.awaddr := io.in.aw.awaddr
    io.uart.axi.aw.awvalid := io.in.aw.awvalid && hit_uart_w
    io.uart.axi.aw.awaddr := io.in.aw.awaddr
    io.in.aw.awready := Mux(hit_uart_w, io.uart.axi.aw.awready, io.mem.axi.aw.awready)

    // W
    io.mem.axi.w.wvalid := io.in.w.wvalid && !hit_uart_w
    io.mem.axi.w.wdata := io.in.w.wdata
    io.mem.axi.w.wstrb := io.in.w.wstrb
    io.uart.axi.w.wvalid := io.in.w.wvalid && hit_uart_w
    io.uart.axi.w.wdata := io.in.w.wdata
    io.uart.axi.w.wstrb := io.in.w.wstrb
    io.in.w.wready := Mux(hit_uart_w, io.uart.axi.w.wready, io.mem.axi.w.wready)

    // B
    io.in.b.bvalid := Mux(write_owner_is_uart, io.uart.axi.b.bvalid, io.mem.axi.b.bvalid)
    io.in.b.bresp := Mux(write_owner_is_uart, io.uart.axi.b.bresp, io.mem.axi.b.bresp)
    io.mem.axi.b.bready := !write_owner_is_uart && io.in.b.bready
    io.uart.axi.b.bready := write_owner_is_uart && io.in.b.bready
    io.b_need_skip_ref := write_owner_is_uart && io.uart.b_need_skip_ref
}
