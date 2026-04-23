package cpu

import chisel3._
import chisel3.util._

class LSAU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new EXUOut))
        val out = Decoupled(new LSAUOut)
        val mem = new Bundle {
            val data_req_valid = Output(Bool())
            val data_req_ready = Input(Bool())
            val wen = Output(Bool())
            val raddr = Output(UInt(32.W))
            val waddr = Output(UInt(32.W))
            val wdata = Output(UInt(32.W))
            val wmask = Output(UInt(4.W))
            // val rdata = Input(UInt(32.W))  // for load data
        }
    })

    val flush = false.B  // 这里需要实现！异常会冲刷！
    val mem_access = io.in.bits.rd_mem || io.in.bits.wr_mem
    val data_req_fire = io.mem.data_req_valid && io.mem.data_req_ready
    val data_req_fire_preserved = bool_preserve(data_req_fire, io.out.fire, false.B)

    val valid = io.in.valid && !flush   // 这里的flush也需要持久化
    val ready_go = !mem_access || data_req_fire_preserved
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go
    
    io.mem.data_req_valid := mem_access && valid && io.out.ready  // 这里的io.out.ready也是暂时的权衡，这会导致LSA在LSD没收到数据之前不会发新请求，影响性能
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
    io.out.bits.wr_mem := io.in.bits.wr_mem        // 为了LSDU判断是否要发写数据请求（之后支持握手才需要实现这一点）
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
