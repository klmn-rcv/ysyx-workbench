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
    val mem = Module(new _root_.cpu.Mem)

    mem.clk := clock
    mem.rst := reset.asBool
    mem.inst_req_valid := core.io.out.inst_req_valid
    mem.data_req_valid := core.io.out.data_req_valid
    mem.inst_resp_ready := core.io.out.inst_resp_ready
    mem.data_resp_ready := core.io.out.data_resp_ready
    mem.wen := core.io.out.wen
    mem.pc := core.io.out.pc
    mem.raddr := core.io.out.raddr
    mem.waddr := core.io.out.waddr
    mem.wdata := core.io.out.wdata
    mem.wmask := core.io.out.wmask

    core.io.in.inst_req_ready := mem.inst_req_ready
    core.io.in.data_req_ready := mem.data_req_ready
    core.io.in.inst_resp_valid := mem.inst_resp_valid
    core.io.in.data_resp_valid := mem.data_resp_valid
    core.io.in.rinst := mem.rinst
    core.io.in.rdata := mem.rdata

    // io.pc := core.io.out.pc
    // io.raddr := core.io.out.raddr
    // io.waddr := core.io.out.waddr
    // io.wdata := core.io.out.wdata
    // io.wmask := core.io.out.wmask
    // io.data_req_valid := core.io.out.data_req_valid
    // io.wen := core.io.out.wen
    // io.rinst := mem.rinst
    // io.rdata := mem.rdata
}
