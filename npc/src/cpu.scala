package cpu

import chisel3._
import chisel3.util._

class CPU extends Module {
    val io = IO(new Bundle {
        val inst = Input(UInt(32.W))
        val pc = Output(UInt(32.W))
        // val st_valid = Output(Bool())
        // val st_data = Output(UInt(32.W))
    })

    val ifu = Module(new IFU)
    val idu = Module(new IDU)
    val exu = Module(new EXU)
    val lsu = Module(new LSU)
    val wbu = Module(new WBU)
    val regfile = Module(new regfile)

    // IF stage
    ifu.io.bj_valid := idu.io.bj_valid
    ifu.io.bj_pc := idu.io.bj_pc
    idu.io.pc := ifu.io.pc
    io.pc := ifu.io.next_pc

    // ID stage
    idu.io.inst := io.inst
    regfile.io.raddr1 := idu.io.rs1     // truncate
    regfile.io.raddr2 := idu.io.rs2     // truncate

    idu.io.rdata1 := regfile.io.rdata1
    idu.io.rdata2 := regfile.io.rdata2

    // EX stage
    exu.io.src1 := idu.io.src1
    exu.io.src2 := idu.io.src2
    exu.io.alu_op := idu.io.alu_op
    exu.io.ebreak_in := idu.io.ebreak_out

    // LSU stage
    lsu.io.in_data := exu.io.result
    lsu.io.ebreak_in := exu.io.ebreak_out

    // WB stage
    wbu.io.in_data := lsu.io.out_data
    wbu.io.in_rd := idu.io.rd
    wbu.io.wr_reg := idu.io.wr_reg
    wbu.io.ebreak_in := lsu.io.ebreak_out

    regfile.io.we := wbu.io.wr_reg
    regfile.io.waddr := wbu.io.wb_addr  // truncate
    regfile.io.wdata := wbu.io.wb_data
}
