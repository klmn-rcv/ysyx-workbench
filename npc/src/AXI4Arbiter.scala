package cpu

import chisel3._
import chisel3.util._

class AXI4Arbiter extends Module with HasYsyxModuleName {
    override protected def moduleSuffix: String = "AXI4Arbiter"
    val io = IO(new Bundle {
        val ifu = Flipped(new AXI4(32, 32, 4))
        val lsu = Flipped(new AXI4(32, 32, 4))
        val out = new AXI4(32, 32, 4)
        val out_r_need_skip_ref = Input(Bool())
        val out_b_need_skip_ref = Input(Bool())
        val lsu_r_need_skip_ref = Output(Bool())
        val lsu_b_need_skip_ref = Output(Bool())
    })

    val lsu_req = io.lsu.arvalid || io.lsu.awvalid || io.lsu.wvalid
    val grant_ifu_read = io.ifu.arvalid && !lsu_req
    val read_owner_is_ifu = RegInit(false.B)

    assert(!io.ifu.awvalid && !io.ifu.wvalid && !io.ifu.bready)
    assert(!(io.lsu.arvalid && (io.lsu.awvalid || io.lsu.wvalid)))

    // AR
    io.out.arvalid := io.lsu.arvalid || grant_ifu_read
    when(io.lsu.arvalid) {
        connectFields(io.lsu.ar, io.out.ar, "araddr", "arid", "arlen", "arsize", "arburst")
        io.lsu.arready := io.out.arready
        io.ifu.arready := false.B
    }.otherwise {
        connectFields(io.ifu.ar, io.out.ar, "araddr", "arid", "arlen", "arsize", "arburst")
        io.lsu.arready := false.B
        io.ifu.arready := io.out.arready && grant_ifu_read
    }

    when(io.out.arvalid && io.out.arready) {
        read_owner_is_ifu := grant_ifu_read
    }

    // R
    when(read_owner_is_ifu) {
        connectFields(io.out.r, io.ifu.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
        io.lsu.rvalid := false.B
        io.lsu.rdata := 0.U
        io.lsu.rresp := 0.U
        io.lsu.rid := 0.U
        io.lsu.rlast := false.B
    }.otherwise {
        connectFields(io.out.r, io.lsu.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
        io.ifu.rvalid := false.B
        io.ifu.rdata := 0.U
        io.ifu.rresp := 0.U
        io.ifu.rid := 0.U
        io.ifu.rlast := false.B
    }

    // AW
    io.out.awvalid := io.lsu.awvalid
    connectFields(io.lsu.aw, io.out.aw, "awaddr", "awid", "awlen", "awsize", "awburst", "awready")
    io.ifu.awready := false.B

    // W
    connectFields(io.lsu.w, io.out.w, "wvalid", "wdata", "wstrb", "wlast", "wready")
    io.ifu.wready := false.B

    // B
    connectFields(io.out.b, io.lsu.b, "bvalid", "bresp", "bid", "bready")
    io.ifu.bvalid := false.B
    io.ifu.bresp := 0.U
    io.ifu.bid := 0.U

    io.lsu_r_need_skip_ref := io.out_r_need_skip_ref
    io.lsu_b_need_skip_ref := io.out_b_need_skip_ref
}
