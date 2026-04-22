package cpu

import chisel3._
import chisel3.util._

class IDU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new IWUOut))
        val out = Decoupled(new IDUOut)
        // val inst = Input(UInt(32.W))   // 等到改为pipeline，这个inst信号就可以删掉了，直接从io.in.bits.inst里取
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
        val raw_info = new Bundle {
            val needRs1 = Output(Bool())
            val needRs2 = Output(Bool())
            val isRAW = Input(Bool())
        }
        val flush = new Bundle {
            val br_taken = Input(Bool())
            val flush = Output(Bool())
        }
    })

    val flush = Wire(Bool())

    val valid = io.in.valid && !flush
    val ready_go = !valid || !io.raw_info.isRAW
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    val br_flush = io.flush.br_taken
    flush := br_flush
    io.flush.flush := flush

    val default = List(InstType.N, FuncType.inv, ALUOp.add, BitWidth.w32, Sign.signed)
    val decoded = ListLookup(io.in.bits.inst, default, RISCV32EInsts.table)

    val (instType, _)   = InstType.safe(decoded(0).asUInt)
    val (funcType, _)   = FuncType.safe(decoded(1).asUInt)
    val (aluOp, _)      = ALUOp.safe(decoded(2).asUInt)
    val (bitWidth, _)   = BitWidth.safe(decoded(3).asUInt)
    val (sign, _)       = Sign.safe(decoded(4).asUInt)

    val (needRs1, needRs2, needImm, needRd) = DecodePolicy.regUsage(instType)

    // printf("inst: %x, needRs1: %b, needRs2: %b, needImm: %b, needRd: %b\n", io.in.bits.inst, needRs1, needRs2, needImm, needRd)

    val rs1 = io.in.bits.inst(19, 15)
    val rs2 = io.in.bits.inst(24, 20)
    val rd = io.in.bits.inst(11, 7)

    val imm = DecodePolicy.immExtract(instType, io.in.bits.inst)

    // io.in.bits.inst_type := instType
    // io.func_type := funcType
    io.out.bits.alu_op := aluOp

    io.rf.rs1 := rs1
    io.rf.rs2 := rs2
    io.out.bits.rd := rd
    io.raw_info.needRs1 := needRs1
    io.raw_info.needRs2 := needRs2

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
    io.out.bits.rs2_data := io.rf.rdata2
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

    io.ctrl.jump_valid := funcType === FuncType.jplk && io.out.fire // 在本流水级处理完时才发跳转信号。如果这里只与一个valid，那isRAW为高时也会发跳转信号，此时jump_target还没拿到，会导致IF拿到错误的jump_target。
                                                                    // 之前这里与上的是io.out.valid，这是错的，因为这样flush可能持续多拍，而因为IW被flush掉了，IF里的跳转后的指令可以流到IW，此时如果flush还为高，IW里这条跳转后的指令也会被flush，导致多flush了一些指令。
    io.ctrl.jump_target := Mux(
        instType === InstType.J,
        io.in.bits.pc + imm,
        (io.rf.rdata1 + imm) & ~(1.U(32.W))
    )

    io.out.bits.br_target := io.in.bits.pc + imm
    io.out.bits.br_valid := funcType === FuncType.br
    io.out.bits.br_expect_0 := (funcType === FuncType.br) &&
        ((io.in.bits.inst(14, 12) === "b000".U) || (io.in.bits.inst(14, 12) === "b101".U) || (io.in.bits.inst(14, 12) === "b111".U))

    // printf("src1: %x, imm: %x, bj_valid: %b, bj_pc: %x\n", src1, imm, io.bj_valid, io.bj_pc)

    io.out.bits.ebreak := funcType === FuncType.ebreak
    io.out.bits.inv := funcType === FuncType.inv // && io.in.valid

    io.out.bits.inst := io.in.bits.inst
    io.out.bits.pc := io.in.bits.pc
    io.out.bits.dnpc := io.in.bits.dnpc
    // CSR指令相关译码信号
    io.out.bits.csrReq.addr := 0.U
    io.out.bits.csrReq.re := false.B
    io.out.bits.csrReq.we := false.B
    io.out.bits.csrReq.wmask := 0.U
    io.out.bits.csrReq.wvalue := 0.U
    val csr_src1 = Mux(io.in.bits.inst(14) === 0.U, io.rf.rdata1, Cat(0.U(27.W), io.in.bits.inst(19, 15)))  // io.in.bits.inst(19, 15) is uimm, zero-extend to 32 bits
    val csr_sc_we = Mux(io.in.bits.inst(19, 15) === 0.U, false.B, true.B)

    when(funcType === FuncType.csr) {
        io.out.bits.csrReq.addr := io.in.bits.inst(31, 20)
        io.out.bits.csrReq.re := true.B
        switch(io.in.bits.inst(13, 12)) {
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

    // ftrace（由于流水线阻塞的存在，ftrace内的DPI-C函数可能会被多次调用，所以给is_jal和is_jalr信号加上了io.out.fire）
    val ftrace = Module(new Ftrace)
    ftrace.clk := clock
    ftrace.rst := reset
    ftrace.pc := io.in.bits.pc
    ftrace.target_pc := io.ctrl.jump_target
    ftrace.rd := rd
    ftrace.rs1 := rs1
    ftrace.imm := imm
    ftrace.is_jal := instType === InstType.J && funcType === FuncType.jplk && io.out.fire
    ftrace.is_jalr := instType === InstType.I && funcType === FuncType.jplk && io.out.fire
}
