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
    val din = TriStateInBuf(io.dio, dout, out_en)

    val mem = Mem(0x400000, UInt(8.W))

    val counter = RegInit(0.U(5.W))
    val RD_FINAL_COUNT = 28  // 读的时候多一拍，因为slave比master的counter更新更快
    val WR_FINAL_COUNT = 21

    when(counter <= RD_FINAL_COUNT.U) {
      counter := counter + 1.U
    }

    object Cmd {
      val QUAD_IO_READ = "heb".U(8.W)
      val QUAD_IO_WRITE = "h38".U(8.W)
    }

    val cmd = RegInit(0.U(8.W))
    val addr = RegInit(0.U(24.W))
    val wr = RegInit(false.B)  // write

    val cmd_trasmitting = counter <= 7.U && !io.ce_n // && FSM.state === FSM.State.BUSY
    val addr_trasmitting = (counter >= 8.U) && (counter <= 13.U)
    val rd_data_trasmitting = (counter >= 21.U) && (counter <= RD_FINAL_COUNT.U) && !wr
    val wr_data_trasmitting = (counter >= 14.U) && (counter <= WR_FINAL_COUNT.U) && wr

    out_en := rd_data_trasmitting

    when(counter === 8.U) {
      when(cmd === Cmd.QUAD_IO_READ) {
        wr := false.B
      }.elsewhen(cmd === Cmd.QUAD_IO_WRITE) {
        wr := true.B
      }.otherwise {
        assert(false, "Unsupported command")
      }
    }

    def offset2addr(offset: UInt): UInt = (addr + offset)(21, 0)

    val rd_bytes = VecInit((0 until 4).map(i => mem(offset2addr(i.U))))
    val rd_data = Cat(rd_bytes.reverse)

    when(cmd_trasmitting) {
      cmd := Cat(cmd(6, 0), din(0))
    }

    when(addr_trasmitting) {
      addr := Cat(addr(19, 0), din)
    }

    val wr_higher_half_byte = RegInit(0.U(4.W))

    when(wr_data_trasmitting) {
      when(!counter(0)) {  // 从counter == 14开始，偶数拍暂存高半字节，奇数拍把低半字节和之前的高半字节合并写入mem
        wr_higher_half_byte := din
      }.otherwise {
        val wr_byte_offset = (counter - 15.U) >> 1
        mem.write(offset2addr(wr_byte_offset), Cat(wr_higher_half_byte, din))
      }
    }

    dout := MuxLookup(counter - 21.U, rd_data(3,0))(Seq(
      0.U -> rd_data(7,4),
      1.U -> rd_data(3,0),
      2.U -> rd_data(15,12),
      3.U -> rd_data(11,8),
      4.U -> rd_data(23,20),
      5.U -> rd_data(19,16),
      6.U -> rd_data(31,28),
      7.U -> rd_data(27,24)
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
