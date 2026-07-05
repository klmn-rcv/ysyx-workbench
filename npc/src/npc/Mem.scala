package cpu.npc

import chisel3._
import cpu._

class Mem extends ExtModule {
    val clk = IO(Input(Clock()))
    val rst = IO(Input(Bool()))
    val axi = IO(Flipped(new AXI4(32, 32, 4)))

    addResource("/npc/Mem.sv")
}
