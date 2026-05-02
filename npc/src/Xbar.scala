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
        }
        val uart = new Bundle {
            val axi = new AXI4Lite(32, 32)
            val b_need_skip_ref = Input(Bool())
        }
        val clint = new Bundle {
            val axi = new AXI4Lite(32, 32)
            val r_need_skip_ref = Input(Bool())
        }
        val r_need_skip_ref = Output(Bool())
        val b_need_skip_ref = Output(Bool())
    })

    val uart_base = "h10000000".U(32.W)
    val clint_mtime_lo = "h10000004".U(32.W)
    val clint_mtime_hi = "h10000008".U(32.W)

    val ar_fire = io.in.ar.arvalid && io.in.ar.arready
    val r_fire = io.in.r.rvalid && io.in.r.rready
    val aw_fire = io.in.aw.awvalid && io.in.aw.awready
    val w_fire = io.in.w.wvalid && io.in.w.wready
    val b_fire = io.in.b.bvalid && io.in.b.bready

    val (_, ar_fire_after) = bool_preserve(ar_fire, r_fire, false.B)
    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, b_fire, false.B)
    val (w_fire_preserved, w_fire_after) = bool_preserve(w_fire, b_fire, false.B)
    val write_req_complete = aw_fire_preserved && w_fire_preserved

    // val read_busy = boolreg_set_clear(ar_fire, r_fire)
    // val write_busy = boolreg_set_clear(aw_fire || w_fire, b_fire)

    val hit_uart_r = io.in.ar.araddr === uart_base
    val hit_clint_r = io.in.ar.araddr === clint_mtime_lo || io.in.ar.araddr === clint_mtime_hi
    val hit_uart_w = io.in.aw.awaddr === uart_base
    val hit_clint_w = io.in.aw.awaddr === clint_mtime_lo || io.in.aw.awaddr === clint_mtime_hi
    val hit_mem_r = !hit_uart_r && !hit_clint_r
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

    io.mem.read_is_inst := io.read_is_inst

    // AR
    io.mem.axi.ar.arvalid := io.in.ar.arvalid && hit_mem_r && !ar_fire_after
    io.mem.axi.ar.araddr := io.in.ar.araddr
    io.uart.axi.ar.arvalid := io.in.ar.arvalid && hit_uart_r && !ar_fire_after
    io.uart.axi.ar.araddr := io.in.ar.araddr
    io.clint.axi.ar.arvalid := io.in.ar.arvalid && hit_clint_r && !ar_fire_after
    io.clint.axi.ar.araddr := io.in.ar.araddr
    io.in.ar.arready := !ar_fire_after && Mux(hit_uart_r, io.uart.axi.ar.arready,
                        Mux(hit_clint_r, io.clint.axi.ar.arready, io.mem.axi.ar.arready))

    // R
    io.in.r.rvalid := MuxLookup(read_owner, io.mem.axi.r.rvalid)(Seq(
        owner_uart -> io.uart.axi.r.rvalid,
        owner_clint -> io.clint.axi.r.rvalid
    ))
    io.in.r.rdata := MuxLookup(read_owner, io.mem.axi.r.rdata)(Seq(
        owner_uart -> io.uart.axi.r.rdata,
        owner_clint -> io.clint.axi.r.rdata
    ))
    io.in.r.rresp := MuxLookup(read_owner, io.mem.axi.r.rresp)(Seq(
        owner_uart -> io.uart.axi.r.rresp,
        owner_clint -> io.clint.axi.r.rresp
    ))
    io.mem.axi.r.rready := read_owner === owner_mem && io.in.r.rready
    io.uart.axi.r.rready := read_owner === owner_uart && io.in.r.rready
    io.clint.axi.r.rready := read_owner === owner_clint && io.in.r.rready
    io.r_need_skip_ref := Mux(read_owner === owner_clint, io.clint.r_need_skip_ref, false.B)

    // AW
    io.mem.axi.aw.awvalid := io.in.aw.awvalid && hit_mem_w && !aw_fire_after
    io.mem.axi.aw.awaddr := io.in.aw.awaddr
    io.uart.axi.aw.awvalid := io.in.aw.awvalid && hit_uart_w && !aw_fire_after
    io.uart.axi.aw.awaddr := io.in.aw.awaddr
    io.clint.axi.aw.awvalid := io.in.aw.awvalid && hit_clint_w && !aw_fire_after
    io.clint.axi.aw.awaddr := io.in.aw.awaddr
    io.in.aw.awready := !aw_fire_after && Mux(hit_uart_w, io.uart.axi.aw.awready,
                        Mux(hit_clint_w, io.clint.axi.aw.awready, io.mem.axi.aw.awready))

    // W
    io.mem.axi.w.wvalid := io.in.w.wvalid && hit_mem_w && !w_fire_after
    io.mem.axi.w.wdata := io.in.w.wdata
    io.mem.axi.w.wstrb := io.in.w.wstrb
    io.uart.axi.w.wvalid := io.in.w.wvalid && hit_uart_w && !w_fire_after
    io.uart.axi.w.wdata := io.in.w.wdata
    io.uart.axi.w.wstrb := io.in.w.wstrb
    io.clint.axi.w.wvalid := io.in.w.wvalid && hit_clint_w && !w_fire_after
    io.clint.axi.w.wdata := io.in.w.wdata
    io.clint.axi.w.wstrb := io.in.w.wstrb
    io.in.w.wready := !w_fire_after && Mux(hit_uart_w, io.uart.axi.w.wready,
                      Mux(hit_clint_w, io.clint.axi.w.wready, io.mem.axi.w.wready))

    // B
    io.in.b.bvalid := MuxLookup(write_owner, io.mem.axi.b.bvalid)(Seq(
        owner_uart -> io.uart.axi.b.bvalid,
        owner_clint -> io.clint.axi.b.bvalid
    ))
    io.in.b.bresp := MuxLookup(write_owner, io.mem.axi.b.bresp)(Seq(
        owner_uart -> io.uart.axi.b.bresp,
        owner_clint -> io.clint.axi.b.bresp
    ))
    io.mem.axi.b.bready := write_owner === owner_mem && io.in.b.bready
    io.uart.axi.b.bready := write_owner === owner_uart && io.in.b.bready
    io.clint.axi.b.bready := write_owner === owner_clint && io.in.b.bready
    io.b_need_skip_ref := Mux(write_owner === owner_uart, io.uart.b_need_skip_ref, false.B)
}
