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
            val inst_req_ready = Input(Bool())
            // val inst_req_addr = Output(UInt(32.W))
        }
    })

    val inst_req_fire = io.mem.inst_req_valid && io.mem.inst_req_ready
    val inst_req_fire_preserved = bool_preserve(inst_req_fire, io.out.fire)

    val valid = !reset.asBool
    val ready_go = inst_req_fire_preserved
    io.out.valid := valid && ready_go

    io.mem.inst_req_valid := valid && io.out.ready  // io.out.ready是暂时的权衡，这会导致IF在IW没收到指令之前不会发新请求，影响性能
                                                    // 不是io.out.fire是因为不发inst_req根本不可能fire

    val (jump_valid_preserved, jump_target_preserved, _, _)               = valid_and_data_preserve(io.ctrl.jump_valid, io.ctrl.jump_target, io.out.fire, false.B)
    val (br_taken_preserved, br_target_preserved, _, _)                   = valid_and_data_preserve(io.ctrl.br_taken, io.ctrl.br_target, io.out.fire, false.B)
    val (ex_redirect_valid_preserved, ex_redirect_target_preserved, _, _) = valid_and_data_preserve(io.ctrl.ex_redirect_valid, io.ctrl.ex_redirect_target, io.out.fire, false.B)

    val snpc = io.out_bypass.pc + 4.U
    val dnpc = Mux(ex_redirect_valid_preserved, ex_redirect_target_preserved,
               Mux(br_taken_preserved, br_target_preserved,
               Mux(jump_valid_preserved, jump_target_preserved, snpc)))
    io.out_bypass.pc := RegEnable(dnpc, "h7ffffffc".U(32.W), io.out.fire)
    io.out.bits.dnpc := dnpc    // 取指访存发送给内存的地址

    // trace（TODO：由于流水线阻塞的存在，iringbuf内现有函数可能会被多次调用，需要改！！）
    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.out.bits.dnpc
    iringbuf.inst := 0.U(32.W)
    iringbuf.before_ifetch := io.out.fire
    iringbuf.after_ifetch := false.B
}
