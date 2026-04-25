package cpu

import chisel3._
import chisel3.util._

class IFU extends Module {
    val io = IO(new Bundle {
        val out = Decoupled(new IFUOut)
        // val out_bypass = new Bundle {
        //     val pc = Output(UInt(32.W)) // 由于pc（实际上是此时IW流水级中的指令的pc）需要在IFU中使用，所以不能直接放在IFUOut中
        //     val dnpc = Output(UInt(32.W))
        // }
        val ctrl = new Bundle {
            val ex_redirect_valid = Input(Bool())
            val ex_redirect_target = Input(UInt(32.W))
            val jump_valid = Input(Bool())
            val jump_target = Input(UInt(32.W))
            val br_taken = Input(Bool())
            val br_target = Input(UInt(32.W))
            val ex_found = Input(Bool()) // 来自IDU的信号，抑制IFU的取指
        }
        val mem = new Bundle {
            val ar = new AXI4LiteAR(32)
            val aw = new AXI4LiteAW(32) // 输出全置0
            val w = new AXI4LiteW(32)   // 输出全置0
        }
    })

    // val sent_to_bus = boolreg_set_clear(io.mem.ar.arvalid && !ar_fire_preserved, io.out.fire)


    val ar_fire = io.mem.ar.arvalid && io.mem.ar.arready
    val (ar_fire_preserved, ar_fire_after) = bool_preserve(ar_fire, io.out.fire, false.B)

    val valid = !reset.asBool
    val ready_go = ar_fire_preserved
    io.out.valid := valid && ready_go

    val (jump_valid_preserved, jump_target_preserved, _, _)               = valid_and_data_preserve(io.ctrl.jump_valid, io.ctrl.jump_target, io.out.fire, false.B)
    val (br_taken_preserved, br_target_preserved, _, _)                   = valid_and_data_preserve(io.ctrl.br_taken, io.ctrl.br_target, io.out.fire, false.B)
    val (ex_redirect_valid_preserved, ex_redirect_target_preserved, _, _) = valid_and_data_preserve(io.ctrl.ex_redirect_valid, io.ctrl.ex_redirect_target, io.out.fire, false.B)

    val ex_found_preserved = bool_preserve(io.ctrl.ex_found, false.B, io.ctrl.ex_redirect_valid)._1 // 这个保持信号和其他的不同，不会在io.out.fire的时候被清除，而是会一直保持到ex_redirect_valid为1的时候才被清除，因为只要ex_found为1，就说明发现了异常，这时应该“禁止”IFU继续取指。
                                                                // 但“禁止”取指不是禁止IFU继续发AR请求，而是flush掉它取来的所有指令，方法和其他redirect一样，利用flush_preserved这个信号。不直接禁止取指请求的原因是，必须允许ex_found拉高时的AR请求完成握手，不能立刻拉低arvalid，所以拉低arvalid的时机不好掌握，不如复用flush_preserved这个机制。

    val need_flush_in_IF_preserved = jump_valid_preserved || br_taken_preserved || ex_redirect_valid_preserved || ex_found_preserved

    val dnpc = Wire(UInt(32.W))
    val pc = RegEnable(dnpc, "h80000000".U(32.W), io.out.fire)
    val snpc = pc + 4.U
    dnpc := Mux(ex_redirect_valid_preserved, ex_redirect_target_preserved,
               Mux(br_taken_preserved, br_target_preserved,
               Mux(jump_valid_preserved, jump_target_preserved, snpc)))
    // io.out_bypass.pc := RegEnable(dnpc, "h7ffffffc".U(32.W), io.out.fire)
    // io.out_bypass.dnpc := dnpc    // 取指访存发送给内存的地址

    io.mem.ar.arvalid := valid && !ar_fire_after // valid && io.out.ready && !forbid_ifetch
                                                 // 改成AXI后，原本的io.out.ready就不行了，因为它可能先有效后无效，导致arvalid在握手成功之前先有效后无效，这是AXI不允许的行为，AXI的valid信号必须在握手成功之前一直保持有效
                                                 // forbid_ifetch：异常从被检测到，到WB阶段触发，期间禁止取指令
                                                 // forbid_ifetch也不能用在这里了，原因和io.out.ready差不多。但它现在仍然有用，ex_found_preserved就是等价的信号
    io.mem.ar.araddr := pc  // 用寄存器里的pc取指，不用组合信号dnpc了，这样取指地址就不会变了，否则取指地址会变，不符合AXI标准

    io.out.bits.pc := pc
    io.out.bits.dnpc := dnpc  // 其实这里等价于填snpc，因为一旦被redirect了，这条指令也就无效了
    io.out.bits.need_flush_in_IF := need_flush_in_IF_preserved // 这条指令是否在IF阶段被flush掉了。由于在IF被flush掉的指令仍需要在IW完成握手，所以需要流到ID再彻底flush掉，而不像正常情况下一旦被flush就不会流到下个阶段了

    // AW和W通道输出全置0
    io.mem.aw.awvalid := false.B
    io.mem.aw.awaddr := 0.U
    io.mem.w.wvalid := false.B
    io.mem.w.wdata := 0.U
    io.mem.w.wstrb := 0.U

    // itrace(iringbuf)
    val iringbuf = Module(new Iringbuf)
    iringbuf.clk := clock
    iringbuf.rst := reset
    iringbuf.pc := io.out.bits.pc
    iringbuf.inst := 0.U(32.W)
    iringbuf.before_ifetch := io.out.fire && !need_flush_in_IF_preserved
    iringbuf.after_ifetch := false.B
    iringbuf.flush_after_ifetch := false.B
}
