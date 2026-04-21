package cpu

import chisel3._
import chisel3.util._

class LSDU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new LSAUOut))
        val out = Decoupled(new LSDUOut)
        val mem = new Bundle {
            val data_resp_valid = Input(Bool())
            // val wdata = Output(UInt(32.W))
            // val wmask = Output(UInt(4.W))
            val rdata = Input(UInt(32.W))  // for load data
        }
    })

    val data_resp_valid_preserved = Wire(Bool())
    val load_data_preserved = Wire(UInt(32.W))
    
    val mem_access = io.in.bits.rd_mem || io.in.bits.wr_mem

    val valid = io.in.valid // && !flush   // 这里的flush也需要持久化
    val ready_go = !mem_access || data_resp_valid_preserved    // 后续需要改成握手成功
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    val load_data = ExtractLoadData(io.mem.rdata, io.in.bits.raddr, io.in.bits.bit_width, io.in.bits.sign)

    // when(valid && !io.out.fire && io.in.bits.rd_mem && io.mem.data_resp_valid) {
    //     data_resp_valid_reg := true.B
    //     load_data_reg := load_data
    // }.elsewhen(io.out.fire) {
    //     data_resp_valid_reg := false.B
    //     load_data_reg := 0.U
    // }
    // data_resp_valid_preserved := io.mem.data_resp_valid || data_resp_valid_reg

    val data_clear = io.out.fire
    val data_set = valid && !io.out.fire && io.in.bits.rd_mem && io.mem.data_resp_valid
    val preserved_tuple = valid_and_data_preserve(io.mem.data_resp_valid, load_data, data_clear, data_set)
    data_resp_valid_preserved := preserved_tuple._1
    load_data_preserved := preserved_tuple._2

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
