package cpu

import chisel3._
import chisel3.util._

class Top extends Module {
    // val io = IO(new Bundle {
    //     val pc = Output(UInt(32.W))
    //     val raddr = Output(UInt(32.W))
    //     val waddr = Output(UInt(32.W))
    //     val wdata = Output(UInt(32.W))
    //     val wmask = Output(UInt(4.W))
    //     val data_req_valid = Output(Bool())
    //     val wen = Output(Bool())
    //     val rinst = Output(UInt(32.W))
    //     val rdata = Output(UInt(32.W))
    // })

    val core = Module(new CPU)
    val arbiter = Module(new Arbiter)
    val mem = Module(new _root_.cpu.Mem)

    arbiter.io.ifu <> core.io.inst_mem_axi
    arbiter.io.lsu <> core.io.data_mem_axi

    mem.clk := clock
    mem.rst := reset.asBool
    mem.read_is_inst := arbiter.io.read_is_inst
    mem.axi <> arbiter.io.out

    core.io.data_mem_r_need_skip_ref := mem.r_need_skip_ref
    core.io.data_mem_b_need_skip_ref := mem.b_need_skip_ref
}
