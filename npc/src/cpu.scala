package cpu

import chisel3._
import chisel3.util._

object StageConnect {
    def apply[T <: Data](left: DecoupledIO[T], right: DecoupledIO[T], arch: String = "pipeline"): Unit = {
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

                val validReg = RegEnable(left.valid, false.B, left.ready)
                val bitsReg  = RegEnable(left.bits, 0.U.asTypeOf(chiselTypeOf(left.bits)), left.fire)

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
            val rinst = Input(UInt(32.W))
            val rdata = Input(UInt(32.W))
        }
        val out = new Bundle {
            val inst_req_valid = Output(Bool())
            val data_req_valid = Output(Bool())
            val wen = Output(Bool())
            val pc = Output(UInt(32.W))
            val raddr = Output(UInt(32.W))
            val waddr = Output(UInt(32.W))
            val wdata = Output(UInt(32.W))
            val wmask = Output(UInt(4.W))
        }
    })

    val ifu = Module(new IFU)
    val idu = Module(new IDU)
    val exu = Module(new EXU)
    val lsu = Module(new LSU)
    val wbu = Module(new WBU)
    val regfile = Module(new regfile)
    val csr = Module(new CSR)

    val arch = "single"  // 单周期

    // CPU core's output
    io.out.inst_req_valid := true.B
    io.out.data_req_valid := lsu.io.mem.data_req_valid
    io.out.wen := lsu.io.mem.wen
    io.out.pc := ifu.io.out.bits.dnpc
    io.out.raddr := lsu.io.mem.raddr
    io.out.waddr := lsu.io.mem.waddr
    io.out.wdata := lsu.io.mem.wdata
    io.out.wmask := lsu.io.mem.wmask

    // CSR's input
    csr.io.in.req := wbu.io.csr.csrReq

    // regfile's input
    regfile.io.in.raddr1 := idu.io.rf.rs1
    regfile.io.in.raddr2 := idu.io.rf.rs2
    regfile.io.in.we := wbu.io.rf.wb_we
    regfile.io.in.waddr := wbu.io.rf.wb_addr
    regfile.io.in.wdata := wbu.io.rf.wb_data

    // IFU's input
    ifu.io.ctrl.ex_redirect_valid := csr.io.out.redirect_valid
    ifu.io.ctrl.ex_redirect_target := csr.io.out.redirect_target
    ifu.io.ctrl.jump_valid := idu.io.ctrl.jump_valid
    ifu.io.ctrl.jump_target := idu.io.ctrl.jump_target
    ifu.io.ctrl.br_taken := exu.io.ctrl.br_taken
    ifu.io.ctrl.br_target := exu.io.ctrl.br_target

    // IDU's input
    StageConnect(ifu.io.out, idu.io.in, arch)
    idu.io.inst := io.in.rinst
    idu.io.rf.rdata1 := regfile.io.out.rdata1
    idu.io.rf.rdata2 := regfile.io.out.rdata2

    // EXU's input
    StageConnect(idu.io.out, exu.io.in, arch)

    // LSU's input
    StageConnect(exu.io.out, lsu.io.in, arch)
    lsu.io.mem.rdata := io.in.rdata

    // WBU's input
    StageConnect(lsu.io.out, wbu.io.in, arch)
    wbu.io.csr.priv := csr.io.out.priv
    wbu.io.csr.csrResp := csr.io.out.resp

    csr.io.in.wb_ex := wbu.io.csr.wb_ex
    csr.io.in.wb_cause := wbu.io.csr.wb_cause
    csr.io.in.wb_pc := wbu.io.csr.wb_pc
    csr.io.in.mret := wbu.io.csr.mret
}
