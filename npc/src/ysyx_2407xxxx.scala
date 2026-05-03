package cpu

import chisel3._
import chisel3.reflect.DataMirror

class ysyx_2407xxxx extends Module {
    val io = IO(new Bundle {
        val interrupt = Input(Bool())
        val master = new AXI4(32, 32, 4)
        val slave = Flipped(new AXI4(32, 32, 4))
    })

    val core = Module(new CPU)
    val arbiter = Module(new AXI4Arbiter)
    val xbar = Module(new Xbar)
    val clint = Module(new CLINT)

    core.io.inst_mem_axi <> arbiter.io.ifu
    core.io.data_mem_axi <> arbiter.io.lsu
    core.io.data_mem_r_need_skip_ref := arbiter.io.lsu_r_need_skip_ref
    core.io.data_mem_b_need_skip_ref := arbiter.io.lsu_b_need_skip_ref

    arbiter.io.out <> xbar.io.arbiter
    arbiter.io.out_r_need_skip_ref := xbar.io.r_need_skip_ref
    arbiter.io.out_b_need_skip_ref := xbar.io.b_need_skip_ref

    clint.io.axi <> xbar.io.clint.axi
    xbar.io.clint.r_need_skip_ref := clint.io.r_need_skip_ref

    xbar.io.soc <> io.master

    io.slave.elements.foreach { case (_, port) =>
    if (DataMirror.directionOf(port) == ActualDirection.Output) {
        port := 0.U.asTypeOf(chiselTypeOf(port))
    }
    }

    dontTouch(io.interrupt)
}
