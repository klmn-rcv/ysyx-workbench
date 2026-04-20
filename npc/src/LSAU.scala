package cpu

import chisel3._
import chisel3.util._

class LSAU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new EXUOut))
        val out = Decoupled(new LSAUOut)
        val mem = new Bundle {
            val data_req_valid = Output(Bool())
            val wen = Output(Bool())
            val raddr = Output(UInt(32.W))
            val waddr = Output(UInt(32.W))
            val wdata = Output(UInt(32.W))
            val wmask = Output(UInt(4.W))
            // val rdata = Input(UInt(32.W))  // for load data
        }
    })

    val ready_go = true.B   // 目前的内存收到地址的下一周期就能返回数据，所以LSAU可以一直发地址请求
    io.in.ready := !reset.asBool && (!io.in.valid || ready_go && io.out.ready)
    io.out.valid := io.in.valid && ready_go

    io.mem.data_req_valid := io.in.bits.rd_mem || io.in.bits.wr_mem
    io.mem.wen := io.in.bits.wr_mem
    io.mem.raddr := io.in.bits.result
    io.mem.waddr := io.in.bits.result
    io.mem.wdata := io.in.bits.rs2_data << (io.mem.waddr(1, 0) << 3) // 这里要左移来对齐到正确的字节位置
    io.mem.wmask := MaskGen(io.in.bits.result, io.in.bits.bit_width)

    // val loadData = ExtractLoadData(io.mem.rdata, io.mem.raddr, io.in.bits.bit_width, io.in.bits.sign)

    // io.out.bits.wr_data := io.in.bits.rs2_data  // 目前写地址和写数据请求还未分离，还不需要把写数据传到LSDU，而是直接在ISU中就能写入内存
    io.out.bits.raddr := io.in.bits.result         // 传给LSDU用来提取load得到的数据
    io.out.bits.bit_width := io.in.bits.bit_width  // 传给LSDU用来提取load得到的数据
    io.out.bits.sign := io.in.bits.sign            // 传给LSDU用来提取load得到的数据
    io.out.bits.rd_mem := io.in.bits.rd_mem        // 为了LSDU判断应该用什么数据（loadData还是ALU的结果）写回寄存器
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
