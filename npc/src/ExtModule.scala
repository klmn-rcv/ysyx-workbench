package cpu

import chisel3._
import chisel3.util._

class Halt extends ExtModule {
    val exit_code = IO(Input(UInt(32.W)))
    val exit_pc = IO(Input(UInt(32.W)))
    val halt_valid = IO(Input(Bool()))

    addResource("/Halt.sv")
}

class Mem extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val inst_req_valid = IO(Input(Bool()))
    val data_req_valid = IO(Input(Bool()))
    val inst_resp_ready = IO(Input(Bool()))
    val data_resp_ready = IO(Input(Bool()))
    val wen = IO(Input(Bool()))
    val pc = IO(Input(UInt(32.W)))
    val raddr = IO(Input(UInt(32.W)))
    val waddr = IO(Input(UInt(32.W)))
    val wdata = IO(Input(UInt(32.W)))
    val wmask = IO(Input(UInt(4.W)))
    val inst_req_ready = IO(Output(Bool()))
    val data_req_ready = IO(Output(Bool()))
    val inst_resp_valid = IO(Output(Bool()))
    val data_resp_valid = IO(Output(Bool()))
    val rinst = IO(Output(UInt(32.W)))
    val rdata = IO(Output(UInt(32.W)))

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
