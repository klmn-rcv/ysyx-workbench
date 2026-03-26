package cpu

import chisel3._
import chisel3.util._

class LSU extends Module {
    val io = IO(new Bundle {
        // For now addi/jalr do not access memory, but this stage is kept for extension.
        val in_data = Input(UInt(32.W))
        val out_data = Output(UInt(32.W))

        val ebreak_in = Input(Bool())
        val ebreak_out = Output(Bool())
    })

    io.out_data := io.in_data

    io.ebreak_out := io.ebreak_in
}
