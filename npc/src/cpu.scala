package cpu

import chisel3._
import chisel3.util._

class CPU extends Module {
    val io = IO(new Bundle {
        val in = new Bundle {
            val mem_rinst = Input(UInt(32.W))
            val mem_rdata = Input(UInt(32.W))
        }
        val out = new Bundle {
            val pc = Output(UInt(32.W))
            val mem_inst_req_valid = Output(Bool())
            val mem_data_req_valid = Output(Bool())
            val mem_wen = Output(Bool())
            val mem_inst_pc = Output(UInt(32.W))
            val mem_raddr = Output(UInt(32.W))
            val mem_waddr = Output(UInt(32.W))
            val mem_wdata = Output(UInt(32.W))
            val mem_wmask = Output(UInt(4.W))
        }
    })

    val ifu = Module(new IFU)
    val idu = Module(new IDU)
    val exu = Module(new EXU)
    val lsu = Module(new LSU)
    val wbu = Module(new WBU)
    val regfile = Module(new regfile)

    // IF stage
    ifu.io.in.bj_valid := idu.io.out.bj_valid
    ifu.io.in.bj_pc := idu.io.out.bj_pc
    idu.io.in.pc := ifu.io.out.pc
    io.out.pc := ifu.io.out.next_pc

    // Current CPU only issues instruction fetches through memory interface.
    io.out.mem_inst_req_valid := true.B
    io.out.mem_data_req_valid := lsu.io.out.mem_data_req_valid
    io.out.mem_wen := lsu.io.out.mem_wen
    io.out.mem_inst_pc := ifu.io.out.next_pc
    io.out.mem_raddr := lsu.io.out.raddr
    io.out.mem_waddr := lsu.io.out.waddr
    io.out.mem_wdata := lsu.io.out.wdata
    io.out.mem_wmask := lsu.io.out.wmask

    // ID stage
    idu.io.in.inst := io.in.mem_rinst
    regfile.io.in.raddr1 := idu.io.out.rs1     // truncate
    regfile.io.in.raddr2 := idu.io.out.rs2     // truncate

    idu.io.in.rdata1 := regfile.io.out.rdata1
    idu.io.in.rdata2 := regfile.io.out.rdata2

    // EX stage
    exu.io.in.src1 := idu.io.out.src1
    exu.io.in.src2 := idu.io.out.src2
    exu.io.in.alu_op := idu.io.out.alu_op
    exu.io.in.wr_reg := idu.io.out.wr_reg
    exu.io.in.rd := idu.io.out.rd
    exu.io.in.rd_mem := idu.io.out.rd_mem
    exu.io.in.wr_mem := idu.io.out.wr_mem
    exu.io.in.bit_width := idu.io.out.bit_width
    exu.io.in.sign := idu.io.out.sign
    exu.io.in.ebreak := idu.io.out.ebreak

    // LSU stage
    lsu.io.in.alu_data := exu.io.out.result
    lsu.io.in.src2 := exu.io.out.src2
    lsu.io.in.wr_reg := exu.io.out.wr_reg
    lsu.io.in.rd := exu.io.out.rd
    lsu.io.in.rd_mem := exu.io.out.rd_mem
    lsu.io.in.wr_mem := exu.io.out.wr_mem
    lsu.io.in.bit_width := exu.io.out.bit_width
    lsu.io.in.sign := exu.io.out.sign
    lsu.io.in.rdata := io.in.mem_rdata
    lsu.io.in.ebreak := exu.io.out.ebreak

    // WB stage
    wbu.io.in.data := lsu.io.out.data
    wbu.io.in.rd := lsu.io.out.rd
    wbu.io.in.wr_reg := lsu.io.out.wr_reg
    wbu.io.in.ebreak := lsu.io.out.ebreak

    regfile.io.in.we := wbu.io.out.wb_we
    regfile.io.in.waddr := wbu.io.out.wb_addr  // truncate
    regfile.io.in.wdata := wbu.io.out.wb_data
}
