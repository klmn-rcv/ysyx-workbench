package ysyx

import chisel3._
import chisel3.util._

class bitrev extends BlackBox {
  val io = IO(Flipped(new SPIIO(1)))
}

// Tx_NEG=1，Rx_NEG=0，空闲时钟电平为0，这属于mode 0配置。
// 由于空闲时钟电平为0，所以上升沿先来，rxCnt比txCnt更先到8。
class bitrevChisel extends RawModule { // we do not need clock and reset
  val io = IO(Flipped(new SPIIO(1)))
  val ss = io.ss(0).asBool
  val reset = ss.asAsyncReset
  val rxData = withClockAndReset(io.sck.asClock, reset) { RegInit(0.U(8.W)) }
  val rxCnt = withClockAndReset(io.sck.asClock, reset) { RegInit(0.U(4.W)) }
  when (rxCnt < 8.U) {
    rxData := Cat(rxData(6, 0), io.mosi)
    rxCnt := rxCnt + 1.U
  }

  val txData = withClockAndReset((!io.sck).asClock, reset) { RegInit(0.U(8.W)) }
  val txCnt = withClockAndReset((!io.sck).asClock, reset) { RegInit(0.U(4.W)) }
  val miso = withClockAndReset((!io.sck).asClock, reset) { RegInit(true.B) }
  when (txCnt < 7.U) {
    txCnt := txCnt + 1.U
    txData := rxData
    miso := true.B
  }.elsewhen (txCnt === 7.U) {
    txCnt := txCnt + 1.U
    txData := rxData >> 1
    miso := rxData(0)
  }.elsewhen (txCnt < 15.U) {
    txCnt := txCnt + 1.U
    txData := txData >> 1
    miso := txData(0)
  }
  io.miso := Mux(ss, true.B, miso)
}
