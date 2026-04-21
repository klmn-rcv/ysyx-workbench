package cpu

import chisel3._
import chisel3.util._

class LSDU extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new LSAUOut))
        val out = Decoupled(new LSDUOut)
        val mem = new Bundle {
            val data_resp_valid = Input(Bool())
            val data_resp_ready = Output(Bool())
            // val wdata = Output(UInt(32.W))
            // val wmask = Output(UInt(4.W))
            val rdata = Input(UInt(32.W))  // for load data
        }
    })

    val flush = false.B  // 这里需要实现！异常会冲刷！
    val data_resp_fire = Wire(Bool())
    val data_resp_fire_preserved = Wire(Bool())
    val load_data_preserved = Wire(UInt(32.W))

    // val data_resp_valid_preserved = Wire(Bool())
    
    val mem_access = io.in.bits.rd_mem || io.in.bits.wr_mem

    val valid = io.in.valid && !flush   // 这里的flush也需要持久化
    val ready_go = !mem_access || data_resp_fire_preserved    // 后续需要改成握手成功
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    val load_data = ExtractLoadData(io.mem.rdata, io.in.bits.raddr, io.in.bits.bit_width, io.in.bits.sign)

    data_resp_fire := io.mem.data_resp_valid && io.mem.data_resp_ready && valid // 在内容无效（被flush掉）的时候不认为握手成功，以丢掉取到的指令，但要置data_resp_ready为1，让内存以为握手成功
    val preserved_tuple = valid_and_data_preserve(data_resp_fire, load_data, io.out.fire, flush) // 在flush的时候立刻把data_resp_fire_reg置为0（注意不是把data_resp_fire_preserved置为0！），这里的立刻是异步的意思
    data_resp_fire_preserved := preserved_tuple._1
    load_data_preserved := preserved_tuple._2
    val data_resp_fire_after = data_resp_fire_preserved && !data_resp_fire  // 握手成功之后
    io.mem.data_resp_ready := !valid || !data_resp_fire_after // 不考虑flush的话，这里的逻辑应该不用改进了（不考虑flush，不管在什么情况下io.out.fire，下一拍data_resp_ready都为1，不会有性能损失）
                                                              // 在!valid的时候置data_resp_ready为1是考虑如果有flush，IW无效，需要让内存以为能握手（不然内存会一直等），但实际上IW会把这条取到的指令丢掉
    

    // when(valid && !io.out.fire && io.in.bits.rd_mem && io.mem.data_resp_valid) {
    //     data_resp_valid_reg := true.B
    //     load_data_reg := load_data
    // }.elsewhen(io.out.fire) {
    //     data_resp_valid_reg := false.B
    //     load_data_reg := 0.U
    // }
    // data_resp_valid_preserved := io.mem.data_resp_valid || data_resp_valid_reg

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
