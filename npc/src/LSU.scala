package cpu

import chisel3._
import chisel3.util._

class LSU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new EXUOut))
        val out = Decoupled(new LSUOut)
        val mem = new Bundle {
            val data_req_valid = Output(Bool())
            val wen = Output(Bool())
            val raddr = Output(UInt(32.W))
            val waddr = Output(UInt(32.W))
            val wdata = Output(UInt(32.W))
            val wmask = Output(UInt(4.W))
            val rdata = Input(UInt(32.W))  // for load data
        }
    })

    val ready_go = true.B
    io.in.ready := !reset.asBool && (!io.in.valid || ready_go && io.out.ready)
    io.out.valid := io.in.valid && ready_go

    io.mem.data_req_valid := io.in.bits.rd_mem || io.in.bits.wr_mem
    io.mem.wen := io.in.bits.wr_mem
    io.mem.raddr := io.in.bits.result
    io.mem.waddr := io.in.bits.result
    io.mem.wdata := io.in.bits.reg_data2 << (io.mem.waddr(1, 0) << 3) // 这里要左移来对齐到正确的字节位置
    io.mem.wmask := MaskGen(io.in.bits.result, io.in.bits.bit_width)

    val loadData = ExtractLoadData(io.mem.rdata, io.mem.raddr, io.in.bits.bit_width, io.in.bits.sign)

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
