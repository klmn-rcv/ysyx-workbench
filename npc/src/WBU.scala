package cpu

import chisel3._
import chisel3.util._

class WBU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val data = Input(UInt(32.W))
            val wr_reg = Input(Bool())
            val rd = Input(UInt(5.W))
            val ebreak = Input(Bool())
            val inst = Input(UInt(32.W))
            val pc = Input(UInt(32.W))
        }
        val out = new Bundle {
            val wb_data = Output(UInt(32.W))
            val wb_we = Output(Bool())
            val wb_addr = Output(UInt(5.W))
        }
    })

    // jump writes link value (pc+4); arithmetic writes ALU result.
    io.out.wb_data := io.in.data
    io.out.wb_we := io.in.wr_reg
    io.out.wb_addr := io.in.rd

    val halt = Module(new Halt)
    halt.exit_code := io.in.data
    halt.ebreak := io.in.ebreak

    val reset_reg = RegInit(true.B)
    reset_reg := reset

    val itrace = Module(new Itrace)
    itrace.clk := clock
    itrace.rst := reset
    itrace.valid := !reset_reg
    itrace.pc := io.in.pc // TODO: connect with real pc
    itrace.inst := io.in.inst // TODO: connect with real inst
}
