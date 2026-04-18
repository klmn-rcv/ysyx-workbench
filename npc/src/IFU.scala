package cpu

import chisel3._
import chisel3.util._

class IFU extends Module {
    val io = IO(new Bundle {
        val out = Decoupled(new IFUOut)
        val ctrl = new Bundle {
            val ex_redirect_valid = Input(Bool())
            val ex_redirect_target = Input(UInt(32.W))
            val jump_valid = Input(Bool())
            val jump_target = Input(UInt(32.W))
            val br_taken = Input(Bool())
            val br_target = Input(UInt(32.W))
        }
    })

    val ready_go = true.B

    // io.out.valid := !reset.asBool  // 等到改为pipeline后再改回这个样子
    io.out.valid := RegNext(!reset.asBool, false.B)

    val pc_reg = RegInit("h7ffffffc".U(32.W))
    val snpc = pc_reg + 4.U
    val dnpc = Mux(io.ctrl.ex_redirect_valid, io.ctrl.ex_redirect_target,
               Mux(io.ctrl.br_taken, io.ctrl.br_target,
               Mux(io.ctrl.jump_valid, io.ctrl.jump_target, snpc)))
    pc_reg := dnpc
    // io.out.bits.inst := DontCare
    io.out.bits.pc := pc_reg
    io.out.bits.dnpc := dnpc

    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.out.bits.dnpc
    iringbuf.inst := 0.U(32.W)
    iringbuf.before_ifetch := true.B
    iringbuf.after_ifetch := false.B
}
