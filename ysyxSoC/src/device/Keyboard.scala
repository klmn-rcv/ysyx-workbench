package ysyx

import chisel3._
import chisel3.util._

import freechips.rocketchip.amba.apb._
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.util._

class PS2IO extends Bundle {
  val clk = Input(Bool())
  val data = Input(Bool())
}

class PS2CtrlIO extends Bundle {
  val clock = Input(Clock())
  val reset = Input(Bool())
  val in = Flipped(new APBBundle(APBBundleParameters(addrBits = 32, dataBits = 32)))
  val ps2 = new PS2IO
}

class ps2_top_apb extends BlackBox {
  val io = IO(new PS2CtrlIO)
}

class ps2Chisel extends Module {
  val io = IO(new PS2CtrlIO)

  val addr_base = "h10011000".U(32.W)
  val addr_end = "h10011007".U(32.W)
  def addrInRange(addr: UInt): Bool = addr >= addr_base && addr <= addr_end

  val fifo = RegInit(VecInit.fill(8)(0.U(8.W)))
  val w_ptr = RegInit(0.U(3.W))
  val r_ptr = RegInit(0.U(3.W))
  val fifo_count = RegInit(0.U(4.W))
  val overflow = RegInit(false.B)

  val bit_buffer = RegInit(VecInit.fill(10)(false.B))
  val bit_count = RegInit(0.U(4.W))
  val ps2_clk_sync = RegInit(0.U(3.W))

  ps2_clk_sync := Cat(ps2_clk_sync(1, 0), io.ps2.clk)
  val sampling = ps2_clk_sync(2) && !ps2_clk_sync(1)

  val apb_access = io.in.psel && io.in.penable
  val reg_offset = io.in.paddr - addr_base
  val fifo_empty = fifo_count === 0.U
  val fifo_full = fifo_count === 8.U
  val fifo_head = Mux(fifo_empty, 0.U(8.W), fifo(r_ptr))

  io.in.pready := apb_access
  io.in.prdata := 0.U
  io.in.pslverr := false.B
  when(apb_access) {
    assert(addrInRange(io.in.paddr), "PS2: address out of range")
    when(!io.in.pwrite && reg_offset === 0.U) {
      io.in.prdata := fifo_head
    }
  }

  val pop_req = apb_access && !io.in.pwrite && reg_offset === 0.U && !fifo_empty
  val frame_done = sampling && bit_count === 10.U
  val frame_bits = bit_buffer.asUInt
  val frame_valid = frame_done &&
    !bit_buffer(0) &&
    io.ps2.data &&
    frame_bits(9, 1).xorR
  val push_req = frame_valid && (!fifo_full || pop_req)
  val push_data = frame_bits(8, 1)

  when(pop_req) {
    r_ptr := r_ptr + 1.U
  }

  when(push_req) {
    fifo(w_ptr) := push_data
    w_ptr := w_ptr + 1.U
  }

  switch(Cat(push_req, pop_req)) {
    is("b10".U) { fifo_count := fifo_count + 1.U }
    is("b01".U) { fifo_count := fifo_count - 1.U }
  }

  when(frame_valid && !push_req) {
    overflow := true.B
  }

  when(sampling) {
    when(bit_count === 10.U) {
      bit_count := 0.U
    }.otherwise {
      bit_buffer(bit_count) := io.ps2.data
      bit_count := bit_count + 1.U
    }
  }
}

class APBKeyboard(address: Seq[AddressSet])(implicit p: Parameters) extends LazyModule {
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
    val ps2_bundle = IO(new PS2IO)

    val mps2 = Module(new ps2Chisel)
    mps2.io.clock := clock
    mps2.io.reset := reset
    mps2.io.in <> in
    ps2_bundle <> mps2.io.ps2
  }
}
