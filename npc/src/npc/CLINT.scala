package cpu.npc

import chisel3._
import cpu._

class CLINT extends Module {
    val io = IO(new Bundle {
        val axi = Flipped(new AXI4(32, 32, 4))
        val r_need_skip_ref = Output(Bool())
    })

    val mtime_lo_addr = "h10000004".U(32.W)
    val mtime_hi_addr = "h10000008".U(32.W)

    val mtime = RegInit(0.U(64.W))
    val mtime_snapshot = RegInit(0.U(64.W))
    val rdata = RegInit(0.U(32.W))
    val rid = RegInit(0.U(4.W))
    val bid = RegInit(0.U(4.W))

    val ar_fire = io.axi.arvalid && io.axi.arready
    val r_fire = io.axi.rvalid && io.axi.rready
    val aw_fire = io.axi.awvalid && io.axi.awready
    val w_fire = io.axi.wvalid && io.axi.wready
    val b_fire = io.axi.bvalid && io.axi.bready

    val write_req_complete = Wire(Bool())
    val rvalid = boolreg_set_clear(ar_fire, r_fire)
    val bvalid = boolreg_set_clear(write_req_complete, b_fire)
    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, b_fire, false.B)
    val (w_fire_preserved, w_fire_after) = bool_preserve(w_fire, b_fire, false.B)
    write_req_complete := aw_fire_preserved && w_fire_preserved && !bvalid

    mtime := mtime + 1.U

    when(ar_fire) {
        rid := io.axi.arid
        assert(io.axi.arlen === 0.U)
        assert(io.axi.arsize === AXI4Size.b4)
        when(io.axi.araddr === mtime_hi_addr) {
            mtime_snapshot := mtime
            rdata := mtime(63, 32)
        }.otherwise {
            rdata := mtime_snapshot(31, 0)
        }
    }
    when(aw_fire) {
        bid := io.axi.awid
        assert(io.axi.awlen === 0.U)
    }
    when(w_fire) {
        assert(io.axi.wlast)
    }
    io.axi.arready := !rvalid
    io.axi.rvalid := rvalid
    io.axi.rdata := rdata
    io.axi.rresp := AXI4Resp.OKAY
    io.axi.rid := rid
    io.axi.rlast := true.B
    io.r_need_skip_ref := rvalid

    io.axi.awready := !bvalid && !aw_fire_after
    io.axi.wready := !bvalid && !w_fire_after
    io.axi.bvalid := bvalid
    io.axi.bresp := AXI4Resp.SLVERR
    io.axi.bid := bid
}
