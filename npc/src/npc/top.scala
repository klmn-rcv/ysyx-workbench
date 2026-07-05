package cpu.npc

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
    val arbiter = Module(new AXI4LiteArbiter)
    val xbar = Module(new Xbar)
    val mem = Module(new Mem)
    val uart = Module(new UART)
    val clint = Module(new CLINT)

    // core <-> arbiter
    core.io.inst_mem_axi <> arbiter.io.ifu
    core.io.data_mem_axi <> arbiter.io.lsu
    core.io.data_mem_r_need_skip_ref := arbiter.io.lsu_r_need_skip_ref
    core.io.data_mem_b_need_skip_ref := arbiter.io.lsu_b_need_skip_ref

    // arbiter <-> xbar
    arbiter.io.out <> xbar.io.in
    arbiter.io.out_r_need_skip_ref := xbar.io.r_need_skip_ref
    arbiter.io.out_b_need_skip_ref := xbar.io.b_need_skip_ref
    xbar.io.read_is_inst := arbiter.io.read_is_inst

    // xbar <-> mem/uart/clint
    xbar.io.uart.b_need_skip_ref := uart.io.b_need_skip_ref
    xbar.io.clint.r_need_skip_ref := clint.io.r_need_skip_ref
    mem.clk := clock
    mem.rst := reset.asBool
    mem.axi <> xbar.io.mem.axi
    mem.read_is_inst := xbar.io.mem.read_is_inst
    uart.io.axi <> xbar.io.uart.axi
    clint.io.axi <> xbar.io.clint.axi
}
