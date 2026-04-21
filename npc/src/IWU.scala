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
            val inst_resp_valid = Input(Bool())
            val inst_resp_ready = Output(Bool())
            val rinst = Input(UInt(32.W))
        }
        val flush = new Bundle {
            val br_taken = Input(Bool())
            val jump_valid = Input(Bool())
            val flush = Output(Bool())
        }
    })

    // 由于流水线会阻塞，所以这里存在问题！尤其是当ID阻塞时，IF也会阻塞，此时IF一直在发它的地址请求，
    // 而内存也一直在返回指令给IWU，导致IWU接收到错位的指令！
    // 已通过在IFU里加上“io.mem.inst_req_valid := io.out.fire && ready_go”解决。

    val flush = Wire(Bool())
    // val inst_resp_valid_preserved = Wire(Bool())
    val inst_resp_fire = Wire(Bool())
    val inst_resp_fire_preserved = Wire(Bool())
    val inst_preserved = Wire(UInt(32.W))

    val valid = io.in.valid && !flush
    // val ready_go = !valid || flush || ...，在现在的语义框架下是错误的，
    // 因为!valid和flush都是“没有有效指令”，既然没有有效指令，怎么会完成了本级任务呢？
    // 而且io.out.valid := valid && ready_go，也就是说无效的信号我们是不会让它流向下一级的，所以更不应该在!valid的时候把ready_go拉高了。
    // 还有一个细节：!valid || flush本身就是冗余的，等价于单独一个!valid，因为flush为1时，!valid必为1，所以只要一个!valid就能涵盖flush的情况了。
    val ready_go = inst_resp_fire_preserved
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    val br_flush = io.flush.br_taken
    val jump_flush = io.flush.jump_valid && !io.flush.br_taken  // br_taken是EXU的输出，jump_valid是IDU的输出，所以如果两者同时为true，则EXU的分支指令优先级更高（因为它更老）
    flush := br_flush || jump_flush
    io.flush.flush := flush

    inst_resp_fire := io.mem.inst_resp_valid && io.mem.inst_resp_ready && valid // 在内容无效（被flush掉）的时候不认为握手成功，以丢掉取到的指令，但要置inst_resp_ready为1，让内存以为握手成功
    val preserved_tuple = valid_and_data_preserve(inst_resp_fire, io.mem.rinst, io.out.fire, flush) // 在flush的时候立刻把inst_resp_fire_reg置为0（注意不是把inst_resp_fire_preserved置为0！），这里的立刻是异步的意思
    inst_resp_fire_preserved := preserved_tuple._1
    inst_preserved := preserved_tuple._2
    val inst_resp_fire_after = preserved_tuple._3  // 握手成功之后
    io.mem.inst_resp_ready := !valid || !inst_resp_fire_after // 不考虑flush的话，这里的逻辑应该不用改进了（不考虑flush，不管在什么情况下io.out.fire，下一拍inst_resp_ready都为1，不会有性能损失）
                                                              // 在!valid的时候置inst_resp_ready为1是考虑如果有flush，IW无效，需要让内存以为能握手（不然内存会一直等），但实际上IW会把这条取到的指令丢掉

    io.out.bits.inst := inst_preserved
    io.out.bits.pc := io.in_bypass.pc
    io.out.bits.dnpc := io.in.bits.dnpc

    // trace（TODO：由于流水线阻塞的存在，iringbuf内现有函数可能会被多次调用，需要改！！）
    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.in_bypass.pc
    iringbuf.inst := io.mem.rinst
    iringbuf.before_ifetch := false.B
    iringbuf.after_ifetch := io.out.fire
}
