import chisel3._
import chisel3.util._

package object cpu {
    object ALUOp extends ChiselEnum {
        val add, sub, slt, sltu, and, or, xor, sll, srl, sra, lui = Value
    }

    object InstType extends ChiselEnum {
        val R, I, S, B, U, J = Value
    }

    object FuncType extends ChiselEnum {
        val alu, ld, st, br, jump, jplk, ebreak = Value     // jplk: jump and link
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

    object MinirvInsts extends ChiselEnum {
        val lui = BitPat("b???????_?????_?????_???_?????_0110111")
        val addi = BitPat("b???????_?????_?????_000_?????_0010011")
        val jalr = BitPat("b???????_?????_?????_000_?????_1100111")
        
        // val lb = BitPat("b???????_?????_?????_000_?????_0000011")
        // val lh = BitPat("b???????_?????_?????_001_?????_0000011")
        val lw = BitPat("b???????_?????_?????_010_?????_0000011")
        val lbu = BitPat("b???????_?????_?????_100_?????_0000011")
        // val lhu = BitPat("b???????_?????_?????_101_????_0000011")
        val sb = BitPat("b???????_?????_?????_000_?????_0100011")
        // val sh = BitPat("b???????_?????_?????_001_?????_0100011")
        val sw = BitPat("b???????_?????_?????_010_?????_0100011")
        val add = BitPat("b0000000_?????_?????_000_?????_0110011")
        val ebreak = BitPat("b0000000_00001_00000_000_00000_1110011")
        
        val table = Array(
            lui -> List(InstType.U, FuncType.alu, ALUOp.lui, BitWidth.w32, Sign.signed),
            addi -> List(InstType.I, FuncType.alu, ALUOp.add, BitWidth.w32, Sign.signed),
            jalr -> List(InstType.I, FuncType.jplk, ALUOp.add, BitWidth.w32, Sign.signed),
            lw -> List(InstType.I, FuncType.ld, ALUOp.add, BitWidth.w32, Sign.signed),
            lbu -> List(InstType.I, FuncType.ld, ALUOp.add, BitWidth.w8, Sign.unsigned),
            sb -> List(InstType.S, FuncType.st, ALUOp.add, BitWidth.w8, Sign.signed),
            sw -> List(InstType.S, FuncType.st, ALUOp.add, BitWidth.w32, Sign.signed),
            add -> List(InstType.R, FuncType.alu, ALUOp.add, BitWidth.w32, Sign.signed),
            ebreak -> List(InstType.I, FuncType.ebreak, ALUOp.add, BitWidth.w32, Sign.signed)
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
}
