package cpu

import chisel3._
import chisel3.util._

class LSWU extends Module with HasYsyxModuleName {
    override protected def moduleSuffix: String = "LSWU"
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new LSUOut))
        val out = Decoupled(new LSWUOut)
        val mem = new Bundle {
            val r = new AXI4R(32, 4)
            val b = new AXI4B(4)
            val r_need_skip_ref = Input(Bool())
            val b_need_skip_ref = Input(Bool())
        }
        val ctrl = new Bundle {
            val ex_found_out = Output(Bool())
            val older_mem_pending = Output(Bool())
        }
        val flush = new Bundle {
            val ex_found_in = Input(Bool())
            val flush = Output(Bool())
        }
        val load = Output(Bool())
    })

    // assert(!io.mem.r.rvalid || (io.mem.r.rresp === AXI4Resp.OKAY && io.mem.r.rlast))
    // assert(!io.mem.b.bvalid || io.mem.b.bresp === AXI4Resp.OKAY)

    val load = io.in.bits.rd_mem
    val mem_access = io.in.bits.rd_mem || io.in.bits.wr_mem

    val flush = Wire(Bool())  // 仅对!mem_access的指令才可能flush
    val valid = io.in.valid && !flush

    flush:= !mem_access && io.flush.ex_found_in
    io.flush.flush := flush

    // val need_flush_in_LSWU = (mem_access && io.flush.ex_found_in) && valid  // !mem_access是因为，如果是访存指令，我们认为它不能在LSWU被flush，因为需要完成握手，并且还需要让它流到下一级（LSWU）去完成flush的动作；如果不是访存指令，可以直接flush。

    val load_data = Wire(UInt(32.W))
    val r_fire = io.mem.r.rvalid && io.mem.r.rready  // 对于非load指令，r_fire永远为0（因为rready为0）
    val b_fire = io.mem.b.bvalid && io.mem.b.bready  // 对于非store指令，b_fire永远为0（因为bready为0）
                // 上面两个fire信号都不能接valid信号（虽然接不接不影响逻辑），因为现在不允许在内容无效的时候假握手了，原因是LSU随时可能流过来，导致错位
    val (r_fire_preserved, load_data_preserved, r_fire_after, _) = valid_and_data_preserve(r_fire, load_data, io.out.fire, false.B)
    val (b_fire_preserved, b_fire_after) = bool_preserve(b_fire, io.out.fire, false.B)

    io.ctrl.older_mem_pending := ((io.in.bits.rd_mem && !r_fire_after) ||
                                 (io.in.bits.wr_mem && !b_fire_after)) && valid
    // older_mem_pending表示：LSWU当前还持有一条更老的访存指令，并且它的最终 R/B 握手还没完成。
    // 这时年轻访存虽然可以先进入LSU，但不能启动新的AR/AW/W。
    // 原因是：如果更老指令在这一拍的R/B响应里检测到resp_ex，年轻访存必须不能先把自己的请求发到总线上，
    // 否则请求将不可撤回，而这可能产生副作用。
    // IFU/IWU不存在这样的机制，是因为为了取指令而发的访存请求都不存在副作用（一不会访问内存以外的设备，二不会有写操作）。

    val r_need_skip_ref = r_fire && io.mem.r_need_skip_ref
    val b_need_skip_ref = b_fire && io.mem.b_need_skip_ref
    val (need_skip_ref_preserved, _) = bool_preserve(r_need_skip_ref || b_need_skip_ref, io.out.fire, false.B)

    val ready_go = !mem_access ||
                   (io.in.bits.rd_mem && r_fire_preserved) ||  
                   (io.in.bits.wr_mem && b_fire_preserved) 
    io.in.ready := !reset.asBool && (!valid || ready_go && io.out.ready)
    io.out.valid := valid && ready_go

    val resp_ex = io.in.bits.rd_mem && resp_error(io.mem.r.rresp) && r_fire ||
                  io.in.bits.wr_mem && resp_error(io.mem.b.bresp) && b_fire
    val resp_ex_preserved = bool_preserve(resp_ex, io.out.fire, false.B)._1
    io.ctrl.ex_found_out := resp_ex

    load_data := ExtractLoadData(io.mem.r.rdata, io.in.bits.raddr, io.in.bits.bit_width, io.in.bits.sign)

    io.mem.r.rready := valid && io.in.bits.rd_mem && !r_fire_after && !io.in.bits.has_exception
    // 这里看 io.in.bits.has_exception，而不是 allow_side_effect。
    // 原因是本级新异常 resp_ex 正是由当前这次 R 握手定义出来的，不能再反过来阻止这次握手本身。
    io.mem.b.bready := valid && io.in.bits.wr_mem && !b_fire_after && !io.in.bits.has_exception
    // B 通道同理：这里只看上级已经带下来的异常，不看本级由当前 B 握手才得出的 resp_ex。

    // val need_flush_in_LSWU_preserved = bool_preserve(need_flush_in_LSWU, io.out.fire, false.B)._1
    // io.out.bits.need_flush_in_LSU_or_LSWU := io.in.bits.need_flush_in_LSU || need_flush_in_LSWU_preserved

    io.out.bits.data := Mux(io.in.bits.rd_mem, load_data_preserved, io.in.bits.result)
    io.out.bits.need_skip_ref := need_skip_ref_preserved

    io.out.bits.wr_reg := io.in.bits.wr_reg
    io.out.bits.rd := io.in.bits.rd
    io.out.bits.ebreak := io.in.bits.ebreak
    io.out.bits.inv := io.in.bits.inv
    io.out.bits.inst := io.in.bits.inst
    io.out.bits.pc := io.in.bits.pc
    io.out.bits.dnpc := io.in.bits.dnpc
    io.out.bits.csrReq := io.in.bits.csrReq
    io.out.bits.ecall := io.in.bits.ecall
    io.out.bits.mret := io.in.bits.mret
    io.out.bits.has_exception := io.in.bits.has_exception || resp_ex_preserved
    io.out.bits.exception_code := Mux(io.in.bits.has_exception, io.in.bits.exception_code,
                                    Mux(resp_ex_preserved,
                                      Mux(io.in.bits.rd_mem, ExceptionCode.load_access_fault.U, ExceptionCode.store_AMO_access_fault.U), 
                                      0.U(32.W)))
}
