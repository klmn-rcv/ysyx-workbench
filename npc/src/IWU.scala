package cpu

import chisel3._
import chisel3.util._

class IWU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new IFUOut))  // IFUOut暂时没信号
        val in_bypass = new Bundle {
            val pc = Input(UInt(32.W)) // 由于pc（实际上是此时IW流水级中的指令的pc）需要在IFU中使用，所以不能直接放在IFUOut中
        }
        val out = Decoupled(new IWUOut)
        val mem = new Bundle {
            val rinst = Input(UInt(32.W))
        }
        val flush = new Bundle {
            val br_taken = Input(Bool())
            val jump_valid = Input(Bool())
        }
    })

    // 由于流水线会阻塞，所以这里存在问题！尤其是当ID阻塞时，IF也会阻塞，此时IF一直在发它的地址请求，
    // 而内存也一直在返回指令给IWU，导致IWU接收到错位的指令！
    // 已通过在IFU里加上“io.mem.inst_req_valid := io.out.fire && ready_go”解决。

    val br_flush = io.flush.br_taken
    val jump_flush = io.flush.jump_valid && !io.flush.br_taken  // br_taken是EXU的输出，jump_valid是IDU的输出，所以如果两者同时为true，则EXU的分支指令优先级更高（因为它更老）
    val flush = br_flush || jump_flush

    // val ready_go = !io.in.valid || flush || ...
    val ready_go = true.B
    io.in.ready := !reset.asBool && (!io.in.valid || ready_go && io.out.ready)
    io.out.valid := io.in.valid && ready_go && !flush

    io.out.bits.inst := io.mem.rinst
    io.out.bits.pc := io.in_bypass.pc
    io.out.bits.dnpc := io.in.bits.dnpc

    // trace（TODO：由于流水线阻塞的存在，iringbuf内现有函数可能会被多次调用，需要改！！）
    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.in_bypass.pc
    iringbuf.inst := io.mem.rinst
    iringbuf.before_ifetch := false.B
    iringbuf.after_ifetch := io.in.valid
}
