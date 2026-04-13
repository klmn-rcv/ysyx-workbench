package cpu

import chisel3._
import chisel3.util._

class CSR extends Module {
  val io = IO(new Bundle {
    val in = new Bundle {
      val req = Input(new CSRReq)
      
      val wb_ex = Input(Bool())  // 来自WBU的信号，表示处于WB级的指令是否发生了异常
      val wb_cause = Input(UInt(32.W))  // 来自WBU的信号，表示发生异常的原因码
      val wb_pc = Input(UInt(32.W))  // 来自WBU的信号，表示发生异常的指令的PC值
      val mret = Input(Bool())  // 来自WBU的信号，表示处于WB级的指令是否为MRET指令
    }
    val out = new Bundle {
      val resp = Output(new CSRResp)
      val priv = Output(UInt(2.W))
      val redirect_valid = Output(Bool())
      val redirect_target = Output(UInt(32.W))
    }
  })

  val priv = RegInit(PrivilegeLevel.machine)  // 当前特权级，初始为M-mode(3)，不属于CSR寄存器
  io.out.priv := priv

  object CSRAddr {
      val mstatus = 0x300
      val mtvec = 0x305
      val mepc = 0x341
      val mcause = 0x342
      val mcycle = 0xB00
      val mcycleh = 0xB80
      val mvendorid = 0xF11
      val marchid = 0xF12
  }

  object CSRFieldMask {
      val mstatus_mie  = 0x00000008
      val mstatus_mpie = 0x00000080
      val mstatus_mpp  = 0x00001800
  }

  private def csrMaskedWrite(oldVal: UInt, wmask: UInt, wvalue: UInt): UInt = {
    (oldVal & ~wmask) | (wvalue & wmask)
  }
  
  private def csrFieldRead(reg: UInt, mask: Int): UInt = {
    (reg & mask.U(32.W)) >> Integer.numberOfTrailingZeros(mask) // Integer.numberOfTrailingZeros是Scala标准库里的静态函数，只能用于能在生成电路（Elaborate）阶段能确定的值（例如这里的mask），不能用于硬件值
  }
  
  private def csrFieldWrite(reg: UInt, field_mask: Int, value: UInt): UInt = {
    (reg & ~field_mask.U(32.W)) | ((value << Integer.numberOfTrailingZeros(field_mask)) & field_mask.U(32.W))
  }

  val mstatus = RegInit("h1800".U(32.W))
  val mtvec = RegInit(0.U(32.W))
  val mepc = RegInit(0.U(32.W))
  val mcause = RegInit(0.U(32.W))
  val mcycle = RegInit(0.U(32.W))
  val mcycleh = RegInit(0.U(32.W))
  val mvendorid = RegInit("h79737978".U(32.W))  // "ysyx"的ASCII码
  val marchid = RegInit("hC0F18E2".U(32.W))  // 202316002，是我学号的一部分（2023K8009916002）

  val csrTable = Seq(
    CSRAddr.mstatus.U(12.W) -> mstatus,
    CSRAddr.mtvec.U(12.W)   -> mtvec,
    CSRAddr.mepc.U(12.W)    -> mepc,
    CSRAddr.mcause.U(12.W)  -> mcause,
    CSRAddr.mcycle.U(12.W)  -> mcycle,
    CSRAddr.mcycleh.U(12.W) -> mcycleh,
    CSRAddr.mvendorid.U(12.W) -> mvendorid,
    CSRAddr.marchid.U(12.W) -> marchid,
  )

  val hits = csrTable.map { case (addr, _) => io.in.req.addr === addr }
  io.out.resp.rvalue := Mux1H(hits, csrTable.map(_._2))
  io.out.redirect_valid := io.in.wb_ex || io.in.mret
  io.out.redirect_target := Mux(io.in.wb_ex, mtvec & "hfffffffc".U(32.W), mepc)

  for(((_, reg), hit) <- csrTable.zip(hits)) {
    when(io.in.req.we && hit) {
      reg := csrMaskedWrite(reg, io.in.req.wmask, io.in.req.wvalue)
    }
  }

  val mcycleCarry = mcycle === "hffffffff".U
  mcycle := mcycle + 1.U
  when(mcycleCarry) {
    mcycleh := mcycleh + 1.U
  }

  // 处理异常
  when(io.in.wb_ex) {
    mepc := io.in.wb_pc
    mcause := io.in.wb_cause
    val mie = csrFieldRead(mstatus, CSRFieldMask.mstatus_mie)
    val withMpie = csrFieldWrite(mstatus, CSRFieldMask.mstatus_mpie, mie)
    val withMieCleared = csrFieldWrite(withMpie, CSRFieldMask.mstatus_mie, 0.U)
    mstatus := csrFieldWrite(withMieCleared, CSRFieldMask.mstatus_mpp, priv)
    priv := PrivilegeLevel.machine
  } .elsewhen(io.in.mret) {
    val mpp = csrFieldRead(mstatus, CSRFieldMask.mstatus_mpp)
    priv := mpp
    val withMie = csrFieldWrite(mstatus, CSRFieldMask.mstatus_mie, csrFieldRead(mstatus, CSRFieldMask.mstatus_mpie))
    val withMpieSet = csrFieldWrite(withMie, CSRFieldMask.mstatus_mpie, 1.U)
    mstatus := csrFieldWrite(withMpieSet, CSRFieldMask.mstatus_mpp, 0.U)
  }

}
