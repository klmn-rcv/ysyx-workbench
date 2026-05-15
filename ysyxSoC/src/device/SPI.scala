package ysyx

import chisel3._
import chisel3.util._

import freechips.rocketchip.amba.apb._
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.util._

class SPIIO(val ssWidth: Int = 8) extends Bundle {
  val sck = Output(Bool())
  val ss = Output(UInt(ssWidth.W))
  val mosi = Output(Bool())
  val miso = Input(Bool())
}

class spi_top_apb extends BlackBox {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Reset())
    val in = Flipped(new APBBundle(APBBundleParameters(addrBits = 32, dataBits = 32)))
    val spi = new SPIIO
    val spi_irq_out = Output(Bool())
  })
}

class flash extends BlackBox {
  val io = IO(Flipped(new SPIIO(1)))
}
class APBSPI(address: Seq[AddressSet])(implicit p: Parameters) extends LazyModule {
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
    val spi_bundle = IO(new SPIIO)

    object ApbSpiTarget extends ChiselEnum {
      val none, spiMaster, xipFlash = Value
    }

    final class AddrRange(val begin: BigInt, val end: BigInt) {
      require(begin <= end)
      private val begin_addr = begin.U(32.W)
      private val end_addr = end.U(32.W)

      def contains(addr: UInt): Bool = addr >= begin_addr && addr <= end_addr
    }

    object AddrRange {
      def apply(begin: BigInt, end: BigInt): AddrRange = new AddrRange(begin, end)
    }

    val spi_master_range = AddrRange(0x10001000L, 0x10001fffL)
    val xip_flash_range  = AddrRange(0x30000000L, 0x3fffffffL)

    def decodeAddr(addr: UInt): ApbSpiTarget.Type = {
      val target = WireDefault(ApbSpiTarget.none)
      when(spi_master_range.contains(addr)) {
        target := ApbSpiTarget.spiMaster
      }.elsewhen(xip_flash_range.contains(addr)) {
        target := ApbSpiTarget.xipFlash
      }
      target
    }

    object SPIRegAddr {
      val spi_rx0_addr = "h00".U(32.W)
      val spi_rx1_addr = "h04".U(32.W)
      val spi_tx0_addr = "h00".U(32.W)
      val spi_tx1_addr = "h04".U(32.W)
      val spi_ctrl_addr = "h10".U(32.W)
      val spi_divider_addr = "h14".U(32.W)
      val spi_ss_addr = "h18".U(32.W)
    }

    object SPICTRLBitField {
      val spi_ctrl_go_bsy = 8
      val spi_ctrl_tx_neg = 10
      val spi_ctrl_ie = 12
      val spi_ctrl_ass = 13
    }

    object FlashSPIConfig {
      val flash_read_cmd = "h03".U(8.W)
      val flash_divider_value = 1.U(32.W)
      val flash_ss_value = 1.U(32.W)
      val flash_tx0_value = 0.U(32.W)
      val flash_ctrl_value =
        (64.U(32.W) << 0) |
        (1.U(32.W) << SPICTRLBitField.spi_ctrl_go_bsy) |
        (1.U(32.W) << SPICTRLBitField.spi_ctrl_tx_neg) |
        (1.U(32.W) << SPICTRLBitField.spi_ctrl_ie) |
        (1.U(32.W) << SPICTRLBitField.spi_ctrl_ass)
    }

    def bswap32(data: UInt): UInt = Cat(data(7, 0), data(15, 8), data(23, 16), data(31, 24))

    class FlashInitReq extends Bundle {
      val addr = UInt(32.W)
      val data = UInt(32.W)
    }

    object FlashInitReq {
      def apply(addr: UInt, data: UInt): FlashInitReq = {
        val req = Wire(new FlashInitReq)
        req.addr := addr
        req.data := data
        req
      }
    }

    val target = decodeAddr(in.paddr)
    val hit_spi_master = target === ApbSpiTarget.spiMaster
    val hit_xip_flash = target === ApbSpiTarget.xipFlash

    in.pready := false.B
    in.pslverr := false.B
    in.prdata := 0.U
    in.pduser := DontCare

    val mspi = Module(new spi_top_apb)
    mspi.io.clock := clock
    mspi.io.reset := reset
    mspi.io.in :<= 0.U.asTypeOf(chiselTypeOf(mspi.io.in))

    val cpu2flash_apb_setup = in.psel && !in.penable && hit_xip_flash

    val flash_addr_reg = RegInit(0.U(24.W))
    val flash_rdata_reg = RegInit(0.U(32.W))

    // XipFlashFSM 给 ApbFSM 发的请求Bundle
    class XipApbReq extends Bundle {
      val write = Bool()
      val addr = UInt(32.W)
      val wdata = UInt(32.W)
    }

    // 两个状态机之间的交互接口
    object XipApbLink {
      val req_valid = WireDefault(false.B)
      val req = WireDefault(0.U.asTypeOf(new XipApbReq))
      val req_ready = Wire(Bool())
      val resp_valid = Wire(Bool())
      val resp_rdata = Wire(UInt(32.W))
    }

    val apb_req_reg = RegInit(0.U.asTypeOf(new XipApbReq))

    // 状态机1：XIP Flash 状态转移规则
    object XipFlashFSM {
      object XipFlashState extends ChiselEnum {
        val Idle, Init, Transmit, Load, Done = Value
      }

