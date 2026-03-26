package cpu

import chisel3._
import chisel3.util._

class regfile extends Module {
    val io = IO(new Bundle {
        val raddr1 = Input(UInt(4.W))
        val rdata1 = Output(UInt(32.W))
        // read port (2)
        val raddr2 = Input(UInt(4.W))
        val rdata2 = Output(UInt(32.W))
        // write port
        val we = Input(Bool())
        val waddr = Input(UInt(4.W))
        val wdata = Input(UInt(32.W))
    })
    val regfile = RegInit(VecInit.fill(16)(0.U(32.W)))
    io.rdata1 := regfile(io.raddr1)
    io.rdata2 := regfile(io.raddr2)
    when(io.we && io.waddr =/= 0.U) { // x0寄存器始终为0
        regfile(io.waddr) := io.wdata
    }
}
