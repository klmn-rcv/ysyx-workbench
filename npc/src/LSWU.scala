package cpu

import chisel3._
import chisel3.util._

class LSWU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new LSUOut))
        val out = Decoupled(new LSWUOut)
        val mem = new Bundle {
            val r = new AXI4LiteR(32)
            val b = new AXI4LiteB
        }
    })

    assert(!io.mem.r.rvalid || io.mem.r.rresp === AXI4Resp.OKAY)
    assert(!io.mem.b.bvalid || io.mem.b.bresp === AXI4Resp.OKAY)

    val mem_access = io.in.bits.rd_mem || io.in.bits.wr_mem

    val valid = io.in.valid // && !flush  // 不能在LSWU直接flush指令

    val need_flush_in_LSWU = (!mem_access && false.B) && valid  // !mem_access是因为，如果是访存指令，我们认为它不能在LSWU被flush，因为需要完成握手，并且还需要让它流到下一级（LSWU）去完成flush的动作；如果不是访存指令，可以直接flush。

    val load_data = Wire(UInt(32.W))
    val r_fire = io.mem.r.rvalid && io.mem.r.rready  // 对于非load指令，r_fire永远为0（因为rready为0）
    val b_fire = io.mem.b.bvalid && io.mem.b.bready  // 对于非store指令，b_fire永远为0（因为bready为0）
                // 上面两个fire信号都不能接valid信号（虽然接不接不影响逻辑），因为现在不允许在内容无效的时候假握手了，原因是LSU随时可能流过来，导致错位
    val (r_fire_preserved, load_data_preserved, r_fire_after, _) = valid_and_data_preserve(r_fire, load_data, io.out.fire, false.B) // 在flush的时候立刻把r_fire_reg置为0（注意不是把r_fire_preserved置为0！），这里的立刻是异步的意思
    val (b_fire_preserved, b_fire_after) = bool_preserve(b_fire, io.out.fire, false.B)

    val ready_go = !mem_access ||
                   (io.in.bits.rd_mem && r_fire_preserved) ||  
                   (io.in.bits.wr_mem && b_fire_preserved) 
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    load_data := ExtractLoadData(io.mem.r.rdata, io.in.bits.raddr, io.in.bits.bit_width, io.in.bits.sign)

    io.mem.r.rready := valid && io.in.bits.rd_mem && !r_fire_after
    io.mem.b.bready := valid && io.in.bits.wr_mem && !b_fire_after

    val need_flush_in_LSWU_preserved = bool_preserve(need_flush_in_LSWU, io.out.fire, false.B)._1
    io.out.bits.need_flush_in_LSU_or_LSWU := io.in.bits.need_flush_in_LSU || need_flush_in_LSWU_preserved

    io.out.bits.data := Mux(io.in.bits.rd_mem, load_data_preserved, io.in.bits.result)

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
