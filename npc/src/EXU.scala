package cpu

import chisel3._
import chisel3.util._

class EXU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val src1 = Input(UInt(32.W))
            val src2 = Input(UInt(32.W)) // 这是ALU的第二个操作数，可能来自寄存器，也可能是立即数
            val reg_data2 = Input(UInt(32.W)) // 这是寄存器的第二个数据，仅用于store指令
            val alu_op = Input(ALUOp())
            val wr_reg = Input(Bool())
            val rd = Input(UInt(5.W))
            val rd_mem = Input(Bool())
            val wr_mem = Input(Bool())
            val bit_width = Input(BitWidth())
            val sign = Input(Sign())
            val br_valid = Input(Bool())
            val br_expect_0 = Input(Bool())
            val br_target = Input(UInt(32.W))
            val ebreak = Input(Bool())
            val inv = Input(Bool())
            val inst = Input(UInt(32.W))
            val pc = Input(UInt(32.W))
            val dnpc = Input(UInt(32.W))
            val csrReq = Input(new CSRReq)
            
            val ecall = Input(Bool())
            val mret = Input(Bool())
        }
        val out = new Bundle {
            val result = Output(UInt(32.W))
            val br_taken = Output(Bool())
            val br_target = Output(UInt(32.W))
            val reg_data2 = Output(UInt(32.W))  // for store data
            val wr_reg = Output(Bool())
            val rd = Output(UInt(5.W))
            val rd_mem = Output(Bool())
            val wr_mem = Output(Bool())
            val bit_width = Output(BitWidth())
            val sign = Output(Sign())
            val ebreak = Output(Bool())
            val inv = Output(Bool())
            val inst = Output(UInt(32.W))
            val pc = Output(UInt(32.W))
            val dnpc = Output(UInt(32.W))
            val csrReq = Output(new CSRReq)
            
            val ecall = Output(Bool())
            val mret = Output(Bool())
        }
    })

    val alu = Module(new ALU)
    alu.io.in.src1 := io.in.src1
    alu.io.in.src2 := io.in.src2
    alu.io.in.op := io.in.alu_op

    val br_alu_zero = alu.io.out.result === 0.U
    io.out.br_taken := io.in.br_valid && (br_alu_zero === io.in.br_expect_0)
    io.out.br_target := io.in.br_target

    io.out.result := alu.io.out.result
    io.out.reg_data2 := io.in.reg_data2

    io.out.wr_reg := io.in.wr_reg
    io.out.rd := io.in.rd

    io.out.rd_mem := io.in.rd_mem
    io.out.wr_mem := io.in.wr_mem

    io.out.bit_width := io.in.bit_width
    io.out.sign := io.in.sign

    io.out.ebreak := io.in.ebreak
    io.out.inv := io.in.inv

    io.out.inst := io.in.inst
    io.out.pc := io.in.pc
    io.out.dnpc := io.in.dnpc
    io.out.csrReq := io.in.csrReq

    io.out.ecall := io.in.ecall
    io.out.mret := io.in.mret
}
