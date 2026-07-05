package cpu.npc

import chisel3._
import chisel3.util._

class UART extends Module {
    val io = IO(new Bundle {
        val axi = Flipped(new AXI4Lite(32, 32))
        val b_need_skip_ref = Output(Bool())
    })

    val write_req_complete = Wire(Bool())

    val ar_fire = io.axi.ar.arvalid && io.axi.ar.arready
    val r_fire = io.axi.r.rvalid && io.axi.r.rready
    val aw_fire = io.axi.aw.awvalid && io.axi.aw.awready
    val w_fire = io.axi.w.wvalid && io.axi.w.wready
    val b_fire = io.axi.b.bvalid && io.axi.b.bready

    val rvalid = boolreg_set_clear(ar_fire, r_fire)
    val bvalid = boolreg_set_clear(write_req_complete, b_fire)

    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, b_fire, false.B)
    val (w_fire_preserved, w_fire_after) = bool_preserve(w_fire, b_fire, false.B)
    write_req_complete := aw_fire_preserved && w_fire_preserved && !bvalid
    val (wdata_preserved, _) = data_preserve(io.axi.w.wdata, w_fire, b_fire, false.B)
    val (wstrb_preserved, _) = data_preserve(io.axi.w.wstrb, w_fire, b_fire, false.B)

    io.axi.ar.arready := !rvalid
    io.axi.r.rvalid := rvalid
    io.axi.r.rdata := 0.U
    io.axi.r.rresp := AXI4Resp.SLVERR

    io.axi.aw.awready := !bvalid && !aw_fire_after
    io.axi.w.wready := !bvalid && !w_fire_after
    io.axi.b.bvalid := bvalid
    io.axi.b.bresp := AXI4Resp.OKAY
    io.b_need_skip_ref := bvalid

    when(write_req_complete && wstrb_preserved(0)) {
        printf("%c", wdata_preserved(7, 0))
    }
}
