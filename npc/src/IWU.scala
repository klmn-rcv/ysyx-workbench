package cpu

import chisel3._
import chisel3.util._

class IWU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new IFUOut))  // IFUOut暂时没信号
        // val in_bypass = new Bundle {
        //     val pc = Input(UInt(32.W)) // 由于pc（实际上是此时IW流水级中的指令的pc）需要在IFU中使用，所以不能直接放在IFUOut中
        //     val dnpc = Input(UInt(32.W))
        // }
        val out = Decoupled(new IWUOut)
        val mem = new Bundle {
            val r = new AXI4LiteR(32)
            val b = new AXI4LiteB  // 输出全置0
        }
        val flush = new Bundle {
            val br_taken = Input(Bool())
            val jump_valid = Input(Bool())
            val ex_found = Input(Bool())  // 来自IDU的信号，需要当作flush处理
            // val flush = Output(Bool())
        }
    })

    // 由于流水线会阻塞，所以这里存在问题！尤其是当ID阻塞时，IF也会阻塞，此时IF一直在发它的地址请求，
    // 而内存也一直在返回指令给IWU，导致IWU接收到错位的指令！
    // 已通过在IFU里加上“io.mem.inst_req_valid := io.out.fire && ready_go”解决。

    assert(!io.mem.r.rvalid || io.mem.r.rresp === AXI4Resp.OKAY)

    val r_fire = io.mem.r.rvalid && io.mem.r.rready // && !io.in.bits.need_flush_in_IF
                // !io.in.bits.need_flush_in_IF不能写在这里，是因为这样会导致r_fire永远为0，从而ready_go也永远为0，让这条指令永远卡死在IWU。
                // 至于为什么不把io.in.bits.need_flush_in_IF直接接给flush信号或valid信号，是因为这样会导致IWU内容提前无效，IFU的内容可能在IWU这条指令剩下的握手流程完成之前流过来，导致接收到错位指令。
                // r_fire信号也不能接valid信号（虽然接不接不影响逻辑），因为现在不允许在内容无效的时候假握手了，原因是IFU随时可能流过来，导致错位
    val (r_fire_preserved, inst_preserved, r_fire_after, _) = valid_and_data_preserve(r_fire, io.mem.r.rdata, io.out.fire, false.B)

    val valid = io.in.valid // && !flush  // IW也不能直接flush，也必须要先完成握手。如果像之前那样，flush来了直接当成无效，在无效的时候rready始终拉高但丢掉取到的指令，是不行的，因为现在IF随时可能流到IW，如果IW无效但还没走完形式上的握手流程，IF就流过来了，这时就会接收到错位指令
                                          // 解决方法是使用need_flush_in_or_before_IW接口，让在IF和IW本应当被flush掉的指令在进入ID的同时被真正flush
    // val ready_go = !valid || flush || ...，在现在的语义框架下是错误的，
    // 因为!valid和flush都是“没有有效指令”，既然没有有效指令，怎么会完成了本级任务呢？
    // 而且io.out.valid := valid && ready_go，也就是说无效的信号我们是不会让它流向下一级的，所以更不应该在!valid的时候把ready_go拉高了。
    // 还有一个细节：!valid || flush本身就是冗余的，等价于单独一个!valid，因为flush为1时，!valid必为1，所以只要一个!valid就能涵盖flush的情况了。
    val ready_go = r_fire_preserved
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    val br_flush = io.flush.br_taken
    val jump_flush = io.flush.jump_valid && !io.flush.br_taken  // br_taken是EXU的输出，jump_valid是IDU的输出，所以如果两者同时为true，则EXU的分支指令优先级更高（因为它更老）
    val ex_flush = io.flush.ex_found && !io.flush.br_taken  // br_taken是EXU的输出，ex_found是IDU的输出，所以如果两者同时为true，则EXU的分支指令优先级更高（因为它更老）
    val need_flush_in_IW = (br_flush || jump_flush || ex_flush) && valid
    val need_flush_in_IW_preserved = bool_preserve(need_flush_in_IW, io.out.fire, false.B)._1
    // io.flush.flush := false.B // 这里不能接need_flush_in_IW，否则io.in.valid就会在下一拍被无效掉，导致之前在val valid信号定义处那个注释提到的问题。因此这里io.flush.flush必须是false.B。


    io.mem.r.rready := valid && !r_fire_after // 不管在什么情况下io.out.fire，下一拍inst_resp_ready都为1，不会有性能损失
                                              // 之前在!valid的时候置rready为1，这在现在的设计中是不好的，因为既然现在IW不会真正flush指令，那valid为0只可能是IW流走，而IF还没流过来，此时如果IF的AR握手成功但继续卡在IF（虽然好像暂时不可能出现这种情况），就会导致IW假握手并丢掉这条实际上不该丢的指令

    io.out.bits.need_flush_in_IF_or_IW := io.in.bits.need_flush_in_IF || need_flush_in_IW_preserved // 这条在IF/IW就应当被flush掉的指令，为了完成握手，必须等到进入ID的同时flush
    io.out.bits.inst := inst_preserved
    io.out.bits.pc := io.in.bits.pc
    io.out.bits.dnpc := io.in.bits.dnpc

    // B通道输出全置0
    io.mem.b.bready := false.B

    // itrace(iringbuf)
    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.in.bits.pc
    iringbuf.inst := io.mem.r.rdata
    iringbuf.before_ifetch := false.B
    iringbuf.after_ifetch := io.out.fire && !io.out.bits.need_flush_in_IF_or_IW // 不能用!need_flush_in_IW_preserved，因为如果是IF阶段被flush掉了，那么need_flush_in_IW_preserved是0，但这条指令在IF阶段就没有填入iringbuf，所以这里也不应该after_ifetch
    iringbuf.flush_after_ifetch := io.out.fire && need_flush_in_IW_preserved  // 不能用!io.out.bits.need_flush_in_IF_or_IW，因为对于IF阶段就被flush掉的指令，它在IF阶段就没有填入iringbuf，所里这里不应该对它的iringbuf项进行flush
}
