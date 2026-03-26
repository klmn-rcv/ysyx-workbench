package cpu

import chisel3._
import chisel3.util._

class Halt extends ExtModule {
    val ebreak = IO(Input(Bool()))
    addResource("/Halt.sv")
}
