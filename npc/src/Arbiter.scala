package cpu

import chisel3._
import chisel3.util._

class Arbiter extends Module {
    val io = IO(new Bundle {
        val ifu = Flipped(new AXI4Lite(32, 32))
        val lsu = Flipped(new AXI4Lite(32, 32))
        val out = new AXI4Lite(32, 32)
        val read_is_inst = Output(Bool())
    })

    val lsu_req = io.lsu.ar.arvalid || io.lsu.aw.awvalid || io.lsu.w.wvalid
    val grant_ifu_read = io.ifu.ar.arvalid && !lsu_req
    val read_owner_is_ifu = RegInit(false.B)

    assert(!io.ifu.aw.awvalid && !io.ifu.w.wvalid && !io.ifu.b.bready)
    assert(!(io.lsu.ar.arvalid && (io.lsu.aw.awvalid || io.lsu.w.wvalid)))

    io.read_is_inst := grant_ifu_read

    // AR
    io.out.ar.arvalid := io.lsu.ar.arvalid || grant_ifu_read
    io.out.ar.araddr := Mux(io.lsu.ar.arvalid, io.lsu.ar.araddr, io.ifu.ar.araddr)
    io.lsu.ar.arready := io.out.ar.arready && io.lsu.ar.arvalid
    io.ifu.ar.arready := io.out.ar.arready && grant_ifu_read

    when(io.out.ar.arvalid && io.out.ar.arready) {
        read_owner_is_ifu := grant_ifu_read
    }

    // R
    io.ifu.r.rvalid := io.out.r.rvalid && read_owner_is_ifu
    io.ifu.r.rdata := io.out.r.rdata
    io.ifu.r.rresp := io.out.r.rresp

    io.lsu.r.rvalid := io.out.r.rvalid && !read_owner_is_ifu
    io.lsu.r.rdata := io.out.r.rdata
    io.lsu.r.rresp := io.out.r.rresp

    io.out.r.rready := Mux(read_owner_is_ifu, io.ifu.r.rready, io.lsu.r.rready)

    // AW
    io.out.aw.awvalid := io.lsu.aw.awvalid
    io.out.aw.awaddr := io.lsu.aw.awaddr
    io.lsu.aw.awready := io.out.aw.awready
    io.ifu.aw.awready := false.B

    // W
    io.out.w.wvalid := io.lsu.w.wvalid
    io.out.w.wdata := io.lsu.w.wdata
    io.out.w.wstrb := io.lsu.w.wstrb
    io.lsu.w.wready := io.out.w.wready
    io.ifu.w.wready := false.B

    // B
    io.lsu.b.bvalid := io.out.b.bvalid
    io.lsu.b.bresp := io.out.b.bresp
    io.out.b.bready := io.lsu.b.bready

    io.ifu.b.bvalid := false.B
    io.ifu.b.bresp := 0.U
}
