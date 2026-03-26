package cpu

import chisel3._
import chisel3.util._

class Top extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
        }
        val out = new Bundle {
            val pc = Output(UInt(32.W))
        }
    })

    val core = Module(new CPU)
    val mem = Module(new _root_.cpu.Mem)

    mem.clk := clock
    mem.rst := reset.asBool
    mem.inst_req_valid := core.io.out.mem_inst_req_valid
    mem.data_req_valid := core.io.out.mem_data_req_valid
    mem.wen := core.io.out.mem_wen
    mem.pc := core.io.out.mem_inst_pc
    mem.raddr := core.io.out.mem_raddr
    mem.waddr := core.io.out.mem_waddr
    mem.wdata := core.io.out.mem_wdata
    mem.wmask := core.io.out.mem_wmask

    core.io.in.mem_rinst := mem.rinst
    core.io.in.mem_rdata := mem.rdata
    io.out.pc := core.io.out.pc
}
