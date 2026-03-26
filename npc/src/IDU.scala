package cpu

import chisel3._
import chisel3.util._

class IDU extends Module {
    val io = IO(new Bundle {
        val inst = Input(UInt(32.W))

        val rdata1 = Input(UInt(32.W))
        val rdata2 = Input(UInt(32.W))

        val pc = Input(UInt(32.W))

        // val inst_type = Output(InstType())
        // val func_type = Output(FuncType())
        val alu_op = Output(ALUOp())

        val imm = Output(UInt(32.W))

        val rs1 = Output(UInt(5.W))
        val rs2 = Output(UInt(5.W))
        val rd = Output(UInt(5.W))

        val src1 = Output(UInt(32.W))
        val src2 = Output(UInt(32.W))
        
        val wr_reg = Output(Bool())

        val bj_valid = Output(Bool())
        val bj_pc = Output(UInt(32.W))
    })

    val default = List(InstType.I, FuncType.alu, ALUOp.add)
    val decoded = ListLookup(io.inst, default, MinirvInsts.table)

    val (instType, _) = InstType.safe(decoded(0).asUInt)
    val (funcType, _) = FuncType.safe(decoded(1).asUInt)
    val (aluOp, _) = ALUOp.safe(decoded(2).asUInt)

    val (needRs1, needRs2, needRd) = DecodePolicy.regUsage(instType)

    val rs1 = io.inst(19, 15)
    val rs2 = io.inst(24, 20)
    val rd = io.inst(11, 7)

    val imm = DecodePolicy.immExtract(instType, io.inst)

    // io.inst_type := instType
    // io.func_type := funcType
    io.alu_op := aluOp
    io.imm := imm

    io.rs1 := rs1
    io.rs2 := rs2
    io.rd := rd

    val src1 = Mux(needRs1, io.rdata1, 0.U)
    val src2 = Mux(needRs2, io.rdata2, imm)
    
    io.src1 := src1
    io.src2 := src2
    when(funcType === FuncType.jplk) { 
        io.src1 := io.pc
        io.src2 := 4.U
    }

    io.wr_reg := needRd
    io.bj_valid := (funcType === FuncType.jump) || (funcType === FuncType.jplk) // || (funcType === FuncType.br) && ...
    io.bj_pc := (src1 + imm) & ~1.U
}
