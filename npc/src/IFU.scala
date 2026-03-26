package cpu

import chisel3._
import chisel3.util._

class IFU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val bj_valid = Input(Bool())
            val bj_pc = Input(UInt(32.W))
        }
        val out = new Bundle {
            val pc = Output(UInt(32.W))
            val next_pc = Output(UInt(32.W))
        }
    })

    val pc_reg = RegInit("hfffffffc".U(32.W))
    val snpc = pc_reg + 4.U
    val dnpc = io.in.bj_pc
    pc_reg := io.out.next_pc   // current pc
    io.out.pc := pc_reg
    io.out.next_pc := Mux(io.in.bj_valid, dnpc, snpc)  // next pc
}
