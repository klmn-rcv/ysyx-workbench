package cpu

import chisel3._

class Top extends Module {
    val core = Module(new CPU(resetVector = 0x80000000L))
    val arbiter = Module(new AXI4Arbiter)
    val xbar = Module(new npc.Xbar)
    val mem = Module(new npc.Mem)
    val uart = Module(new npc.UART)
    val clint = Module(new npc.CLINT)

    core.io.inst_mem_axi <> arbiter.io.if_iw
    core.io.data_mem_axi <> arbiter.io.ls_lsw
    core.io.data_mem_r_need_skip_ref := arbiter.io.ls_lsw_r_need_skip_ref
    core.io.data_mem_b_need_skip_ref := arbiter.io.ls_lsw_b_need_skip_ref

    arbiter.io.xbar <> xbar.io.in
    arbiter.io.ls_lsw_load := core.io.ls_lsw_load
    arbiter.io.xbar_r_need_skip_ref := xbar.io.r_need_skip_ref
    arbiter.io.xbar_b_need_skip_ref := xbar.io.b_need_skip_ref

    xbar.io.mem <> mem.axi
    xbar.io.uart <> uart.io.axi
    xbar.io.clint <> clint.io.axi
    xbar.io.uart_b_need_skip_ref := uart.io.b_need_skip_ref
    xbar.io.clint_r_need_skip_ref := clint.io.r_need_skip_ref

    mem.clk := clock
    mem.rst := reset.asBool
}
