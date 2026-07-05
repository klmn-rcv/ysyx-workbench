package cpu

import chisel3._
import chisel3.util._

class AXI4Arbiter extends Module with HasYsyxModuleName {
    override protected def moduleSuffix: String = "AXI4Arbiter"
    val io = IO(new Bundle {
        val if_iw = Flipped(new AXI4(32, 32, 4))
        val ls_lsw = Flipped(new AXI4(32, 32, 4))
        val ls_lsw_load = Input(Bool())
        val xbar = new AXI4(32, 32, 4)
        val xbar_r_need_skip_ref = Input(Bool())
        val xbar_b_need_skip_ref = Input(Bool())
        val ls_lsw_r_need_skip_ref = Output(Bool())
        val ls_lsw_b_need_skip_ref = Output(Bool())
    })

    val if_iw_ar_fire = io.if_iw.arvalid && io.if_iw.arready
    val if_iw_r_fire = io.if_iw.rvalid && io.if_iw.rready

    // val ls_lsw_req = io.ls_lsw.arvalid || io.ls_lsw.awvalid || io.ls_lsw.wvalid
    val grant_if_iw_read = io.if_iw.arvalid && !io.ls_lsw_load
    val grant_if_iw_read_preserved = bool_preserve(grant_if_iw_read, if_iw_r_fire, false.B)._1
    val read_owner_is_if_iw = boolreg_set_clear(if_iw_ar_fire, if_iw_r_fire)

    assert(!io.if_iw.awvalid && !io.if_iw.wvalid && !io.if_iw.bready)
    assert(!(io.ls_lsw.arvalid && (io.ls_lsw.awvalid || io.ls_lsw.wvalid)))

    // 一旦拉高grant_if_iw_read，就必须完成IFU这次的AR握手，因此下面的AR逻辑需要改
    // R逻辑就按read_owner_is_if_iw来区分，不需要改
    // 如果IFU的AR请求发到一半，突然LSU来了个load，IFU仍然需要完成AR握手，LSU要等到IFU的R握手都完成之后才有可能完成AR握手
    // 但这不会造成跟之前一样的死锁，因为“IFU的AR请求发到一半，突然LSU来了个load”意味着一定有空泡，IFU一定能进入IWU完成R握手，不会被LSU/LSWU卡住形成死锁
    // AR
    io.xbar.arvalid := io.ls_lsw.arvalid || grant_if_iw_read
    when(grant_if_iw_read_preserved) {
        connectFields(io.if_iw.ar, io.xbar.ar, "araddr", "arid", "arlen", "arsize", "arburst")
        io.ls_lsw.arready := false.B
        io.if_iw.arready := io.xbar.arready && grant_if_iw_read
    }.otherwise {
        connectFields(io.ls_lsw.ar, io.xbar.ar, "araddr", "arid", "arlen", "arsize", "arburst")
        io.ls_lsw.arready := io.xbar.arready
        io.if_iw.arready := false.B
    }

    // R
    when(read_owner_is_if_iw) {
        connectFields(io.xbar.r, io.if_iw.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
        io.ls_lsw.rvalid := false.B
        io.ls_lsw.rdata := 0.U
        io.ls_lsw.rresp := 0.U
        io.ls_lsw.rid := 0.U
        io.ls_lsw.rlast := false.B
    }.otherwise {
        connectFields(io.xbar.r, io.ls_lsw.r, "rvalid", "rdata", "rresp", "rid", "rlast", "rready")
        io.if_iw.rvalid := false.B
        io.if_iw.rdata := 0.U
        io.if_iw.rresp := 0.U
        io.if_iw.rid := 0.U
        io.if_iw.rlast := false.B
    }

    // AW
    io.xbar.awvalid := io.ls_lsw.awvalid
    connectFields(io.ls_lsw.aw, io.xbar.aw, "awaddr", "awid", "awlen", "awsize", "awburst", "awready")
    io.if_iw.awready := false.B

    // W
    connectFields(io.ls_lsw.w, io.xbar.w, "wvalid", "wdata", "wstrb", "wlast", "wready")
    io.if_iw.wready := false.B

    // B
    connectFields(io.xbar.b, io.ls_lsw.b, "bvalid", "bresp", "bid", "bready")
    io.if_iw.bvalid := false.B
    io.if_iw.bresp := 0.U
    io.if_iw.bid := 0.U

    io.ls_lsw_r_need_skip_ref := io.xbar_r_need_skip_ref
    io.ls_lsw_b_need_skip_ref := io.xbar_b_need_skip_ref
}
