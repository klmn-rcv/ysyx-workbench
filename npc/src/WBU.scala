package cpu

import chisel3._
import chisel3.util._

class WBU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new LSWUOut))
        val csr = new Bundle {
            val priv = Input(UInt(2.W))
            val csrReq = Output(new CSRReq)
            val csrResp = Input(new CSRResp)
            val mtvec = Input(UInt(32.W))
            val mepc = Input(UInt(32.W))
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
        val ctrl = new Bundle {
            val ex_redirect_valid = Output(Bool())
            val ex_redirect_target = Output(UInt(32.W))
        }
        val flush = new Bundle {
            val flush = Output(Bool())
        }
    })

    val flush = io.in.bits.need_flush_in_LSU_or_LSWU
    val valid = io.in.valid && !flush

    io.in.ready := !reset.asBool

    io.flush.flush := flush

    val dnpc = Mux(io.ctrl.ex_redirect_valid, io.ctrl.ex_redirect_target, io.in.bits.dnpc)
    val submit_dnpc = RegEnable(dnpc, 0.U(32.W), valid)

    dontTouch(submit_dnpc)

    io.ctrl.ex_redirect_valid := io.csr.wb_ex || io.csr.mret  // 可以保证只持续一拍
    io.ctrl.ex_redirect_target := Mux(io.csr.wb_ex, io.csr.mtvec & "hfffffffc".U(32.W), io.csr.mepc)

    // jump writes link value (pc+4); arithmetic writes ALU result.
    io.rf.wb_data := Mux(io.in.bits.csrReq.re, io.csr.csrResp.rvalue, io.in.bits.data)
    io.rf.wb_we := io.in.bits.wr_reg && valid
    io.rf.wb_addr := io.in.bits.rd

    io.csr.mret := io.in.bits.mret && valid
    io.csr.wb_ex := false.B && valid
    io.csr.wb_cause := 0.U(32.W)
    io.csr.wb_pc := 0.U(32.W)

    io.csr.csrReq.re := io.in.bits.csrReq.re && valid
    io.csr.csrReq.we := io.in.bits.csrReq.we && valid
    io.csr.csrReq.addr := io.in.bits.csrReq.addr
    io.csr.csrReq.wmask := io.in.bits.csrReq.wmask
    io.csr.csrReq.wvalue := io.in.bits.csrReq.wvalue

    val wb_cause = WireDefault(0.U(32.W))

    switch(io.csr.priv) {
        is(PrivilegeLevel.user)       { wb_cause := ExceptionCode.ecall_from_u.U }
        is(PrivilegeLevel.supervisor) { wb_cause := ExceptionCode.ecall_from_s.U }
        is(PrivilegeLevel.machine)    { wb_cause := ExceptionCode.ecall_from_m.U }
    }

    when(io.in.bits.ecall) {
        io.csr.wb_ex := valid
        io.csr.wb_cause := wb_cause
        io.csr.wb_pc := io.in.bits.pc
    }

    // Black boxes
    val halt = Module(new Halt)
    halt.clk := clock
    halt.rst := reset
    halt.exit_code := Mux(io.in.bits.inv, 1.U, io.in.bits.data)
    halt.exit_pc := io.in.bits.pc
    halt.halt_valid := (io.in.bits.ebreak || io.in.bits.inv) && valid

    val itrace = Module(new Itrace)
    itrace.clk := clock
    itrace.rst := reset
    itrace.valid := valid
    itrace.pc := io.in.bits.pc
    itrace.inst := io.in.bits.inst
    itrace.dnpc := dnpc
}
