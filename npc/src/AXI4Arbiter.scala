package cpu

import chisel3._
import chisel3.util._

class AXI4Arbiter extends Module with HasYsyxModuleName {
    override protected def moduleSuffix: String = "AXI4Arbiter"
    val io = IO(new Bundle {
        val ifu = Flipped(new AXI4(32, 32, 4))
        val lsu = Flipped(new AXI4(32, 32, 4))
        val xbar = new AXI4(32, 32, 4)
        val xbar_r_need_skip_ref = Input(Bool())
        val xbar_b_need_skip_ref = Input(Bool())
        val lsu_r_need_skip_ref = Output(Bool())
        val lsu_b_need_skip_ref = Output(Bool())
    })

    val lsu_req = io.lsu.arvalid || io.lsu.awvalid || io.lsu.wvalid
    val grant_ifu_read = io.ifu.arvalid && !lsu_req

    assert(!io.ifu.awvalid && !io.ifu.wvalid && !io.ifu.bready)
    assert(!(io.lsu.arvalid && (io.lsu.awvalid || io.lsu.wvalid)))

    // AR
    io.xbar.arvalid := io.lsu.arvalid || grant_ifu_read
    when(io.lsu.arvalid) {
        connectFields(io.lsu.ar, io.xbar.ar, "araddr", "arid", "arlen", "arsize", "arburst")
        io.lsu.arready := io.xbar.arready
        io.ifu.arready := false.B
    }.otherwise {
        connectFields(io.ifu.ar, io.xbar.ar, "araddr", "arid", "arlen", "arsize", "arburst")
        io.lsu.arready := false.B
        io.ifu.arready := io.xbar.arready && grant_ifu_read
    }

    // R
    val xbar_r_to_ifu = io.xbar.r.rvalid && io.xbar.r.rid === AXI4Id.IFU
    val xbar_r_to_lsu = io.xbar.r.rvalid && io.xbar.r.rid === AXI4Id.LSU
    assert(!io.xbar.r.rvalid || xbar_r_to_ifu || xbar_r_to_lsu)

    io.ifu.r.rvalid := xbar_r_to_ifu
    io.ifu.r.rdata := io.xbar.r.rdata
    io.ifu.r.rresp := io.xbar.r.rresp
    io.ifu.r.rid := io.xbar.r.rid
    io.ifu.r.rlast := io.xbar.r.rlast

    io.lsu.r.rvalid := xbar_r_to_lsu
    io.lsu.r.rdata := io.xbar.r.rdata
    io.lsu.r.rresp := io.xbar.r.rresp
    io.lsu.r.rid := io.xbar.r.rid
    io.lsu.r.rlast := io.xbar.r.rlast

    io.xbar.r.rready := Mux(xbar_r_to_ifu, io.ifu.r.rready,
                        Mux(xbar_r_to_lsu, io.lsu.r.rready, false.B))

    // AW
    io.xbar.awvalid := io.lsu.awvalid
    connectFields(io.lsu.aw, io.xbar.aw, "awaddr", "awid", "awlen", "awsize", "awburst", "awready")
    io.ifu.awready := false.B

    // W
    connectFields(io.lsu.w, io.xbar.w, "wvalid", "wdata", "wstrb", "wlast", "wready")
    io.ifu.wready := false.B

    // B
    connectFields(io.xbar.b, io.lsu.b, "bvalid", "bresp", "bid", "bready")
    io.ifu.bvalid := false.B
    io.ifu.bresp := 0.U
    io.ifu.bid := 0.U

    io.lsu_r_need_skip_ref := io.xbar_r_need_skip_ref
    io.lsu_b_need_skip_ref := io.xbar_b_need_skip_ref
}