      object InitSubstate extends ChiselEnum {
        val WriteDivider, WriteSs, WriteTx0, WriteTx1, WriteCtrl = Value
      }

      val state = RegInit(XipFlashState.Idle)
      val init_substate = RegInit(InitSubstate.WriteDivider)

      def done: Bool = state === XipFlashState.Done

      switch(state) {
        is(XipFlashState.Idle) {
          when(cpu2flash_apb_setup) {
            state := XipFlashState.Init
            init_substate := InitSubstate.WriteDivider
          }
        }

        is(XipFlashState.Init) {
          when(XipApbLink.resp_valid) {
            when(init_substate === InitSubstate.WriteCtrl) {
              state := XipFlashState.Transmit
            }.otherwise {
              init_substate := InitSubstate(init_substate.asUInt + 1.U) // 默认“ChiselEnum连续编码”这个事实
            }
          }
        }

        is(XipFlashState.Transmit) {
          when(mspi.io.spi_irq_out) {
            state := XipFlashState.Load
          }
        }

        is(XipFlashState.Load) {
          when(XipApbLink.resp_valid) {
            state := XipFlashState.Done
          }
        }

        is(XipFlashState.Done) {
          state := XipFlashState.Idle
        }
      }
    }

    // 状态机2：给 mspi 发 APB 请求的 master 的状态转移规则
    object ApbFSM {
      object ApbState extends ChiselEnum {
        val Idle, Setup, Access = Value
      }

      val state = RegInit(ApbState.Idle)

      switch(state) {
        is(ApbState.Idle) {
          when(XipApbLink.req_valid) {
            state := ApbState.Setup
          }
        }

        is(ApbState.Setup) {
          state := ApbState.Access
        }

        is(ApbState.Access) {
          when(mspi.io.in.pready) {
            state := ApbState.Idle
          }
        }
      }
    }

    XipApbLink.req_ready := ApbFSM.state === ApbFSM.ApbState.Idle
    XipApbLink.resp_valid := ApbFSM.state === ApbFSM.ApbState.Access && mspi.io.in.pready
    XipApbLink.resp_rdata := mspi.io.in.prdata

    when(XipApbLink.req_valid && XipApbLink.req_ready) {
      apb_req_reg := XipApbLink.req
    }

    when(cpu2flash_apb_setup) {
      // SPI flash 读命令只携带 24-bit 地址，并按4字节对齐
      flash_addr_reg := Cat(in.paddr(23, 2), 0.U(2.W))
    }

    when(XipFlashFSM.state === XipFlashFSM.XipFlashState.Load && XipApbLink.resp_valid) {
      flash_rdata_reg := bswap32(XipApbLink.resp_rdata)
    }

    val flash_init_reqs = VecInit(Seq(
      FlashInitReq(SPIRegAddr.spi_divider_addr, FlashSPIConfig.flash_divider_value),
      FlashInitReq(SPIRegAddr.spi_ss_addr, FlashSPIConfig.flash_ss_value),
      FlashInitReq(SPIRegAddr.spi_tx0_addr, FlashSPIConfig.flash_tx0_value),
      FlashInitReq(SPIRegAddr.spi_tx1_addr, Cat(FlashSPIConfig.flash_read_cmd, flash_addr_reg)),
      FlashInitReq(SPIRegAddr.spi_ctrl_addr, FlashSPIConfig.flash_ctrl_value),
    ))

    // XipFlashFSM -> ApbFSM 的请求
    switch(XipFlashFSM.state) {
      is(XipFlashFSM.XipFlashState.Init) {
        val init_req = flash_init_reqs(XipFlashFSM.init_substate.asUInt)
        XipApbLink.req_valid := true.B
        XipApbLink.req.write := true.B
        XipApbLink.req.addr := init_req.addr
        XipApbLink.req.wdata := init_req.data
      }

      is(XipFlashFSM.XipFlashState.Load) {
        XipApbLink.req_valid := true.B
        XipApbLink.req.write := false.B
        XipApbLink.req.addr := SPIRegAddr.spi_rx0_addr
      }
    }

    when(XipApbLink.resp_valid) {
      assert(!mspi.io.in.pslverr)
    }

    switch(target) {
      is(ApbSpiTarget.spiMaster) {
        mspi.io.in <> in

        when(in.psel && in.penable && mspi.io.in.pready) {
          assert(!mspi.io.in.pslverr)
        }
      }

      is(ApbSpiTarget.xipFlash) {
        when(ApbFSM.state === ApbFSM.ApbState.Setup || ApbFSM.state === ApbFSM.ApbState.Access) {
          mspi.io.in.psel := true.B
          mspi.io.in.penable := ApbFSM.state === ApbFSM.ApbState.Access
          mspi.io.in.pwrite := apb_req_reg.write
          mspi.io.in.paddr := apb_req_reg.addr
          mspi.io.in.pprot := 0.U
          mspi.io.in.pwdata := apb_req_reg.wdata
          mspi.io.in.pstrb := Mux(apb_req_reg.write, Fill(4, 1.U(1.W)), 0.U(4.W))
        }

        in.pready := XipFlashFSM.done && in.psel && in.penable
        in.prdata := flash_rdata_reg
      }

      is(ApbSpiTarget.none) {
        in.pready := in.psel && in.penable
      }
    }

    spi_bundle <> mspi.io.spi
  }
}