package cpu.npc

import chisel3._
import chisel3.util._

class CLINT extends Module {
    val io = IO(new Bundle {
        val axi = Flipped(new AXI4Lite(32, 32))
        val r_need_skip_ref = Output(Bool())
    })

    val mtime_lo_addr = "h10000004".U(32.W)
    val mtime_hi_addr = "h10000008".U(32.W)

    val mtime = RegInit(0.U(64.W))
    val mtime_snapshot = RegInit(0.U(64.W))
    val rdata_reg = RegInit(0.U(32.W))
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

    mtime := mtime + 1.U

    when(ar_fire) {
        when(io.axi.ar.araddr === mtime_hi_addr) {
            mtime_snapshot := mtime
            rdata_reg := mtime(63, 32)
        }.otherwise {
            rdata_reg := mtime_snapshot(31, 0)
        }
    }

    io.axi.ar.arready := !rvalid
    io.axi.r.rvalid := rvalid
    io.axi.r.rdata := rdata_reg
    io.axi.r.rresp := AXI4Resp.OKAY
    io.r_need_skip_ref := io.axi.r.rvalid

    io.axi.aw.awready := !bvalid && !aw_fire_after
    io.axi.w.wready := !bvalid && !w_fire_after
    io.axi.b.bvalid := bvalid
    io.axi.b.bresp := AXI4Resp.SLVERR
}
