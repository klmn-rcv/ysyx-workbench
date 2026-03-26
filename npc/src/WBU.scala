package cpu

import chisel3._
import chisel3.util._

class WBU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val data = Input(UInt(32.W))
            val wr_reg = Input(Bool())
            val rd = Input(UInt(5.W))
            val ebreak = Input(Bool())
        }
        val out = new Bundle {
            val wb_data = Output(UInt(32.W))
            val wb_we = Output(Bool())
            val wb_addr = Output(UInt(5.W))
        }
    })

    // jump writes link value (pc+4); arithmetic writes ALU result.
    io.out.wb_data := io.in.data
    io.out.wb_we := io.in.wr_reg
    io.out.wb_addr := io.in.rd

    val halt = Module(new Halt)
    halt.ebreak := io.in.ebreak
}
