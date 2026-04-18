package cpu

import chisel3._
import chisel3.util._

class WBU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new LSUOut))
        val csr = new Bundle {
            val priv = Input(UInt(2.W))
            val csrReq = Output(new CSRReq)
            val csrResp = Input(new CSRResp)
            val wb_ex = Output(Bool())
            val wb_cause = Output(UInt(32.W))
            val wb_pc = Output(UInt(32.W))
            val mret = Output(Bool())
        }
        val rf = new Bundle {
            val wb_data = Output(UInt(32.W))
            val wb_we = Output(Bool())
            val wb_addr = Output(UInt(5.W))
        }
    })

    val ready_go = true.B
    io.in.ready := !reset.asBool && (!io.in.valid || ready_go)

    // jump writes link value (pc+4); arithmetic writes ALU result.
    io.rf.wb_data := Mux(io.in.bits.csrReq.re, io.csr.csrResp.rvalue, io.in.bits.data)
    io.rf.wb_we := io.in.bits.wr_reg
    io.rf.wb_addr := io.in.bits.rd
    io.csr.csrReq := io.in.bits.csrReq
    io.csr.mret := io.in.bits.mret
    io.csr.wb_ex := false.B
    io.csr.wb_cause := 0.U
    io.csr.wb_pc := 0.U

    val wb_cause = WireDefault(0.U(32.W))

    switch(io.csr.priv) {
        is(PrivilegeLevel.user)       { wb_cause := ExceptionCode.ecall_from_u.U }
        is(PrivilegeLevel.supervisor) { wb_cause := ExceptionCode.ecall_from_s.U }
        is(PrivilegeLevel.machine)    { wb_cause := ExceptionCode.ecall_from_m.U }
    }

    when(io.in.bits.ecall) {
        io.csr.wb_ex := true.B
        io.csr.wb_cause := wb_cause
        io.csr.wb_pc := io.in.bits.pc
    }

    // Black boxes
    val halt = Module(new Halt)
    halt.exit_code := Mux(io.in.bits.inv, 1.U, io.in.bits.data)
    halt.exit_pc := io.in.bits.pc
    halt.halt_valid := io.in.bits.ebreak || io.in.bits.inv

    val reset_reg = RegInit(true.B)
    reset_reg := reset

    val itrace = Module(new Itrace)
    itrace.clk := clock
    itrace.rst := reset
    itrace.valid := !reset_reg
    itrace.pc := io.in.bits.pc
    itrace.inst := io.in.bits.inst
    itrace.dnpc := io.in.bits.dnpc
}
