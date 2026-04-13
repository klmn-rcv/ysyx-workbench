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
            // 从译码级接收CSR信号
            val csr_addr = Input(UInt(12.W))
            val csr_re = Input(Bool())  // 不需要传给CSR模块
            val csr_we = Input(Bool())
            val csr_wmask = Input(UInt(32.W))
            val csr_wvalue = Input(UInt(32.W))
            // 从CSR模块接收CSR寄存器的读数据
            val csr_rvalue = Input(UInt(32.W))
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
            // 将CSR相关信号传给CSR模块
            val csr_addr = Output(UInt(12.W))
            val csr_we = Output(Bool())
            val csr_wmask = Output(UInt(32.W))
            val csr_wvalue = Output(UInt(32.W))
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

    // 将从ID级传来的CSR相关信号传给CSR模块
    io.out.csr_addr := io.in.csr_addr
    io.out.csr_we := io.in.csr_we
    io.out.csr_wmask := io.in.csr_wmask
    io.out.csr_wvalue := io.in.csr_wvalue

    when(io.in.csr_re) {
        io.out.result := io.in.csr_rvalue
    }
}
