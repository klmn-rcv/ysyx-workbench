package cpu

import chisel3._
import chisel3.util._

class IFU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val bj_valid = Input(Bool())
            val bj_pc = Input(UInt(32.W))
        }
        val out = new Bundle {
            val valid = Output(Bool())
            val pc = Output(UInt(32.W))
            val next_pc = Output(UInt(32.W))
        }
    })

    io.out.valid := RegNext(!reset.asBool, false.B)  // valid after reset

    val pc_reg = RegInit("h7ffffffc".U(32.W))
    val snpc = pc_reg + 4.U
    val dnpc = io.in.bj_pc
    pc_reg := io.out.next_pc   // current pc
    io.out.pc := pc_reg
    io.out.next_pc := Mux(io.in.bj_valid, dnpc, snpc)  // next pc

    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.out.next_pc
    iringbuf.inst := 0.U(32.W)
    iringbuf.before_ifetch := true.B
    iringbuf.after_ifetch := false.B
}
