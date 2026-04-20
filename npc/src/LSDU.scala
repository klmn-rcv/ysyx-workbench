package cpu

import chisel3._
import chisel3.util._

class LSDU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new LSAUOut))
        val out = Decoupled(new LSDUOut)
        val mem = new Bundle {
            // val wdata = Output(UInt(32.W))
            // val wmask = Output(UInt(4.W))
            val rdata = Input(UInt(32.W))  // for load data
        }
    })

    val valid = io.in.valid // && !flush   // 这里的flush也需要持久化
    val ready_go = true.B   // 目前的内存收到地址的下一周期就能返回数据，所以LSDU可以一直收到数据
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    val loadData = ExtractLoadData(io.mem.rdata, io.in.bits.raddr, io.in.bits.bit_width, io.in.bits.sign)
    io.out.bits.data := Mux(io.in.bits.rd_mem, loadData, io.in.bits.result)

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
