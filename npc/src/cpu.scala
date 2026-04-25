package cpu

import chisel3._
import chisel3.util._

object StageConnect {
    def apply[T <: Data](left: DecoupledIO[T], right: DecoupledIO[T], arch: String = "pipeline", flush: Bool = false.B): Unit = {
        arch match {
            case "single" =>
                right.bits  := left.bits
                right.valid := left.valid
                left.ready  := true.B

            case "multi" =>
                right.bits  := left.bits
                right.valid := left.valid
                left.ready  := right.ready

            case "pipeline" =>
                left.ready := right.ready

                val validReg = RegInit(false.B)
                val bitsReg  = RegEnable(left.bits, 0.U.asTypeOf(chiselTypeOf(left.bits)), left.fire)

                val (flush_preserved, _) = bool_preserve(flush, left.fire, false.B)
                val flush_next_cycle = flush_preserved && !left.fire

                when(left.ready) {
                    validReg := left.valid && !flush_next_cycle
                }

                right.valid := validReg
                right.bits  := bitsReg

            case _ =>
                throw new IllegalArgumentException(s"unknown arch: $arch")
        }
    }
}

class CPU extends Module {
    val io = IO(new Bundle {
        val inst_mem_axi = new AXI4Lite(32, 32)
        val data_mem_axi = new AXI4Lite(32, 32)
    })

    val ifu = Module(new IFU)
    val iwu = Module(new IWU)
    val idu = Module(new IDU)
    val exu = Module(new EXU)
    val lsu = Module(new LSU)
    val lswu = Module(new LSWU)
    val wbu = Module(new WBU)
    val regfile = Module(new regfile)
    val csr = Module(new CSR)

    val arch = "pipeline"  // 流水线
    
    val isRAW = Wire(Bool())

    // CPU core's output
    // instruction memory AXI
    io.inst_mem_axi.ar <> ifu.io.mem.ar
    io.inst_mem_axi.r <> iwu.io.mem.r
    io.inst_mem_axi.aw <> ifu.io.mem.aw
    io.inst_mem_axi.w <> ifu.io.mem.w
    io.inst_mem_axi.b <> iwu.io.mem.b
    // data memory AXI
    io.data_mem_axi.ar <> lsu.io.mem.ar
    io.data_mem_axi.r <> lswu.io.mem.r
    io.data_mem_axi.aw <> lsu.io.mem.aw
    io.data_mem_axi.w <> lsu.io.mem.w
    io.data_mem_axi.b <> lswu.io.mem.b

    // CSR's input
    csr.io.in.req := wbu.io.csr.csrReq
    csr.io.in.wb_ex := wbu.io.csr.wb_ex
    csr.io.in.wb_cause := wbu.io.csr.wb_cause
    csr.io.in.wb_pc := wbu.io.csr.wb_pc
    csr.io.in.mret := wbu.io.csr.mret

    // regfile's input
    regfile.io.in.raddr1 := idu.io.rf.rs1
    regfile.io.in.raddr2 := idu.io.rf.rs2
    regfile.io.in.we := wbu.io.rf.wb_we
    regfile.io.in.waddr := wbu.io.rf.wb_addr
    regfile.io.in.wdata := wbu.io.rf.wb_data

    // IFU's input
    ifu.io.ctrl.ex_redirect_valid := wbu.io.ctrl.ex_redirect_valid
    ifu.io.ctrl.ex_redirect_target := wbu.io.ctrl.ex_redirect_target
    ifu.io.ctrl.jump_valid := idu.io.ctrl.jump_valid
    ifu.io.ctrl.jump_target := idu.io.ctrl.jump_target
    ifu.io.ctrl.br_taken := exu.io.ctrl.br_taken
    ifu.io.ctrl.br_target := exu.io.ctrl.br_target
    ifu.io.ctrl.ex_found := idu.io.ctrl.ex_found

    // IWU's input
    StageConnect(ifu.io.out, iwu.io.in, arch) // IWU不能flush
    iwu.io.flush.br_taken := exu.io.ctrl.br_taken
    iwu.io.flush.jump_valid := idu.io.ctrl.jump_valid
    iwu.io.flush.ex_found := idu.io.ctrl.ex_found
    
    // IDU's input
    StageConnect(iwu.io.out, idu.io.in, arch, idu.io.flush.flush)
    idu.io.rf.rdata1 := regfile.io.out.rdata1
    idu.io.rf.rdata2 := regfile.io.out.rdata2
    idu.io.raw_info.isRAW := isRAW
    idu.io.flush.br_taken := exu.io.ctrl.br_taken

    // EXU's input
    StageConnect(idu.io.out, exu.io.in, arch)

    // LSU's input
    StageConnect(exu.io.out, lsu.io.in, arch) // LSU不能flush

    // LSWU's input
    StageConnect(lsu.io.out, lswu.io.in, arch) // LSWU不能flush

    // WBU's input
    StageConnect(lswu.io.out, wbu.io.in, arch, wbu.io.flush.flush)
    wbu.io.csr.priv := csr.io.out.priv
    wbu.io.csr.csrResp := csr.io.out.resp
    wbu.io.csr.mtvec := csr.io.out.mtvec
    wbu.io.csr.mepc := csr.io.out.mepc

    // pipeline RAW hazard
    val exuHazardInfo = Wire(new RAWHazardInfo)
    exuHazardInfo.valid := exu.io.in.valid && !exu.io.flush.flush
    exuHazardInfo.wr_reg := exu.io.in.bits.wr_reg
    exuHazardInfo.rd := exu.io.in.bits.rd
    val lsuHazardInfo = Wire(new RAWHazardInfo)
    lsuHazardInfo.valid := lsu.io.in.valid // && !lsu.io.flush.flush  // LSU不能flush
    lsuHazardInfo.wr_reg := lsu.io.in.bits.wr_reg
    lsuHazardInfo.rd := lsu.io.in.bits.rd
    val lswuHazardInfo = Wire(new RAWHazardInfo)
    lswuHazardInfo.valid := lswu.io.in.valid // && !lswu.io.flush.flush  // LSWU不能flush
    lswuHazardInfo.wr_reg := lswu.io.in.bits.wr_reg
    lswuHazardInfo.rd := lswu.io.in.bits.rd
    val wbuHazardInfo = Wire(new RAWHazardInfo)
    wbuHazardInfo.valid := wbu.io.in.valid && !wbu.io.flush.flush
    wbuHazardInfo.wr_reg := wbu.io.in.bits.wr_reg
    wbuHazardInfo.rd := wbu.io.in.bits.rd
    isRAW := RAWConflictWithStage(idu.io.rf.rs1, idu.io.raw_info.needRs1, idu.io.rf.rs2, idu.io.raw_info.needRs2, exuHazardInfo) ||
             RAWConflictWithStage(idu.io.rf.rs1, idu.io.raw_info.needRs1, idu.io.rf.rs2, idu.io.raw_info.needRs2, lsuHazardInfo) ||
             RAWConflictWithStage(idu.io.rf.rs1, idu.io.raw_info.needRs1, idu.io.rf.rs2, idu.io.raw_info.needRs2, lswuHazardInfo) ||
             RAWConflictWithStage(idu.io.rf.rs1, idu.io.raw_info.needRs1, idu.io.rf.rs2, idu.io.raw_info.needRs2, wbuHazardInfo)
}
