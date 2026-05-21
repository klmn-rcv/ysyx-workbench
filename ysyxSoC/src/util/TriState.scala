package ysyx

import chisel3._
import chisel3.util._
import chisel3.experimental.Analog

class TriStateInBuf(bits: Int) extends BlackBox(Map("width" -> bits)) with HasBlackBoxInline {
  val io = IO(new Bundle {
    val dio = Analog(bits.W)
    val dout = Input(UInt(bits.W))
    val out_en = Input(Bool())
    val din = Output(UInt(bits.W))
  })

  setInline("TriStateInBuf.v",
    """module TriStateInBuf #(
      |  parameter width = 1
      |)(
      |    inout  [width-1:0] dio,
      |    input  [width-1:0] dout,
      |    input              out_en,
      |    output [width-1:0] din
      |);
      |  assign din = dio;
      |  assign dio = out_en ? dout : {width{1'bz}};
      |endmodule
    """.stripMargin)
}

object TriStateInBuf {
  def apply(dio: Analog, dout: UInt, out_en: Bool) = {
    val buf = Module(new TriStateInBuf(dio.getWidth))
    buf.io.dio <> dio
    buf.io.dout := dout
    buf.io.out_en := out_en
    buf.io.din
  }
}

class TriStateInBufVecEn(bits: Int) extends BlackBox(Map("width" -> bits)) with HasBlackBoxInline {
  val io = IO(new Bundle {
    val dio = Analog(bits.W)
    val dout = Input(UInt(bits.W))
    val out_en = Input(UInt((bits / 8).W))
    val din = Output(UInt(bits.W))
  })

  setInline("TriStateInBufVecEn.v",
    """module TriStateInBufVecEn #(
      |  parameter width = 1
      |)(
      |  inout  [width-1:0] dio,
      |  input  [width-1:0] dout,
      |  input  [width/8-1:0] out_en,
      |  output [width-1:0] din
      |);
      |  genvar i;
      |  assign din = dio;
      |  generate
      |    for (i = 0; i < width; i = i + 1) begin : gen_ts
      |      assign dio[i] = out_en[i / 8] ? dout[i] : 1'bz;
      |    end
      |  endgenerate
      |endmodule
    """.stripMargin)
}

object TriStateInBufVecEn {
  def apply(dio: Analog, dout: UInt, out_en: UInt) = {
    val buf = Module(new TriStateInBufVecEn(dio.getWidth))
    buf.io.dio <> dio
    buf.io.dout := dout
    buf.io.out_en := out_en
    buf.io.din
  }
}
