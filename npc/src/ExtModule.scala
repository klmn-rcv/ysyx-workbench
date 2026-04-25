package cpu

import chisel3._
import chisel3.util._

class Halt extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val exit_code = IO(Input(UInt(32.W)))
    val exit_pc = IO(Input(UInt(32.W)))
    val halt_valid = IO(Input(Bool()))

    addResource("/Halt.sv")
}

class Mem extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val is_inst = IO(Input(Bool()))
    val axi = IO(Flipped(new AXI4Lite(32, 32)))

    addResource("/Mem.sv")
    addResource("/LFSR.sv")
}

class Itrace extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val valid = IO(Input(Bool()))
    val pc = IO(Input(UInt(32.W)))
    val inst = IO(Input(UInt(32.W)))
    val dnpc = IO(Input(UInt(32.W)))

    addResource("/Itrace.sv")
}

class Iringbuf extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val pc = IO(Input(UInt(32.W)))
    val inst = IO(Input(UInt(32.W)))
    val before_ifetch = IO(Input(Bool()))
    val after_ifetch = IO(Input(Bool()))
    val flush_after_ifetch = IO(Input(Bool()))

    addResource("/Iringbuf.sv")
}

class Ftrace extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val pc = IO(Input(UInt(32.W)))
    val target_pc = IO(Input(UInt(32.W)))
    val rd = IO(Input(UInt(5.W)))
    val rs1 = IO(Input(UInt(5.W)))
    val imm = IO(Input(UInt(32.W)))
    val is_jal = IO(Input(Bool()))
    val is_jalr = IO(Input(Bool()))

    addResource("/Ftrace.sv")
}
