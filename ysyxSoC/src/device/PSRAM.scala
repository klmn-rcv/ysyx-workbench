package ysyx

import chisel3._
import chisel3.util._
import chisel3.experimental.Analog

import freechips.rocketchip.amba.apb._
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.util._

class QSPIIO extends Bundle {
  val sck = Output(Bool())
  val ce_n = Output(Bool())
  val dio = Analog(4.W)
}

class psram_top_apb extends BlackBox {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Reset())
    val in = Flipped(new APBBundle(APBBundleParameters(addrBits = 32, dataBits = 32)))
    val qspi = new QSPIIO
  })
}

class psram extends BlackBox {
  val io = IO(Flipped(new QSPIIO))
}

class psramChisel extends RawModule {
  val io = IO(Flipped(new QSPIIO))
  withClockAndReset(io.sck.asClock, io.ce_n.asAsyncReset) {
    val dout = Wire(UInt(4.W))
    val out_en = Wire(Bool())
    val di = TriStateInBuf(io.dio, dout, out_en)

    val mem = Mem(0x400000, UInt(8.W))

    val counter = RegInit(0.U(5.W))
    val FINAL_COUNT = 28

    when(counter <= FINAL_COUNT.U) {
      counter := counter + 1.U
    }

    val cmd_trasmitting = counter <= 7.U && !io.ce_n // && FSM.state === FSM.State.BUSY
    val addr_trasmitting = (counter >= 8.U) && (counter <= 13.U)
    val data_trasmitting = (counter >= 21.U) && (counter <= FINAL_COUNT.U)

    out_en := data_trasmitting

    // val done = counter === FINAL_COUNT.U + 1.U

    val cmd = RegInit(0.U(8.W))
    val addr = RegInit(0.U(24.W))
    val data = mem(addr)

    when(cmd_trasmitting) {
      cmd := Cat(cmd(6, 0), di(0))
    }

    when(addr_trasmitting) {
      addr := Cat(addr(19, 0), di)
    }

    when(counter === 8.U) {
      assert(cmd === "heb".U, "Only Fast Read Quad I/O (0xEB) command is supported now")
    }

    dout := MuxLookup(counter - 21.U, data(3,0))(Seq(
      0.U -> data(7,4),
      1.U -> data(3,0),
      2.U -> data(15,12),
      3.U -> data(11,8),
      4.U -> data(23,20),
      5.U -> data(19,16),
      6.U -> data(31,28),
      7.U -> data(27,24)
    ))
  }
}

class APBPSRAM(address: Seq[AddressSet])(implicit p: Parameters) extends LazyModule {
  val node = APBSlaveNode(Seq(APBSlavePortParameters(
    Seq(APBSlaveParameters(
      address       = address,
      executable    = true,
      supportsRead  = true,
      supportsWrite = true)),
    beatBytes  = 4)))

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {
    val (in, _) = node.in(0)
    val qspi_bundle = IO(new QSPIIO)

    val mpsram = Module(new psram_top_apb)
    mpsram.io.clock := clock
    mpsram.io.reset := reset
    mpsram.io.in <> in
    qspi_bundle <> mpsram.io.qspi
  }
}
