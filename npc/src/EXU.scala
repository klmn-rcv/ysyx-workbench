package cpu

import chisel3._
import chisel3.util._

class EXU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val src1 = Input(UInt(32.W))
            val src2 = Input(UInt(32.W))
            val alu_op = Input(ALUOp())
            val wr_reg = Input(Bool())
            val rd = Input(UInt(5.W))
            val rd_mem = Input(Bool())
            val wr_mem = Input(Bool())
            val bit_width = Input(BitWidth())
            val sign = Input(Sign())
            val ebreak = Input(Bool())
        }
        val out = new Bundle {
            val result = Output(UInt(32.W))
            val src2 = Output(UInt(32.W))  // for store data
            val wr_reg = Output(Bool())
            val rd = Output(UInt(5.W))
            val rd_mem = Output(Bool())
            val wr_mem = Output(Bool())
            val bit_width = Output(BitWidth())
            val sign = Output(Sign())
            val ebreak = Output(Bool())
        }
    })

    val alu = Module(new ALU)
    alu.io.in.src1 := io.in.src1
    alu.io.in.src2 := io.in.src2
    alu.io.in.op := io.in.alu_op
    
    io.out.result := alu.io.out.result
    io.out.src2 := io.in.src2

    io.out.wr_reg := io.in.wr_reg
    io.out.rd := io.in.rd

    io.out.rd_mem := io.in.rd_mem
    io.out.wr_mem := io.in.wr_mem

    io.out.bit_width := io.in.bit_width
    io.out.sign := io.in.sign

    io.out.ebreak := io.in.ebreak
}
