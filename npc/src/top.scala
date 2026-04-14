package cpu

import chisel3._
import chisel3.util._

class Top extends Module {
    val core = Module(new CPU)
    val mem = Module(new _root_.cpu.Mem)

    mem.clk := clock
    mem.rst := reset.asBool
    mem.inst_req_valid := core.io.out.inst_req_valid
    mem.data_req_valid := core.io.out.data_req_valid
    mem.wen := core.io.out.wen
    mem.pc := core.io.out.pc
    mem.raddr := core.io.out.raddr
    mem.waddr := core.io.out.waddr
    mem.wdata := core.io.out.wdata
    mem.wmask := core.io.out.wmask

    core.io.in.rinst := mem.rinst
    core.io.in.rdata := mem.rdata
}
