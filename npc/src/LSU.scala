package cpu

import chisel3._
import chisel3.util._

class LSU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val alu_data = Input(UInt(32.W))
            val reg_data2 = Input(UInt(32.W))  // for store data
            val wr_reg = Input(Bool())
            val rd = Input(UInt(5.W))
            val rd_mem = Input(Bool())
            val wr_mem = Input(Bool())
            val bit_width = Input(BitWidth())
            val sign = Input(Sign())
            val rdata = Input(UInt(32.W))  // for load data
            val ebreak = Input(Bool())
        }
        val out = new Bundle {
            val mem_data_req_valid = Output(Bool())
            val mem_wen = Output(Bool())
            val raddr = Output(UInt(32.W))
            val waddr = Output(UInt(32.W))
            val wdata = Output(UInt(32.W))
            val wmask = Output(UInt(4.W))

            val data = Output(UInt(32.W))
            val wr_reg = Output(Bool())
            val rd = Output(UInt(5.W))
            val ebreak = Output(Bool())
        }
    })

    io.out.mem_data_req_valid := io.in.rd_mem || io.in.wr_mem
    io.out.mem_wen := io.in.wr_mem
    io.out.raddr := io.in.alu_data
    io.out.waddr := io.in.alu_data
    io.out.wdata := io.in.reg_data2 << (io.out.waddr(1, 0) << 3) // 这里要左移来对齐到正确的字节位置
    io.out.wmask := MaskGen(io.in.alu_data, io.in.bit_width)

    val loadData = ExtractLoadData(io.in.rdata, io.out.raddr, io.in.bit_width, io.in.sign)

    io.out.data := Mux(io.in.rd_mem, loadData, io.in.alu_data)
    io.out.wr_reg := io.in.wr_reg
    io.out.rd := io.in.rd
    io.out.ebreak := io.in.ebreak
}
