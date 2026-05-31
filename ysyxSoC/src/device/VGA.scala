package ysyx

import chisel3._
import chisel3.util._

import freechips.rocketchip.amba.apb._
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.util._

class VGAIO extends Bundle {
  val r = Output(UInt(8.W))
  val g = Output(UInt(8.W))
  val b = Output(UInt(8.W))
  val hsync = Output(Bool())
  val vsync = Output(Bool())
  val valid = Output(Bool())
}

class VGACtrlIO extends Bundle {
  val clock = Input(Clock())
  val reset = Input(Bool())
  val in = Flipped(new APBBundle(APBBundleParameters(addrBits = 32, dataBits = 32)))
  val vga = new VGAIO
}

class vga_top_apb extends BlackBox {
  val io = IO(new VGACtrlIO)
}

class vgaChisel extends Module {
  val io = IO(new VGACtrlIO)

  val addr_base = "h21000000".U(32.W)
  val addr_end = "h211fffff".U(32.W)
  def addrInRange(addr: UInt): Bool = addr >= addr_base && addr <= addr_end

  val screen_width = 640
  val screen_height = 480
  val h_sync_end = 96
  val h_active_start = 144
  val h_active_end = 784
  val h_total = 800

  val v_sync_end = 2
  val v_active_start = 35
  val v_active_end = 515
  val v_total = 525

  val fb = Mem(screen_width * screen_height, UInt(32.W))

  val apb_access = io.in.psel && io.in.penable
  val word_addr = (io.in.paddr - addr_base)(20, 2)

  io.in.pready := apb_access
  io.in.prdata := 0.U
  io.in.pslverr := false.B

  when(apb_access) {
    assert(addrInRange(io.in.paddr), "VGA: address out of range")
    when(io.in.pwrite) {
      fb.write(word_addr, io.in.pwdata)
    }.otherwise {
      io.in.prdata := fb.read(word_addr)
    }
  }

  val h_cnt = RegInit(0.U(10.W))
  val v_cnt = RegInit(0.U(10.W))

  when(h_cnt === (h_total - 1).U) {
    h_cnt := 0.U
    when(v_cnt === (v_total - 1).U) {
      v_cnt := 0.U
    }.otherwise {
      v_cnt := v_cnt + 1.U
    }
  }.otherwise {
    h_cnt := h_cnt + 1.U
  }

  val h_active = h_cnt >= h_active_start.U && h_cnt < h_active_end.U
  val v_active = v_cnt >= v_active_start.U && v_cnt < v_active_end.U
  val active = h_active && v_active

  val pixel_x = h_cnt - h_active_start.U
  val pixel_y = v_cnt - v_active_start.U
  val pixel_addr = (pixel_y * screen_width.U + pixel_x)(18, 0)
  val pixel = Mux(active, fb.read(pixel_addr), 0.U(32.W))

  io.vga.r := pixel(23, 16)
  io.vga.g := pixel(15, 8)
  io.vga.b := pixel(7, 0)
  io.vga.hsync := h_cnt >= h_sync_end.U
  io.vga.vsync := v_cnt >= v_sync_end.U
  io.vga.valid := active
}

class APBVGA(address: Seq[AddressSet])(implicit p: Parameters) extends LazyModule {
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
    val vga_bundle = IO(new VGAIO)

    val mvga = Module(new vgaChisel)
    mvga.io.clock := clock
    mvga.io.reset := reset
    mvga.io.in <> in
    vga_bundle <> mvga.io.vga
  }
}
