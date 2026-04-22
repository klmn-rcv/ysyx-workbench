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

                val flush_preserved = bool_preserve(flush, left.fire)
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
        val in = new Bundle {
            val inst_req_ready = Input(Bool())
            val data_req_ready = Input(Bool())
            val inst_resp_valid = Input(Bool())
            val data_resp_valid = Input(Bool())
            val rinst = Input(UInt(32.W))
            val rdata = Input(UInt(32.W))
        }
        val out = new Bundle {
            val inst_req_valid = Output(Bool())
            val data_req_valid = Output(Bool())
            val inst_resp_ready = Output(Bool())
            val data_resp_ready = Output(Bool())
            val wen = Output(Bool())
            val pc = Output(UInt(32.W))
            val raddr = Output(UInt(32.W))
            val waddr = Output(UInt(32.W))
            val wdata = Output(UInt(32.W))
            val wmask = Output(UInt(4.W))
        }
    })

    val ifu = Module(new IFU)
    val iwu = Module(new IWU)
    val idu = Module(new IDU)
    val exu = Module(new EXU)
    val lsau = Module(new LSAU)
    val lsdu = Module(new LSDU)
    val wbu = Module(new WBU)
    val regfile = Module(new regfile)
    val csr = Module(new CSR)

    val arch = "pipeline"  // 流水线
    
    val isRAW = Wire(Bool())

    // CPU core's output
    io.out.inst_req_valid := ifu.io.mem.inst_req_valid
    io.out.data_req_valid := lsau.io.mem.data_req_valid
    io.out.inst_resp_ready := iwu.io.mem.inst_resp_ready
    io.out.data_resp_ready := lsdu.io.mem.data_resp_ready
    io.out.wen := lsau.io.mem.wen
    io.out.pc := ifu.io.out_bypass.dnpc
    io.out.raddr := lsau.io.mem.raddr
    io.out.waddr := lsau.io.mem.waddr
    io.out.wdata := lsau.io.mem.wdata
    io.out.wmask := lsau.io.mem.wmask

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
    ifu.io.mem.inst_req_ready := io.in.inst_req_ready

    // IWU's input
    StageConnect(ifu.io.out, iwu.io.in, arch, iwu.io.flush.flush)
    iwu.io.in_bypass.pc := ifu.io.out_bypass.pc
    iwu.io.in_bypass.dnpc := ifu.io.out_bypass.dnpc
    iwu.io.mem.inst_resp_valid := io.in.inst_resp_valid
    iwu.io.mem.rinst := io.in.rinst
    iwu.io.flush.br_taken := exu.io.ctrl.br_taken
    iwu.io.flush.jump_valid := idu.io.ctrl.jump_valid

    // IDU's input
    StageConnect(iwu.io.out, idu.io.in, arch, idu.io.flush.flush)
    idu.io.rf.rdata1 := regfile.io.out.rdata1
    idu.io.rf.rdata2 := regfile.io.out.rdata2
    idu.io.raw_info.isRAW := isRAW
    idu.io.flush.br_taken := exu.io.ctrl.br_taken

    // EXU's input
    StageConnect(idu.io.out, exu.io.in, arch)

    // LSAU's input
    StageConnect(exu.io.out, lsau.io.in, arch)
    lsau.io.mem.data_req_ready := io.in.data_req_ready

    // LSDU's input
    StageConnect(lsau.io.out, lsdu.io.in, arch)
    lsdu.io.mem.data_resp_valid := io.in.data_resp_valid
    lsdu.io.mem.rdata := io.in.rdata

    // WBU's input
    StageConnect(lsdu.io.out, wbu.io.in, arch)
    wbu.io.csr.priv := csr.io.out.priv
    wbu.io.csr.csrResp := csr.io.out.resp
    wbu.io.csr.mtvec := csr.io.out.mtvec
    wbu.io.csr.mepc := csr.io.out.mepc

    // pipeline RAW hazard
    val exuHazardInfo = Wire(new RAWHazardInfo)
    exuHazardInfo.valid := exu.io.in.valid
    exuHazardInfo.wr_reg := exu.io.in.bits.wr_reg
    exuHazardInfo.rd := exu.io.in.bits.rd
    val lsauHazardInfo = Wire(new RAWHazardInfo)
    lsauHazardInfo.valid := lsau.io.in.valid
    lsauHazardInfo.wr_reg := lsau.io.in.bits.wr_reg
    lsauHazardInfo.rd := lsau.io.in.bits.rd
    val lsduHazardInfo = Wire(new RAWHazardInfo)
    lsduHazardInfo.valid := lsdu.io.in.valid
    lsduHazardInfo.wr_reg := lsdu.io.in.bits.wr_reg
    lsduHazardInfo.rd := lsdu.io.in.bits.rd
    val wbuHazardInfo = Wire(new RAWHazardInfo)
    wbuHazardInfo.valid := wbu.io.in.valid
    wbuHazardInfo.wr_reg := wbu.io.in.bits.wr_reg
    wbuHazardInfo.rd := wbu.io.in.bits.rd
    isRAW := RAWConflictWithStage(idu.io.rf.rs1, idu.io.raw_info.needRs1, idu.io.rf.rs2, idu.io.raw_info.needRs2, exuHazardInfo) ||
             RAWConflictWithStage(idu.io.rf.rs1, idu.io.raw_info.needRs1, idu.io.rf.rs2, idu.io.raw_info.needRs2, lsauHazardInfo) ||
             RAWConflictWithStage(idu.io.rf.rs1, idu.io.raw_info.needRs1, idu.io.rf.rs2, idu.io.raw_info.needRs2, lsduHazardInfo) ||
             RAWConflictWithStage(idu.io.rf.rs1, idu.io.raw_info.needRs1, idu.io.rf.rs2, idu.io.raw_info.needRs2, wbuHazardInfo)
}
