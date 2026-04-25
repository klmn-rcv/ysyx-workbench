package cpu

import chisel3._
import chisel3.util._

class LSU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new EXUOut))
        val out = Decoupled(new LSUOut)
        val mem = new Bundle {
            val ar = new AXI4LiteAR(32)
            val aw = new AXI4LiteAW(32)
            val w = new AXI4LiteW(32)
        }
    })

    val mem_access = io.in.bits.rd_mem || io.in.bits.wr_mem

    val valid = io.in.valid // && !flush  // 不能在LSU直接flush指令

    val need_flush_in_LSU = (!mem_access && false.B) && valid  // !mem_access是因为，如果是访存指令，我们认为它不能在LSU被flush，因为需要完成握手，并且还需要让它流到下一级（LSWU）去完成flush的动作；如果不是访存指令，可以直接flush。

    val ar_fire = io.mem.ar.arvalid && io.mem.ar.arready  // 不能接valid信号（虽然接不接不影响逻辑），因为一旦这里的握手成功，是不能忽略的，AR之后有R握手，AW/W之后有B握手，如果这里握手成功却忽略了，就会错位
    val aw_fire = io.mem.aw.awvalid && io.mem.aw.awready
    val w_fire = io.mem.w.wvalid && io.mem.w.wready

    val (ar_fire_preserved, ar_fire_after) = bool_preserve(ar_fire, io.out.fire, false.B) // 因为访存指令并不能在LSU被flush，所以这里clear_now参数不接flush
    val (aw_fire_preserved, aw_fire_after) = bool_preserve(aw_fire, io.out.fire, false.B)
    val (w_fire_preserved, w_fire_after) = bool_preserve(w_fire, io.out.fire, false.B)


    val ready_go = !mem_access || 
                   (io.in.bits.rd_mem && ar_fire_preserved) || 
                   (io.in.bits.wr_mem && aw_fire_preserved && w_fire_preserved)
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go   // io.out.valid不会放行非load/store指令流到下一级，但会放行被flush掉的load/store指令流到下一级，交给LSWU来彻底flush掉。


    io.mem.ar.arvalid := io.in.bits.rd_mem && valid && !ar_fire_after
    io.mem.ar.araddr := io.in.bits.result
    io.mem.aw.awvalid := io.in.bits.wr_mem && valid && !aw_fire_after
    io.mem.aw.awaddr := io.in.bits.result
    io.mem.w.wvalid := io.in.bits.wr_mem && valid && !w_fire_after
    io.mem.w.wdata := io.in.bits.rs2_data << (io.mem.aw.awaddr(1, 0) << 3) // 这里要左移来对齐到正确的字节位置
    io.mem.w.wstrb := MaskGen(io.in.bits.result, io.in.bits.bit_width)

    val need_flush_in_LSU_preserved = bool_preserve(need_flush_in_LSU, io.out.fire, false.B)._1
    io.out.bits.need_flush_in_LSU := need_flush_in_LSU_preserved    // 这条load/store指令是否在LSU阶段被flush掉了。注意仅在load/store指令时可能拉高。由于在LSU被flush掉的load/store指令仍需要在LSWU完成握手，所以需要流到LSWU再彻底flush掉。非load/store指令不需要这样，直接在LSU就能彻底flush。
    
    io.out.bits.raddr := io.in.bits.result         // 传给LSWU用来提取load得到的数据
    io.out.bits.bit_width := io.in.bits.bit_width  // 传给LSWU用来提取load得到的数据
    io.out.bits.sign := io.in.bits.sign            // 传给LSWU用来提取load得到的数据
    io.out.bits.rd_mem := io.in.bits.rd_mem        // 为了LSWU判断应该用什么数据（loadData还是ALU的结果）写回寄存器
    io.out.bits.wr_mem := io.in.bits.wr_mem        // 为了LSWU判断是否要发写数据请求（之后支持握手才需要实现这一点）
    io.out.bits.result := io.in.bits.result        // 如果不是访存指令，需要写回ALU的结果
    io.out.bits.wr_reg := io.in.bits.wr_reg
    io.out.bits.rd := io.in.bits.rd
    io.out.bits.ebreak := io.in.bits.ebreak
    io.out.bits.inv := io.in.bits.inv

    io.out.bits.inst := io.in.bits.inst
    io.out.bits.pc := io.in.bits.pc
    io.out.bits.dnpc := io.in.bits.dnpc
    io.out.bits.csrReq := io.in.bits.csrReq
    io.out.bits.ecall := io.in.bits.ecall
    io.out.bits.mret := io.in.bits.mret
}
