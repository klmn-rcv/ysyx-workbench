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
        val alu, ls, br, jump, jplk, ebreak = Value     // jplk: jump and link
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

        // Return (needRs1, needRs2, needRd)
        def regUsage(instType: InstType.Type): (Bool, Bool, Bool) = {
            val usageBits = MuxLookup(instType.asUInt, "b000".U(3.W))(Seq(
                InstType.R.asUInt -> "b111".U(3.W),
                InstType.I.asUInt -> "b101".U(3.W),
                InstType.S.asUInt -> "b110".U(3.W),
                InstType.B.asUInt -> "b110".U(3.W),
                InstType.U.asUInt -> "b001".U(3.W),
                InstType.J.asUInt -> "b001".U(3.W)
            ))
            (usageBits(2), usageBits(1), usageBits(0))
        }
    }

    object MinirvInsts extends ChiselEnum {
        val addi = BitPat("b???????_?????_?????_000_?????_0010011")
        val jalr = BitPat("b???????_?????_?????_000_?????_1100111")
        val ebreak = BitPat("b0000000_00001_00000_000_00000_1110011")
        val table = Array(
            addi -> List(InstType.I, FuncType.alu, ALUOp.add),
            jalr -> List(InstType.I, FuncType.jplk, ALUOp.add),
            ebreak -> List(InstType.I, FuncType.ebreak, ALUOp.add)
        )
    }
}
