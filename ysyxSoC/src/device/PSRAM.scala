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
  val reset = IO(Input(Reset()))
  withClockAndReset(io.sck.asClock, io.ce_n.asAsyncReset) {
    val dout = Wire(UInt(4.W))
    val out_en = Wire(Bool())
    val din = TriStateInBuf(io.dio, dout, out_en)

    val mem = Mem(0x400000, UInt(8.W))

    val qpi_mode = withReset(reset) {
      RegInit(false.B)
    }

    val counter = RegInit(0.U(5.W))
    val RD_FINAL_COUNT_SPI = 28.U(5.W)
    val WR_FINAL_COUNT_SPI = 21.U(5.W)
    val RD_FINAL_COUNT_QPI = 22.U(5.W)
    val WR_FINAL_COUNT_QPI = 15.U(5.W)

    object Cmd {
      val ENTER_QPI = "h35".U(8.W)
      val QUAD_IO_READ = "heb".U(8.W)
      val QUAD_IO_WRITE = "h38".U(8.W)
    }

    val cmd = RegInit(0.U(8.W))
    val addr = RegInit(0.U(24.W))
    val wr = RegInit(false.B)  // write

    val cmd_next = WireDefault(0.U(8.W))

    val cmd_cycles = Mux(qpi_mode, 2.U, 8.U)
    val cmd_end = cmd_cycles - 1.U
    val addr_begin = cmd_end + 1.U
    val addr_end = addr_begin + 5.U
    val rd_dummy_begin = addr_end + 1.U
    val rd_dummy_end = rd_dummy_begin + 6.U  // 7拍空等，比规定的6拍空等多出一拍，这是为了让slave的时钟沿总是先于master的时钟沿
    val rd_data_begin = rd_dummy_end + 1.U
    val wr_data_begin = addr_end + 1.U
    val rd_final_count = Mux(qpi_mode, RD_FINAL_COUNT_QPI, RD_FINAL_COUNT_SPI)
    val wr_final_count = Mux(qpi_mode, WR_FINAL_COUNT_QPI, WR_FINAL_COUNT_SPI)

    when(counter <= rd_final_count) {
      counter := counter + 1.U
    }

    val cmd_trasmitting = (counter <= cmd_end) && !io.ce_n
    val addr_trasmitting = (counter >= addr_begin) && (counter <= addr_end)
    val rd_data_trasmitting = (counter >= rd_data_begin) && (counter <= rd_final_count) && !wr
    val wr_data_trasmitting = (counter >= wr_data_begin) && (counter <= wr_final_count) && wr

    out_en := rd_data_trasmitting
    dontTouch(rd_data_trasmitting)
    dontTouch(out_en)

    when(counter === cmd_end) {
      when(cmd_next === Cmd.QUAD_IO_READ) {
        wr := false.B
      }.elsewhen(cmd_next === Cmd.QUAD_IO_WRITE) {
        wr := true.B
      }.elsewhen(cmd_next === Cmd.ENTER_QPI) {
        qpi_mode := true.B
      }.otherwise {
        printf("Unsupported command: %x\n", cmd_next)
        assert(false.B)
      }
    }

    def offset2addr(offset: UInt): UInt = (addr + offset)(21, 0)

    val rd_bytes = VecInit((0 until 4).map(i => mem(offset2addr(i.U))))
    val rd_data = Cat(rd_bytes.reverse)

    when(cmd_trasmitting) {
      when(!qpi_mode) {
        cmd_next := Cat(cmd(6, 0), din(0))
        cmd := cmd_next
      }.otherwise {
        cmd_next := Cat(cmd(3, 0), din)
        cmd := cmd_next
      }
    }

    when(addr_trasmitting) {
      addr := Cat(addr(19, 0), din)
    }

    val wr_higher_half_byte = RegInit(0.U(4.W))

    when(wr_data_trasmitting) {
      when(!counter(0)) {
        wr_higher_half_byte := din
      }.otherwise {
        val wr_byte_offset = (counter - wr_data_begin - 1.U) >> 1
        mem.write(offset2addr(wr_byte_offset), Cat(wr_higher_half_byte, din))
      }
    }

    dout := MuxLookup(counter - rd_data_begin, rd_data(3,0))(Seq(
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
