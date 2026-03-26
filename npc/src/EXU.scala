package cpu

import chisel3._
import chisel3.util._

class EXU extends Module {
    val io = IO(new Bundle {
        // val aluio = new Bundle {
        //     val alu_src1 = Input(UInt(32.W))
        //     val alu_src2 = Input(UInt(32.W))
        //     val alu_op = Input(ALUOp())
        //     val alu_result = Output(UInt(32.W))
        // }
        val src1 = Input(UInt(32.W))
        val src2 = Input(UInt(32.W))
        val alu_op = Input(ALUOp())
        val result = Output(UInt(32.W))

        val ebreak_in = Input(Bool())
        val ebreak_out = Output(Bool())
    })

    val alu = Module(new ALU)
    // io.aluio <> alu.io
    alu.io.alu_src1 := io.src1
    alu.io.alu_src2 := io.src2
    alu.io.alu_op := io.alu_op
    io.result := alu.io.alu_result

    io.ebreak_out := io.ebreak_in
}
