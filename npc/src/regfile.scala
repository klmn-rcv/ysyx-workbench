package cpu

import chisel3._
import chisel3.util._

class regfile extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val raddr1 = Input(UInt(4.W))
            val raddr2 = Input(UInt(4.W))
            val we = Input(Bool())
            val waddr = Input(UInt(4.W))
            val wdata = Input(UInt(32.W))
        }
        val out = new Bundle {
            val rdata1 = Output(UInt(32.W))
            val rdata2 = Output(UInt(32.W))
        }
    })
    val regfile = RegInit(VecInit.fill(16)(0.U(32.W)))
    io.out.rdata1 := regfile(io.in.raddr1)
    io.out.rdata2 := regfile(io.in.raddr2)
    when(io.in.we && io.in.waddr =/= 0.U) { // x0寄存器始终为0
        regfile(io.in.waddr) := io.in.wdata
    }
}
