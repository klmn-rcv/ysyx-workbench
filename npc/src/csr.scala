package cpu

import chisel3._
import chisel3.util._

class CSR extends Module {
  val io = IO(new Bundle {
    val in = new Bundle {
      val addr = Input(UInt(12.W))  // CSR地址空间为12位，但实际使用的CSR数量远小于2^12，因此CSR模块内部可以使用查找表的方式来匹配CSR地址
      val we = Input(Bool())
      val wmask = Input(UInt(32.W))
      val wvalue = Input(UInt(32.W))
    }
    val out = new Bundle {
      val rvalue = Output(UInt(32.W))
    }
  })

  val mcycle = RegInit(0.U(32.W))
  val mcycleh = RegInit(0.U(32.W))
  val mvendorid = RegInit("h79737978".U(32.W))  // "ysyx"的ASCII码
  val marchid = RegInit("hC0F18E2".U(32.W))  // 202316002，是我学号的一部分（2023K8009916002）

  val csrTable = Seq(
    // CSRAddr.mstatus.U(12.W) -> mstatus,
    // CSRAddr.mtvec.U(12.W)   -> mtvec,
    // CSRAddr.mepc.U(12.W)    -> mepc,
    // CSRAddr.mcause.U(12.W)  -> mcause,
    CSRAddr.mcycle.U(12.W)  -> mcycle,
    CSRAddr.mcycleh.U(12.W) -> mcycleh,
    CSRAddr.mvendorid.U(12.W) -> mvendorid,
    CSRAddr.marchid.U(12.W) -> marchid,
  )

  val hits = csrTable.map { case (addr, _) => io.in.addr === addr }
  io.out.rvalue := Mux1H(hits, csrTable.map(_._2))

  for(((_, reg), hit) <- csrTable.zip(hits)) {
    when(io.in.we && hit) {
      reg := (reg & ~io.in.wmask) | (io.in.wvalue & io.in.wmask)
    }
  }

}
