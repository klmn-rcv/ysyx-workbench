package cpu

import chisel3._
import chisel3.util._

class IDU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val valid = Input(Bool())
            val inst = Input(UInt(32.W))
            val rdata1 = Input(UInt(32.W))
            val rdata2 = Input(UInt(32.W))
            val pc = Input(UInt(32.W))
        }
        val out = new Bundle {
            val alu_op = Output(ALUOp())
            val imm = Output(UInt(32.W))
            val rs1 = Output(UInt(5.W))
            val rs2 = Output(UInt(5.W))
            val rd = Output(UInt(5.W))
            val src1 = Output(UInt(32.W))
            val src2 = Output(UInt(32.W))
            val reg_data2 = Output(UInt(32.W))
            val wr_reg = Output(Bool())
            val rd_mem = Output(Bool())
            val wr_mem = Output(Bool())
            val bit_width = Output(BitWidth())
            val sign = Output(Sign())
            val bj_valid = Output(Bool())
            val bj_pc = Output(UInt(32.W))
            val ebreak = Output(Bool())
            val inst = Output(UInt(32.W))
            val pc = Output(UInt(32.W))
        }
    })

    val default = List(InstType.I, FuncType.alu, ALUOp.add, BitWidth.w32, Sign.signed)
    val decoded = ListLookup(io.in.inst, default, MinirvInsts.table)

    val (instType, _)   = InstType.safe(decoded(0).asUInt)
    val (funcType, _)   = FuncType.safe(decoded(1).asUInt)
    val (aluOp, _)      = ALUOp.safe(decoded(2).asUInt)
    val (bitWidth, _)   = BitWidth.safe(decoded(3).asUInt)
    val (sign, _)       = Sign.safe(decoded(4).asUInt)

    val (needRs1, needRs2, needImm, needRd) = DecodePolicy.regUsage(instType)

    // printf("inst: %x, needRs1: %b, needRs2: %b, needImm: %b, needRd: %b\n", io.inst, needRs1, needRs2, needImm, needRd)

    val rs1 = io.in.inst(19, 15)
    val rs2 = io.in.inst(24, 20)
    val rd = io.in.inst(11, 7)

    val imm = DecodePolicy.immExtract(instType, io.in.inst)

    // io.inst_type := instType
    // io.func_type := funcType
    io.out.alu_op := aluOp
    io.out.imm := imm

    io.out.rs1 := rs1
    io.out.rs2 := rs2
    io.out.rd := rd

    when(funcType === FuncType.ebreak) {
        io.out.rs1 := 10.U
        io.out.rs2 := 0.U
        io.out.imm := 0.U
    }

    val src1 = Mux(needRs1, io.in.rdata1, 0.U)
    val src2 = Mux(needImm, io.out.imm, io.in.rdata2)

    // printf("src1: %x, src2: %x\n", src1, src2)
    
    io.out.src1 := src1
    io.out.src2 := src2
    io.out.reg_data2 := io.in.rdata2
    when(funcType === FuncType.jplk) { 
        io.out.src1 := io.in.pc
        io.out.src2 := 4.U
    }

    io.out.wr_reg := needRd
    io.out.rd_mem := funcType === FuncType.ld
    io.out.wr_mem := funcType === FuncType.st
    io.out.bit_width := bitWidth
    io.out.sign := sign

    io.out.bj_valid := (funcType === FuncType.jump) || (funcType === FuncType.jplk) // || (funcType === FuncType.br) && ...
    io.out.bj_pc := (src1 + imm) & ~(1.U(32.W))

    // printf("src1: %x, imm: %x, bj_valid: %b, bj_pc: %x\n", src1, imm, io.bj_valid, io.bj_pc)

    io.out.ebreak := funcType === FuncType.ebreak

    io.out.inst := io.in.inst
    io.out.pc := io.in.pc

    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.in.pc
    iringbuf.inst := io.in.inst
    iringbuf.before_ifetch := false.B
    iringbuf.after_ifetch := io.in.valid
}
