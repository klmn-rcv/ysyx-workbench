package cpu

import chisel3._
import chisel3.util._

class AddressErrorHandler extends Module with HasYsyxModuleName {
    override protected def moduleSuffix: String = "AddressErrorHandler"
    val io = IO(new Bundle {
        val axi = Flipped(new AXI4(32, 32, 4))
    })

    val write_req_complete = Wire(Bool())
    val rid_reg = RegInit(0.U(4.W))
    val bid_reg = RegInit(0.U(4.W))

    val ar_fire = io.axi.arvalid && io.axi.arready
    val r_fire = io.axi.rvalid && io.axi.rready
    val aw_fire = io.axi.awvalid && io.axi.awready
    val w_fire = io.axi.wvalid && io.axi.wready
    val b_fire = io.axi.bvalid && io.axi.bready

    val rvalid = boolreg_set_clear(ar_fire, r_fire)
    val bvalid = boolreg_set_clear(write_req_complete, b_fire)

    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, b_fire, false.B)
    val (w_fire_preserved, w_fire_after) = bool_preserve(w_fire, b_fire, false.B)
    write_req_complete := aw_fire_preserved && w_fire_preserved && !bvalid

    when(ar_fire) {
        rid_reg := io.axi.arid
    }
    when(aw_fire) {
        bid_reg := io.axi.awid
    }

    io.axi.arready := !rvalid
    io.axi.rvalid := rvalid
    io.axi.rdata := 0.U
    io.axi.rresp := AXI4Resp.DECERR
    io.axi.rid := rid_reg
    io.axi.rlast := true.B

    io.axi.awready := !bvalid && !aw_fire_after
    io.axi.wready := !bvalid && !w_fire_after
    io.axi.bvalid := bvalid
    io.axi.bresp := AXI4Resp.DECERR
    io.axi.bid := bid_reg
}
