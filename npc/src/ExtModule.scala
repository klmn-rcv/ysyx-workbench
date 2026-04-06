package cpu

import chisel3._
import chisel3.util._

class Halt extends ExtModule {
    val exit_code = IO(Input(UInt(32.W)))
    val ebreak = IO(Input(Bool()))
    addResource("/Halt.sv")
}

class Mem extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val inst_req_valid = IO(Input(Bool()))
    val data_req_valid = IO(Input(Bool()))
    val wen = IO(Input(Bool()))
    val pc = IO(Input(UInt(32.W)))
    val raddr = IO(Input(UInt(32.W)))
    val rinst = IO(Output(UInt(32.W)))
    val rdata = IO(Output(UInt(32.W)))
    val waddr = IO(Input(UInt(32.W)))
    val wdata = IO(Input(UInt(32.W)))
    val wmask = IO(Input(UInt(4.W)))

    addResource("/Mem.sv")
}

class Itrace extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val valid = IO(Input(Bool()))
    val pc = IO(Input(UInt(32.W)))
    val inst = IO(Input(UInt(32.W)))

    addResource("/Itrace.sv")
}
