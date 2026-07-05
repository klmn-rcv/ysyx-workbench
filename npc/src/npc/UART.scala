package cpu.npc

import chisel3._
import cpu._

class UART extends Module {
    val io = IO(new Bundle {
        val axi = Flipped(new AXI4(32, 32, 4))
        val b_need_skip_ref = Output(Bool())
    })

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
    val (wdata_preserved, _) = data_preserve(io.axi.wdata, w_fire, b_fire, false.B)
    val (wstrb_preserved, _) = data_preserve(io.axi.wstrb, w_fire, b_fire, false.B)
    val rid = RegInit(0.U(4.W))
    val bid = RegInit(0.U(4.W))

    when(ar_fire) {
        rid := io.axi.arid
        assert(io.axi.arlen === 0.U)
    }
    when(aw_fire) {
        bid := io.axi.awid
        assert(io.axi.awlen === 0.U)
    }
    when(w_fire) {
        assert(io.axi.wlast)
    }
    when(write_req_complete && wstrb_preserved(0)) {
        printf("%c", wdata_preserved(7, 0))
    }

    io.axi.arready := !rvalid
    io.axi.rvalid := rvalid
    io.axi.rdata := 0.U
    io.axi.rresp := AXI4Resp.SLVERR
    io.axi.rid := rid
    io.axi.rlast := true.B

    io.axi.awready := !bvalid && !aw_fire_after
    io.axi.wready := !bvalid && !w_fire_after
    io.axi.bvalid := bvalid
    io.axi.bresp := AXI4Resp.OKAY
    io.axi.bid := bid
    io.b_need_skip_ref := bvalid
}
