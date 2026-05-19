package cpu

import chisel3._
import chisel3.reflect.DataMirror

class ysyx_26050145 extends Module {
    val io = IO(new Bundle {
        val interrupt = Input(Bool())
        val master = new AXI4(32, 32, 4)
        val slave = Flipped(new AXI4(32, 32, 4))
    })

    val core = Module(new CPU)
    val arbiter = Module(new AXI4Arbiter)
    val xbar = Module(new Xbar)
    val clint = Module(new CLINT)
    val addrerr = Module(new AddressErrorHandler)

    core.io.inst_mem_axi <> arbiter.io.if_iw
    core.io.data_mem_axi <> arbiter.io.ls_lsw
    core.io.data_mem_r_need_skip_ref := arbiter.io.ls_lsw_r_need_skip_ref
    core.io.data_mem_b_need_skip_ref := arbiter.io.ls_lsw_b_need_skip_ref

    arbiter.io.xbar <> xbar.io.arbiter
    arbiter.io.ls_lsw_load := core.io.ls_lsw_load
    arbiter.io.xbar_r_need_skip_ref := xbar.io.r_need_skip_ref
    arbiter.io.xbar_b_need_skip_ref := xbar.io.b_need_skip_ref

    clint.io.axi <> xbar.io.clint
    xbar.io.clint_r_need_skip_ref := clint.io.r_need_skip_ref
    addrerr.io.axi <> xbar.io.addrerr

    xbar.io.soc <> io.master

    io.slave.elements.foreach { case (_, port) =>
        if (DataMirror.directionOf(port) == ActualDirection.Output) {
            port := 0.U.asTypeOf(chiselTypeOf(port))
        }
    }

    dontTouch(io.interrupt)
}
