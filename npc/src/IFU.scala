package cpu

import chisel3._
import chisel3.util._

class IFU extends Module {
    val io = IO(new Bundle {
        val out = Decoupled(new IFUOut)
        val out_bypass = new Bundle {
            val pc = Output(UInt(32.W)) // 由于pc（实际上是此时IW流水级中的指令的pc）需要在IFU中使用，所以不能直接放在IFUOut中
        }
        val ctrl = new Bundle {
            val ex_redirect_valid = Input(Bool())
            val ex_redirect_target = Input(UInt(32.W))
            val jump_valid = Input(Bool())
            val jump_target = Input(UInt(32.W))
            val br_taken = Input(Bool())
            val br_target = Input(UInt(32.W))
        }
        val mem = new Bundle {
            val inst_req_valid = Output(Bool())
            // val inst_req_addr = Output(UInt(32.W))
        }
    })

    val ready_go = true.B  // 目前的内存收到地址的下一周期就能返回指令，所以IF可以一直给它发地址
    io.out.valid := !reset.asBool

    io.mem.inst_req_valid := io.out.fire && ready_go

    val snpc = io.out_bypass.pc + 4.U
    val dnpc = Mux(io.ctrl.ex_redirect_valid, io.ctrl.ex_redirect_target,
               Mux(io.ctrl.br_taken, io.ctrl.br_target,
               Mux(io.ctrl.jump_valid, io.ctrl.jump_target, snpc)))
    io.out_bypass.pc := RegEnable(dnpc, "h7ffffffc".U(32.W), io.out.fire && ready_go)
    io.out.bits.dnpc := dnpc    // 取指访存发送给内存的地址

    // trace（TODO：由于流水线阻塞的存在，iringbuf内现有函数可能会被多次调用，需要改！！）
    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.out.bits.dnpc
    iringbuf.inst := 0.U(32.W)
    iringbuf.before_ifetch := true.B
    iringbuf.after_ifetch := false.B
}
