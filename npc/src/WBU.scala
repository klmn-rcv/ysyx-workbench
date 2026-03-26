package cpu

import chisel3._
import chisel3.util._

class WBU extends Module {
    val io = IO(new Bundle {
        // val func_type = Input(FuncType())
        val in_data = Input(UInt(32.W))

        val in_rd = Input(UInt(5.W))
        val wr_reg = Input(Bool())

        val wb_data = Output(UInt(32.W))
        val wb_we = Output(Bool())
        val wb_addr = Output(UInt(5.W))
    })

    // jump writes link value (pc+4); arithmetic writes ALU result.
    io.wb_data := io.in_data
    io.wb_we := io.wr_reg
    io.wb_addr := io.in_rd
}
