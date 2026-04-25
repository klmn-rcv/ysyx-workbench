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
    val inst_mem = Module(new _root_.cpu.Mem)
    val data_mem = Module(new _root_.cpu.Mem)

    inst_mem.clk := clock
    inst_mem.rst := reset.asBool
    inst_mem.is_inst := true.B
    inst_mem.axi <> core.io.inst_mem_axi

    data_mem.clk := clock
    data_mem.rst := reset.asBool
    data_mem.is_inst := false.B
    data_mem.axi <> core.io.data_mem_axi
}
