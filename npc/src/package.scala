import chisel3._
import chisel3.util._

package object cpu {
    object ALUOp extends ChiselEnum {
        val add, sub, slt, sltu, and, or, xor, sll, srl, sra, lui = Value
    }

    object InstType extends ChiselEnum {
        val R, I, S, B, U, J, N = Value   // N: No type (invalid instruction)
    }

    object FuncType extends ChiselEnum {
        val alu, ld, st, br, jump, jplk, auipc, ebreak, csr, ecall, mret, inv = Value     // jplk: jump and link
    }

    object BitWidth extends ChiselEnum {
        val w8, w16, w32 = Value
    }
    
    object Sign extends ChiselEnum {
        val signed, unsigned = Value
    }

    // A typed policy layer: map abstract instruction classes to control metadata.
    object DecodePolicy {
        def immExtract(instType: InstType.Type, inst: UInt): UInt = {
            val imm: UInt = MuxLookup(instType.asUInt, 0.U(32.W))(Seq(
                InstType.R.asUInt -> 0.U(32.W),  // R-type has no immediate
                InstType.I.asUInt -> Cat(Fill(20, inst(31)), inst(31, 20)),
                InstType.S.asUInt -> Cat(Fill(20, inst(31)), inst(31, 25), inst(11, 7)),
                InstType.B.asUInt -> Cat(Fill(19, inst(31)), inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W)),
                InstType.U.asUInt -> (inst(31, 12) << 12),
                InstType.J.asUInt -> Cat(Fill(11, inst(31)), inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))
            ))
            imm
        }

        // Return (needRs1, needRs2, needImm, needRd)
        def regUsage(instType: InstType.Type): (Bool, Bool, Bool, Bool) = {
            val usageBits = MuxLookup(instType.asUInt, "b0000".U(4.W))(Seq(
                InstType.R.asUInt -> "b1101".U(4.W),
                InstType.I.asUInt -> "b1011".U(4.W),
                InstType.S.asUInt -> "b1110".U(4.W),
                InstType.B.asUInt -> "b1110".U(4.W),
                InstType.U.asUInt -> "b0011".U(4.W),
                InstType.J.asUInt -> "b0011".U(4.W)
            ))
            (usageBits(3), usageBits(2), usageBits(1), usageBits(0))
        }
    }

    object RISCV32EInsts extends ChiselEnum {
        // R-type
        val add    = BitPat("b0000000_?????_?????_000_?????_0110011")
        val sub    = BitPat("b0100000_?????_?????_000_?????_0110011")
        val sll    = BitPat("b0000000_?????_?????_001_?????_0110011")
        val slt    = BitPat("b0000000_?????_?????_010_?????_0110011")
        val sltu   = BitPat("b0000000_?????_?????_011_?????_0110011")
        val xor    = BitPat("b0000000_?????_?????_100_?????_0110011")
        val srl    = BitPat("b0000000_?????_?????_101_?????_0110011")
        val sra    = BitPat("b0100000_?????_?????_101_?????_0110011")
        val or     = BitPat("b0000000_?????_?????_110_?????_0110011")
        val and    = BitPat("b0000000_?????_?????_111_?????_0110011")
        // I-type
        val jalr   = BitPat("b???????_?????_?????_000_?????_1100111")
        val lb     = BitPat("b???????_?????_?????_000_?????_0000011")
        val lh     = BitPat("b???????_?????_?????_001_?????_0000011")
        val lw     = BitPat("b???????_?????_?????_010_?????_0000011")
        val lbu    = BitPat("b???????_?????_?????_100_?????_0000011")
        val lhu    = BitPat("b???????_?????_?????_101_?????_0000011")
        val addi   = BitPat("b???????_?????_?????_000_?????_0010011")
        val slti   = BitPat("b???????_?????_?????_010_?????_0010011")
        val sltiu  = BitPat("b???????_?????_?????_011_?????_0010011")
        val xori   = BitPat("b???????_?????_?????_100_?????_0010011")
        val ori    = BitPat("b???????_?????_?????_110_?????_0010011")
        val andi   = BitPat("b???????_?????_?????_111_?????_0010011")
        val slli   = BitPat("b0000000_?????_?????_001_?????_0010011")
        val srli   = BitPat("b0000000_?????_?????_101_?????_0010011")
        val srai   = BitPat("b0100000_?????_?????_101_?????_0010011")
        val csrrw  = BitPat("b???????_?????_?????_001_?????_1110011")
        val csrrs  = BitPat("b???????_?????_?????_010_?????_1110011")
        val csrrc  = BitPat("b???????_?????_?????_011_?????_1110011")
        val csrrwi = BitPat("b???????_?????_?????_101_?????_1110011")
        val csrrsi = BitPat("b???????_?????_?????_110_?????_1110011")
        val csrrci = BitPat("b???????_?????_?????_111_?????_1110011")
        // S-type
        val sb     = BitPat("b???????_?????_?????_000_?????_0100011")
        val sh     = BitPat("b???????_?????_?????_001_?????_0100011")
        val sw     = BitPat("b???????_?????_?????_010_?????_0100011")
        // B-type
        val beq    = BitPat("b???????_?????_?????_000_?????_1100011")
        val bne    = BitPat("b???????_?????_?????_001_?????_1100011")
        val blt    = BitPat("b???????_?????_?????_100_?????_1100011")
        val bge    = BitPat("b???????_?????_?????_101_?????_1100011")
        val bltu   = BitPat("b???????_?????_?????_110_?????_1100011")
        val bgeu   = BitPat("b???????_?????_?????_111_?????_1100011")
        // U-type
        val lui    = BitPat("b???????_?????_?????_???_?????_0110111")
        val auipc  = BitPat("b???????_?????_?????_???_?????_0010111")
        // J-type
        val jal    = BitPat("b???????_?????_?????_???_?????_1101111")
        // N-type
        val ecall  = BitPat("b0000000_00000_00000_000_00000_1110011")
        val ebreak = BitPat("b0000000_00001_00000_000_00000_1110011")
        val mret   = BitPat("b0011000_00010_00000_000_00000_1110011")
        
        val table = Array(
            // R-type
            add    -> List(InstType.R, FuncType.alu,    ALUOp.add,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 + src2;
            sub    -> List(InstType.R, FuncType.alu,    ALUOp.sub,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 - src2;
            sll    -> List(InstType.R, FuncType.alu,    ALUOp.sll,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 << (src2 & 0x1f);
            slt    -> List(InstType.R, FuncType.alu,    ALUOp.slt,  BitWidth.w32, Sign.signed  ),  // R(rd) = (sword_t)src1 < (sword_t)src2 ? 1 : 0;
            sltu   -> List(InstType.R, FuncType.alu,    ALUOp.sltu, BitWidth.w32, Sign.unsigned),  // R(rd) = (word_t)src1 < (word_t)src2 ? 1 : 0;
            xor    -> List(InstType.R, FuncType.alu,    ALUOp.xor,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 ^ src2;
            srl    -> List(InstType.R, FuncType.alu,    ALUOp.srl,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 >> (src2 & 0x1f);
            sra    -> List(InstType.R, FuncType.alu,    ALUOp.sra,  BitWidth.w32, Sign.signed  ),  // R(rd) = (sword_t)src1 >> (src2 & 0x1f);
            or     -> List(InstType.R, FuncType.alu,    ALUOp.or,   BitWidth.w32, Sign.signed  ),  // R(rd) = src1 | src2;
            and    -> List(InstType.R, FuncType.alu,    ALUOp.and,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 & src2;
            
            // I-type
            jalr   -> List(InstType.I, FuncType.jplk,   ALUOp.add,  BitWidth.w32, Sign.signed  ),  // R(rd) = s->snpc; s->dnpc = (src1 + imm) & ~1; FTRACE_JALR_HOOK();
            lb     -> List(InstType.I, FuncType.ld,     ALUOp.add,  BitWidth.w8,  Sign.signed  ),  // R(rd) = SEXT(Mr(src1 + imm, 1), 8);
            lh     -> List(InstType.I, FuncType.ld,     ALUOp.add,  BitWidth.w16, Sign.signed  ),  // R(rd) = SEXT(Mr(src1 + imm, 2), 16);
            lw     -> List(InstType.I, FuncType.ld,     ALUOp.add,  BitWidth.w32, Sign.signed  ),  // R(rd) = Mr(src1 + imm, 4);
            lbu    -> List(InstType.I, FuncType.ld,     ALUOp.add,  BitWidth.w8,  Sign.unsigned),  // R(rd) = Mr(src1 + imm, 1);
            lhu    -> List(InstType.I, FuncType.ld,     ALUOp.add,  BitWidth.w16, Sign.unsigned),  // R(rd) = Mr(src1 + imm, 2);
            addi   -> List(InstType.I, FuncType.alu,    ALUOp.add,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 + imm;
            slti   -> List(InstType.I, FuncType.alu,    ALUOp.slt,  BitWidth.w32, Sign.signed  ),  // R(rd) = (sword_t)src1 < (sword_t)imm ? 1 : 0;
            sltiu  -> List(InstType.I, FuncType.alu,    ALUOp.sltu, BitWidth.w32, Sign.unsigned),  // R(rd) = (word_t)src1 < (word_t)imm ? 1 : 0;
            xori   -> List(InstType.I, FuncType.alu,    ALUOp.xor,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 ^ imm;
            ori    -> List(InstType.I, FuncType.alu,    ALUOp.or,   BitWidth.w32, Sign.signed  ),  // R(rd) = src1 | imm;
            andi   -> List(InstType.I, FuncType.alu,    ALUOp.and,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 & imm;
            slli   -> List(InstType.I, FuncType.alu,    ALUOp.sll,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 << (imm & 0x1f);
            srli   -> List(InstType.I, FuncType.alu,    ALUOp.srl,  BitWidth.w32, Sign.signed  ),  // R(rd) = src1 >> (imm & 0x1f);
            srai   -> List(InstType.I, FuncType.alu,    ALUOp.sra,  BitWidth.w32, Sign.signed  ),  // R(rd) = (sword_t)src1 >> (imm & 0x1f);
            csrrw  -> List(InstType.I, FuncType.csr,    ALUOp.add,  BitWidth.w32, Sign.signed  ),  // word_t *csr; CSR_OPERAND_FETCH(csr); word_t old = *csr; *csr = src1; R(rd) = old);
            csrrs  -> List(InstType.I, FuncType.csr,    ALUOp.add,  BitWidth.w32, Sign.signed  ),  // word_t *csr, rs1; CSR_OPERAND_FETCH(csr); rs1 = RS1_OR_UIMM(); word_t old = *csr; if(rs1 != 0) *csr = old | src1; R(rd) = old);
            csrrc  -> List(InstType.I, FuncType.csr,    ALUOp.add,  BitWidth.w32, Sign.signed  ),  // word_t *csr, rs1; CSR_OPERAND_FETCH(csr); rs1 = RS1_OR_UIMM(); word_t old = *csr; if(rs1 != 0) *csr = old & ~src1; R(rd) = old);
            csrrwi -> List(InstType.I, FuncType.csr,    ALUOp.add,  BitWidth.w32, Sign.signed  ),  // word_t *csr, uimm; CSR_OPERAND_FETCH(csr); uimm = RS1_OR_UIMM(); word_t old = *csr; *csr = uimm; R(rd) = old);
            csrrsi -> List(InstType.I, FuncType.csr,    ALUOp.add,  BitWidth.w32, Sign.signed  ),  // word_t *csr, uimm; CSR_OPERAND_FETCH(csr); uimm = RS1_OR_UIMM(); word_t old = *csr; if(uimm != 0) *csr = old | uimm; R(rd) = old);
            csrrci -> List(InstType.I, FuncType.csr,    ALUOp.add,  BitWidth.w32, Sign.signed  ),  // word_t *csr, uimm; CSR_OPERAND_FETCH(csr); uimm = RS1_OR_UIMM(); word_t old = *csr; if(uimm != 0) *csr = old & ~uimm; R(rd) = old);

            // S-type
            sb     -> List(InstType.S, FuncType.st,     ALUOp.add,  BitWidth.w8,  Sign.signed  ),  // Mw(src1 + imm, 1, src2);
            sh     -> List(InstType.S, FuncType.st,     ALUOp.add,  BitWidth.w16, Sign.signed  ),  // Mw(src1 + imm, 2, src2);
            sw     -> List(InstType.S, FuncType.st,     ALUOp.add,  BitWidth.w32, Sign.signed  ),  // Mw(src1 + imm, 4, src2);

            // B-type
            beq    -> List(InstType.B, FuncType.br,     ALUOp.sub,  BitWidth.w32, Sign.signed  ),  // s->dnpc = (src1 == src2 ? s->pc + imm : s->snpc);
            bne    -> List(InstType.B, FuncType.br,     ALUOp.sub,  BitWidth.w32, Sign.signed  ),  // s->dnpc = (src1 != src2 ? s->pc + imm : s->snpc);
            blt    -> List(InstType.B, FuncType.br,     ALUOp.slt,  BitWidth.w32, Sign.signed  ),  // s->dnpc = ((sword_t)src1 < (sword_t)src2 ? s->pc + imm : s->snpc);
            bge    -> List(InstType.B, FuncType.br,     ALUOp.slt,  BitWidth.w32, Sign.signed  ),  // s->dnpc = ((sword_t)src1 >= (sword_t)src2 ? s->pc + imm : s->snpc);
            bltu   -> List(InstType.B, FuncType.br,     ALUOp.sltu, BitWidth.w32, Sign.unsigned),  // s->dnpc = ((word_t)src1 < (word_t)src2 ? s->pc + imm : s->snpc);
            bgeu   -> List(InstType.B, FuncType.br,     ALUOp.sltu, BitWidth.w32, Sign.unsigned),  // s->dnpc = ((word_t)src1 >= (word_t)src2 ? s->pc + imm : s->snpc);

            // U-type
            lui    -> List(InstType.U, FuncType.alu,    ALUOp.lui,  BitWidth.w32, Sign.signed  ),  // R(rd) = imm;
            auipc  -> List(InstType.U, FuncType.auipc,  ALUOp.add,  BitWidth.w32, Sign.signed  ),  // R(rd) = s->pc + imm;

            // J-type
            jal    -> List(InstType.J, FuncType.jplk,   ALUOp.add,  BitWidth.w32, Sign.signed  ),  // R(rd) = s->snpc; s->dnpc = s->pc + imm; FTRACE_JAL_HOOK();
        
            // N-type
            ecall  -> List(InstType.N, FuncType.ecall,  ALUOp.add,  BitWidth.w32, Sign.signed  ),  // word_t NO; ECALL_GET_NO(NO); s->dnpc = isa_raise_intr(NO, s->pc);
            ebreak -> List(InstType.N, FuncType.ebreak, ALUOp.add,  BitWidth.w32, Sign.signed  ),  // NEMUTRAP(s->pc, R(10));
            mret   -> List(InstType.N, FuncType.mret,   ALUOp.add,  BitWidth.w32, Sign.signed  ),  // s->dnpc = isa_return_trap();
        )
    }

    object MaskGen {
        def apply(addr: UInt, bitWidth: BitWidth.Type): UInt = {
            val mask = MuxLookup(bitWidth.asUInt, "b0000".U(4.W))(Seq(
                BitWidth.w8.asUInt -> UIntToOH(addr(1, 0), 4),    // UIntToOH是译码器，这里生成0001/0010/0100/1000
                BitWidth.w16.asUInt -> Mux(addr(1), "b1100".U(4.W), "b0011".U(4.W)),    // 0011/1100
                BitWidth.w32.asUInt -> "b1111".U(4.W)
            ))
            mask
        }
    }

    object ExtractLoadData {
        def apply(rdata: UInt, addr: UInt, bitWidth: BitWidth.Type, sign: Sign.Type): UInt = {
            val shifted = rdata >> (addr(1, 0) << 3)  // addr(1, 0) << 3 就是 addr(1, 0) * 8，shifted是把rdata里我们需要的部分右移到边界
            val b = shifted(7, 0)
            val h = shifted(15, 0)
            val loadData = MuxLookup(bitWidth.asUInt, shifted)(Seq(
                BitWidth.w8.asUInt -> Mux(sign === Sign.signed, Cat(Fill(24, b(7)), b), b),
                BitWidth.w16.asUInt -> Mux(sign === Sign.signed, Cat(Fill(16, h(15)), h), h),
                BitWidth.w32.asUInt -> shifted
            ))
            loadData
        }
    }

    class CSRReq extends Bundle {
        val addr = UInt(12.W)
        val re = Bool()
        val we = Bool()
        val wmask = UInt(32.W)
        val wvalue = UInt(32.W)
    }

    class CSRResp extends Bundle {
        val rvalue = UInt(32.W)
    }

    object PrivilegeLevel {
        val user = 0.U(2.W)
        val supervisor = 1.U(2.W)
        val machine = 3.U(2.W)
    }

    object ExceptionCode {
        val ecall_from_u = 8
        val ecall_from_s = 9
        val ecall_from_m = 11
    }

}
