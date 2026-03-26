package cpu

import chisel3._
import chisel3.util._

class ALU extends Module {
    val io = IO(new Bundle {
        val alu_src1 = Input(UInt(32.W))
        val alu_src2 = Input(UInt(32.W))
        val alu_op = Input(ALUOp())
        val alu_result = Output(UInt(32.W))
    })
    io.alu_result := 0.U
    switch(io.alu_op) {
        is(ALUOp.add) { io.alu_result := io.alu_src1 + io.alu_src2 }
        is(ALUOp.sub) { io.alu_result := io.alu_src1 - io.alu_src2 }
        is(ALUOp.slt) { io.alu_result := (io.alu_src1.asSInt < io.alu_src2.asSInt).asUInt } // 也可以用Mux实现
        is(ALUOp.sltu) { io.alu_result := (io.alu_src1 < io.alu_src2).asUInt }
        is(ALUOp.and) { io.alu_result := io.alu_src1 & io.alu_src2 }
        is(ALUOp.or) { io.alu_result := io.alu_src1 | io.alu_src2 }
        is(ALUOp.xor) { io.alu_result := io.alu_src1 ^ io.alu_src2 }
        is(ALUOp.sll) { io.alu_result := io.alu_src1 << io.alu_src2(4, 0) }
        is(ALUOp.srl) { io.alu_result := io.alu_src1 >> io.alu_src2(4, 0) }
        is(ALUOp.sra) { io.alu_result := (io.alu_src1.asSInt >> io.alu_src2(4, 0)).asUInt }
        is(ALUOp.lui) { io.alu_result := io.alu_src2 }
    }
}

//// 如果不用switch这种行为级描述，可以按照下面的方式实现，这本质上和switch生成的电路是一样的（MuxLookup并行多路选择器）
//   // 预计算每种操作的结果
//   val add_res = io.alu_src1 + io.alu_src2
//   val sub_res = io.alu_src1 - io.alu_src2
//   val slt_res = (io.alu_src1.asSInt < io.alu_src2.asSInt).asUInt
//   val sltu_res = (io.alu_src1 < io.alu_src2).asUInt
//   val and_res = io.alu_src1 & io.alu_src2
//   val or_res  = io.alu_src1 | io.alu_src2
//   val xor_res = io.alu_src1 ^ io.alu_src2
//   val sll_res = io.alu_src1 << io.alu_src2(4, 0)
//   val srl_res = io.alu_src1 >> io.alu_src2(4, 0)
//   val sra_res = (io.alu_src1.asSInt >> io.alu_src2(4, 0)).asUInt
//   val lui_res = io.alu_src2

//   // 使用 MuxLookup 根据 alu_op 选择结果
//   io.alu_result := MuxLookup(io.alu_op.asUInt, 0.U(32.W))(
//     Seq(
//       ALUOp.add.asUInt -> add_res,
//       ALUOp.sub.asUInt -> sub_res,
//       ALUOp.slt.asUInt -> slt_res,
//       ALUOp.sltu.asUInt -> sltu_res,
//       ALUOp.and.asUInt -> and_res,
//       ALUOp.or.asUInt  -> or_res,
//       ALUOp.xor.asUInt -> xor_res,
//       ALUOp.sll.asUInt -> sll_res,
//       ALUOp.srl.asUInt -> srl_res,
//       ALUOp.sra.asUInt -> sra_res,
//       ALUOp.lui.asUInt -> lui_res
//     )
//   )


//// 也可以用WireDefault和多个when实现，但生成的电路是优先级选择器，而不是并行多路选择器，效率比上面两种低
//   // 定义结果线，默认值为 0
//   val result = WireDefault(0.U(32.W))

//   // 优先级链（实际按 alu_op 值匹配）
//   when(io.alu_op === ALUOp.add) {
//     result := io.alu_src1 + io.alu_src2
//   }.elsewhen(io.alu_op === ALUOp.sub) {
//     result := io.alu_src1 - io.alu_src2
//   }.elsewhen(io.alu_op === ALUOp.slt) {
//     result := (io.alu_src1.asSInt < io.alu_src2.asSInt).asUInt
//   }
//   // ... 其他 elsewhen 分支
//   .otherwise {
//     result := 0.U
//   }

//   io.alu_result := result
