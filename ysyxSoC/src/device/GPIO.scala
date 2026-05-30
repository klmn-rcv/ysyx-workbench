package ysyx

import chisel3._
import chisel3.util._

import freechips.rocketchip.amba.apb._
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.util._

class GPIOIO extends Bundle {
  val out = Output(UInt(16.W))
  val in = Input(UInt(16.W))
  val seg = Output(Vec(8, UInt(8.W)))
}

class GPIOCtrlIO extends Bundle {
  val clock = Input(Clock())
  val reset = Input(Reset())
  val in = Flipped(new APBBundle(APBBundleParameters(addrBits = 32, dataBits = 32)))
  val gpio = new GPIOIO
}

class gpio_top_apb extends BlackBox {
  val io = IO(new GPIOCtrlIO)
}

class gpioChisel extends Module {
  val io = IO(new GPIOCtrlIO)

  val addr_base = "h10002000".U(32.W)
  val addr_end = "h1000200f".U(32.W)
  def addrInRange(addr: UInt): Bool = addr >= addr_base && addr <= addr_end

  def hexToSeg(x: UInt): UInt = MuxLookup(x, "b11111111".U(8.W))(Seq(
    "h0".U -> "b00000011".U,
    "h1".U -> "b10011111".U,
    "h2".U -> "b00100101".U,
    "h3".U -> "b00001101".U,
    "h4".U -> "b10011001".U,
    "h5".U -> "b01001001".U,
    "h6".U -> "b01000001".U,
    "h7".U -> "b00011111".U,
    "h8".U -> "b00000001".U,
    "h9".U -> "b00001001".U,
    "ha".U -> "b00010001".U,
    "hb".U -> "b11000001".U,
    "hc".U -> "b01100011".U,
    "hd".U -> "b10000101".U,
    "he".U -> "b01100001".U,
    "hf".U -> "b01110001".U
  ))

  val reg0x0_led = RegInit(0.U(16.W))
  val reg0x8_hex = RegInit(VecInit.fill(8)(0.U(4.W)))
  io.gpio.out := reg0x0_led
  io.gpio.seg := reg0x8_hex.map(hexToSeg)

  io.in.pready := false.B
  io.in.prdata := 0.U
  io.in.pslverr := false.B

  when(io.in.psel && io.in.penable) {
    assert(addrInRange(io.in.paddr), "GPIO: address out of range")
    io.in.pready := true.B
    switch(io.in.paddr - addr_base) {
      is(0.U) {
        assert(io.in.pwrite, "GPIO: read not supported at address 0x0")
        reg0x0_led := io.in.pwdata(15, 0)
      }
      is(4.U) {
        assert(!io.in.pwrite, "GPIO: write not supported at address 0x4")
        io.in.prdata := io.gpio.in.pad(32)
      }
      is(8.U) {
        for (i <- 0 until 8) {
          reg0x8_hex(i) := io.in.pwdata(4*i + 3, 4*i)
        }
      }
      is(12.U) {
        assert(false.B, "GPIO: reserved address 0xc")
      }
    }
  }
}

class APBGPIO(address: Seq[AddressSet])(implicit p: Parameters) extends LazyModule {
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
    val gpio_bundle = IO(new GPIOIO)

    val mgpio = Module(new gpioChisel)
    mgpio.io.clock := clock
    mgpio.io.reset := reset
    mgpio.io.in <> in
    gpio_bundle <> mgpio.io.gpio
  }
}
