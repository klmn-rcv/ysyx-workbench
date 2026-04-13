package cpu

import chisel3._
import chisel3.util._

class WBU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val priv = Input(UInt(2.W))
            val data = Input(UInt(32.W))
            val wr_reg = Input(Bool())
            val rd = Input(UInt(5.W))
            val ebreak = Input(Bool())
            val inv = Input(Bool())
            val inst = Input(UInt(32.W))
            val pc = Input(UInt(32.W))
            val csrReq = Input(new CSRReq)
            val csrResp = Input(new CSRResp)
            val ecall = Input(Bool()) // 注意：CSR读写指令的处理放在了EX，但ecall和mret放在了WB，这就导致在流水线中这里存在一个hazard，需要给ecall和mret打上标记来解决这个问题。
            val mret = Input(Bool())
        }
        val out = new Bundle {
            val wb_data = Output(UInt(32.W))
            val wb_we = Output(Bool())
            val wb_addr = Output(UInt(5.W))
            val csrReq = Output(new CSRReq)
            val wb_ex = Output(Bool())
            val wb_cause = Output(UInt(32.W))
            val wb_pc = Output(UInt(32.W))
            val mret = Output(Bool())
        }
    })

    // jump writes link value (pc+4); arithmetic writes ALU result.
    io.out.wb_data := Mux(io.in.csrReq.re, io.in.csrResp.rvalue, io.in.data)
    io.out.wb_we := io.in.wr_reg
    io.out.wb_addr := io.in.rd
    io.out.csrReq := io.in.csrReq
    io.out.mret := io.in.mret
    io.out.wb_ex := false.B
    io.out.wb_cause := 0.U
    io.out.wb_pc := 0.U

    val wb_cause = WireDefault(0.U(32.W))

    switch(io.in.priv) {
        is(PrivilegeLevel.user)       { wb_cause := ExceptionCode.ecall_from_u.U }
        is(PrivilegeLevel.supervisor) { wb_cause := ExceptionCode.ecall_from_s.U }
        is(PrivilegeLevel.machine)    { wb_cause := ExceptionCode.ecall_from_m.U }
    }

    when(io.in.ecall) {
        io.out.wb_ex := true.B
        io.out.wb_cause := wb_cause
        io.out.wb_pc := io.in.pc
    }

    // Black boxes
    val halt = Module(new Halt)
    halt.exit_code := Mux(io.in.inv, 1.U, io.in.data)
    halt.exit_pc := io.in.pc
    halt.halt_valid := io.in.ebreak || io.in.inv

    val reset_reg = RegInit(true.B)
    reset_reg := reset

    val itrace = Module(new Itrace)
    itrace.clk := clock
    itrace.rst := reset
    itrace.valid := !reset_reg
    itrace.pc := io.in.pc // TODO: connect with real pc
    itrace.inst := io.in.inst // TODO: connect with real inst
}
