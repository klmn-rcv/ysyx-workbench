package cpu

import chisel3._
import chisel3.util._

class IDU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new IFUOut))
        val out = Decoupled(new IDUOut)
        val inst = Input(UInt(32.W))   // 等到改为pipeline，这个inst信号就可以删掉了，直接从io.in.bits.inst里取
        val rf = new Bundle {
            val rs1 = Output(UInt(5.W))
            val rs2 = Output(UInt(5.W))
            val rdata1 = Input(UInt(32.W))
            val rdata2 = Input(UInt(32.W))
        }
        val ctrl = new Bundle {
            val jump_valid = Output(Bool())
            val jump_target = Output(UInt(32.W))
        }
    })

    val ready_go = true.B
    io.in.ready := !reset.asBool && (!io.in.valid || ready_go && io.out.ready)
    io.out.valid := io.in.valid && ready_go

    val default = List(InstType.N, FuncType.inv, ALUOp.add, BitWidth.w32, Sign.signed)
    val decoded = ListLookup(io.inst, default, RISCV32EInsts.table)

    val (instType, _)   = InstType.safe(decoded(0).asUInt)
    val (funcType, _)   = FuncType.safe(decoded(1).asUInt)
    val (aluOp, _)      = ALUOp.safe(decoded(2).asUInt)
    val (bitWidth, _)   = BitWidth.safe(decoded(3).asUInt)
    val (sign, _)       = Sign.safe(decoded(4).asUInt)

    val (needRs1, needRs2, needImm, needRd) = DecodePolicy.regUsage(instType)

    // printf("inst: %x, needRs1: %b, needRs2: %b, needImm: %b, needRd: %b\n", io.inst, needRs1, needRs2, needImm, needRd)

    val rs1 = io.inst(19, 15)
    val rs2 = io.inst(24, 20)
    val rd = io.inst(11, 7)

    val imm = DecodePolicy.immExtract(instType, io.inst)

    // io.inst_type := instType
    // io.func_type := funcType
    io.out.bits.alu_op := aluOp

    io.rf.rs1 := rs1
    io.rf.rs2 := rs2
    io.out.bits.rd := rd

    when(funcType === FuncType.ebreak) {
        io.rf.rs1 := 10.U
        io.out.bits.src1 := io.rf.rdata1
        io.out.bits.src2 := 0.U
    }

    val src1 = Mux(needRs1, io.rf.rdata1, 0.U)
    val src2 = Mux(funcType === FuncType.br, io.rf.rdata2,
               Mux(needImm, imm, Mux(needRs2, io.rf.rdata2, 0.U)))

    // printf("src1: %x, src2: %x\n", src1, src2)
    
    io.out.bits.src1 := src1
    io.out.bits.src2 := src2
    io.out.bits.reg_data2 := io.rf.rdata2
    when(funcType === FuncType.jplk) {
        io.out.bits.src1 := io.in.bits.pc
        io.out.bits.src2 := 4.U
    }

    when(funcType === FuncType.auipc) {
        io.out.bits.src1 := io.in.bits.pc
        io.out.bits.src2 := imm
    }

    io.out.bits.wr_reg := needRd
    io.out.bits.rd_mem := funcType === FuncType.ld
    io.out.bits.wr_mem := funcType === FuncType.st
    io.out.bits.bit_width := bitWidth
    io.out.bits.sign := sign

    io.ctrl.jump_valid := funcType === FuncType.jplk
    io.ctrl.jump_target := Mux(
        instType === InstType.J,
        io.in.bits.pc + imm,
        (io.rf.rdata1 + imm) & ~(1.U(32.W))
    )

    io.out.bits.br_target := io.in.bits.pc + imm
    io.out.bits.br_valid := funcType === FuncType.br
    io.out.bits.br_expect_0 := (funcType === FuncType.br) &&
        ((io.inst(14, 12) === "b000".U) || (io.inst(14, 12) === "b101".U) || (io.inst(14, 12) === "b111".U))

    // printf("src1: %x, imm: %x, bj_valid: %b, bj_pc: %x\n", src1, imm, io.bj_valid, io.bj_pc)

    io.out.bits.ebreak := funcType === FuncType.ebreak
    io.out.bits.inv := io.in.valid && funcType === FuncType.inv

    io.out.bits.inst := io.inst
    io.out.bits.pc := io.in.bits.pc
    io.out.bits.dnpc := io.in.bits.dnpc
    // CSR指令相关译码信号
    io.out.bits.csrReq.addr := 0.U
    io.out.bits.csrReq.re := false.B
    io.out.bits.csrReq.we := false.B
    io.out.bits.csrReq.wmask := 0.U
    io.out.bits.csrReq.wvalue := 0.U
    val csr_src1 = Mux(io.inst(14) === 0.U, io.rf.rdata1, Cat(0.U(27.W), io.inst(19, 15)))  // io.inst(19, 15) is uimm, zero-extend to 32 bits
    val csr_sc_we = Mux(io.inst(19, 15) === 0.U, false.B, true.B)

    when(funcType === FuncType.csr) {
        io.out.bits.csrReq.addr := io.inst(31, 20)
        io.out.bits.csrReq.re := true.B
        switch(io.inst(13, 12)) {
            is("b01".U) {
                io.out.bits.csrReq.we := true.B
                io.out.bits.csrReq.wvalue := csr_src1
                io.out.bits.csrReq.wmask := "hffffffff".U
            }
            is("b10".U) {
                io.out.bits.csrReq.we := csr_sc_we
                io.out.bits.csrReq.wvalue := "hffffffff".U
                io.out.bits.csrReq.wmask := csr_src1
            }
            is("b11".U) {
                io.out.bits.csrReq.we := csr_sc_we
                io.out.bits.csrReq.wvalue := 0.U
                io.out.bits.csrReq.wmask := csr_src1
            }
        }
    }

    io.out.bits.ecall := funcType === FuncType.ecall
    io.out.bits.mret := funcType === FuncType.mret

    // trace
    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.in.bits.pc
    iringbuf.inst := io.inst
    iringbuf.before_ifetch := false.B
    iringbuf.after_ifetch := io.in.valid

    val ftrace = Module(new Ftrace)
    ftrace.clk := clock
    ftrace.rst := reset
    ftrace.pc := io.in.bits.pc
    ftrace.target_pc := io.ctrl.jump_target
    ftrace.rd := rd
    ftrace.rs1 := rs1
    ftrace.imm := imm
    ftrace.is_jal := instType === InstType.J && funcType === FuncType.jplk
    ftrace.is_jalr := instType === InstType.I && funcType === FuncType.jplk
}
