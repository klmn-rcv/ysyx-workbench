package cpu

import chisel3._
import chisel3.util._

class EXU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new IDUOut))
        val out = Decoupled(new EXUOut)
        val ctrl = new Bundle {
            val br_taken = Output(Bool())
            val br_target = Output(UInt(32.W))
        }
    })

    val valid = io.in.valid // && !flush   // 这里的flush也需要持久化
    val ready_go = true.B
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    val alu = Module(new ALU)
    alu.io.in.src1 := io.in.bits.src1
    alu.io.in.src2 := io.in.bits.src2
    alu.io.in.op := io.in.bits.alu_op

    val br_alu_zero = alu.io.out.result === 0.U
    io.ctrl.br_taken := io.in.bits.br_valid && (br_alu_zero === io.in.bits.br_expect_0) && io.out.valid
    io.ctrl.br_target := io.in.bits.br_target

    io.out.bits.result := alu.io.out.result
    io.out.bits.rs2_data := io.in.bits.rs2_data

    io.out.bits.wr_reg := io.in.bits.wr_reg
    io.out.bits.rd := io.in.bits.rd

    io.out.bits.rd_mem := io.in.bits.rd_mem
    io.out.bits.wr_mem := io.in.bits.wr_mem

    io.out.bits.bit_width := io.in.bits.bit_width
    io.out.bits.sign := io.in.bits.sign

    io.out.bits.ebreak := io.in.bits.ebreak
    io.out.bits.inv := io.in.bits.inv

    io.out.bits.inst := io.in.bits.inst
    io.out.bits.pc := io.in.bits.pc
    io.out.bits.dnpc := io.in.bits.dnpc
    io.out.bits.csrReq := io.in.bits.csrReq

    io.out.bits.ecall := io.in.bits.ecall
    io.out.bits.mret := io.in.bits.mret
}
