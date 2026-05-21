package ysyx

import chisel3._
import chisel3.util._
import chisel3.experimental.Analog

import freechips.rocketchip.amba.axi4._
import freechips.rocketchip.amba.apb._
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.util._

class SDRAMIO extends Bundle {
  val clk = Output(Bool())
  val cke = Output(Bool())
  val cs  = Output(Bool())
  val ras = Output(Bool())
  val cas = Output(Bool())
  val we  = Output(Bool())
  val a   = Output(UInt(13.W))
  val ba  = Output(UInt(2.W))
  val dqm = Output(UInt(2.W))
  val dq  = Analog(16.W)
}

class sdram_top_axi extends BlackBox {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Bool())
    val in = Flipped(new AXI4Bundle(AXI4BundleParameters(addrBits = 32, dataBits = 32, idBits = 4)))
    val sdram = new SDRAMIO
  })
}

class sdram_top_apb extends BlackBox {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Bool())
    val in = Flipped(new APBBundle(APBBundleParameters(addrBits = 32, dataBits = 32)))
    val sdram = new SDRAMIO
  })
}

class sdram extends BlackBox {
  val io = IO(Flipped(new SDRAMIO))
}

class sdramChisel extends RawModule {
  val io = IO(Flipped(new SDRAMIO))
  val reset = IO(Input(Reset()))

  val dq_out = WireDefault(0.U(16.W))
  val dq_out_en = WireDefault(0.U(2.W))
  val dq_in = TriStateInBufVecEn(io.dq, dq_out, dq_out_en)

  withClockAndReset(io.clk.asClock, reset) {
    val BANK_COUNT = 4
    val BANK_ROW_COUNT = 8192
    val BANK_COL_COUNT = 512
    val BANK_ADDR_LEN = 2
    val ROW_ADDR_LEN = 13
    val COL_ADDR_LEN = 9
    val DQM_READ_LATENCY = 2

    object Cmd {
      // val CommandInhibit = BitPat("b1???")
      val Nop = "b0111".U(4.W)
      val Active = "b0011".U(4.W)
      val Read = "b0101".U(4.W)
      val Write = "b0100".U(4.W)
      val BurstTerminate = "b0110".U(4.W)
      val Precharge = "b0010".U(4.W)
      val AutoRefresh = "b0001".U(4.W)
      val LoadMode = "b0000".U(4.W)
    }

    class Mode extends Bundle {
      val mode_loaded = RegInit(false.B)
      val burst_length = RegInit(2.U(4.W))      // bit 0-2
      val burst_type = RegInit(0.U(1.W))        // bit 3
      val cas_latency = RegInit(2.U(3.W))       // bit 4-6
      val operating_mode = RegInit(0.U(2.W))    // bit 7-8
      val write_burst_mode = RegInit(0.U(1.W))  // bit 9
    }

    val mode = new Mode

    val bank_mem = Seq.fill(BANK_COUNT)(Mem(BANK_ROW_COUNT * BANK_COL_COUNT, UInt(16.W)))
    val bank_row_buffer = RegInit(VecInit(Seq.fill(BANK_COUNT)(VecInit(Seq.fill(BANK_COL_COUNT)(0.U(16.W))))))

    val bank_active_row = RegInit(VecInit(Seq.fill(BANK_COUNT)(0.U(ROW_ADDR_LEN.W))))
    val bank_active_row_valid = RegInit(VecInit(Seq.fill(BANK_COUNT)(false.B)))

    val bank_burst_col = RegInit(VecInit(Seq.fill(BANK_COUNT)(0.U(COL_ADDR_LEN.W))))
    val bank_read_wait_cnt = RegInit(VecInit(Seq.fill(BANK_COUNT)(0.U(3.W))))
    val bank_read_cnt = RegInit(VecInit(Seq.fill(BANK_COUNT)(0.U(4.W))))
    val bank_write_cnt = RegInit(VecInit(Seq.fill(BANK_COUNT)(0.U(4.W))))

    val read_dqm_q = RegInit(VecInit(Seq.fill(DQM_READ_LATENCY)(0.U(2.W))))

    val cmd = Cat(io.cs, io.ras, io.cas, io.we)

    object BankFSM {
      object BankState extends ChiselEnum {
        val Idle, Open, ReadWait, ReadData, WriteData = Value
      }

      val state = RegInit(VecInit(Seq.fill(BANK_COUNT)(BankState.Idle)))

      val active_start = WireDefault(VecInit(Seq.fill(BANK_COUNT)(false.B)))
      val read_start = WireDefault(VecInit(Seq.fill(BANK_COUNT)(false.B)))
      val write_start = WireDefault(VecInit(Seq.fill(BANK_COUNT)(false.B)))
      val terminate = WireDefault(VecInit(Seq.fill(BANK_COUNT)(false.B)))
      val precharge_one = WireDefault(VecInit(Seq.fill(BANK_COUNT)(false.B)))
      val precharge_all = WireDefault(false.B)
      val read_wait_done = WireDefault(VecInit(Seq.fill(BANK_COUNT)(false.B)))
      val read_data_done = WireDefault(VecInit(Seq.fill(BANK_COUNT)(false.B)))
      val write_data_done = WireDefault(VecInit(Seq.fill(BANK_COUNT)(false.B)))

      when(io.cke) {
        for (bank_idx <- 0 until BANK_COUNT) {
          when(precharge_all) {
            state(bank_idx) := BankState.Idle
          }.otherwise {
            switch(state(bank_idx)) {
              is(BankState.Idle) {
                when(active_start(bank_idx)) {
                  state(bank_idx) := BankState.Open
                }
              }

              is(BankState.Open) {
                when(read_start(bank_idx)) {
                  when(mode.cas_latency === 1.U) {
                    state(bank_idx) := BankState.ReadData
                  }.otherwise {
                    state(bank_idx) := BankState.ReadWait
                  }
                }.elsewhen(write_start(bank_idx)) {
                  when(mode.burst_length === 1.U) {
                    state(bank_idx) := BankState.Open
                  }.otherwise {
                    state(bank_idx) := BankState.WriteData
                  }
                }.elsewhen(precharge_one(bank_idx)) {
                  state(bank_idx) := BankState.Idle
                }
              }

              is(BankState.ReadWait) {
                when(terminate(bank_idx)) {
                  state(bank_idx) := BankState.Open
                }.elsewhen(read_wait_done(bank_idx)) {
                  state(bank_idx) := BankState.ReadData
                }
              }

              is(BankState.ReadData) {
                when(terminate(bank_idx) || read_data_done(bank_idx)) {
                  state(bank_idx) := BankState.Open
                }
              }

              is(BankState.WriteData) {
                when(terminate(bank_idx) || write_data_done(bank_idx)) {
                  state(bank_idx) := BankState.Open
                }
              }
            }
          }
        }
      }
    }

    val precharge_one_cmd_fire = WireDefault(false.B)
    val precharge_all_cmd_fire = WireDefault(false.B)

    for (bank_idx <- 0 until BANK_COUNT) {
      val bank_selected = io.ba === bank_idx.U

      BankFSM.active_start(bank_idx) := cmd === Cmd.Active && bank_selected
      BankFSM.read_start(bank_idx) := cmd === Cmd.Read && bank_selected
      BankFSM.write_start(bank_idx) := cmd === Cmd.Write && bank_selected
      BankFSM.terminate(bank_idx) := cmd === Cmd.BurstTerminate && bankIsBusy(BankFSM.state(bank_idx))
      BankFSM.precharge_one(bank_idx) := precharge_one_cmd_fire && bank_selected
      BankFSM.read_wait_done(bank_idx) :=
        BankFSM.state(bank_idx) === BankFSM.BankState.ReadWait &&
        bank_read_wait_cnt(bank_idx) === 1.U
      BankFSM.read_data_done(bank_idx) :=
        BankFSM.state(bank_idx) === BankFSM.BankState.ReadData &&
        bank_read_cnt(bank_idx) === 1.U
      BankFSM.write_data_done(bank_idx) :=
        BankFSM.state(bank_idx) === BankFSM.BankState.WriteData &&
        bank_write_cnt(bank_idx) === 1.U
    }
    BankFSM.precharge_all := precharge_all_cmd_fire

    def bankIsBusy(state: BankFSM.BankState.Type): Bool = {
      state === BankFSM.BankState.ReadWait ||
      state === BankFSM.BankState.ReadData ||
      state === BankFSM.BankState.WriteData
    }

    def decodeBurstLen(a: UInt): UInt = {
      val code = a(2, 0)
      assert(code === "b000".U || code === "b001".U || code === "b010".U || code === "b011".U, "Unsupported SDRAM burst length")
      MuxLookup(code, 0.U(4.W))(Seq(
        "b000".U -> 1.U(4.W),
        "b001".U -> 2.U(4.W),
        "b010".U -> 4.U(4.W),
        "b011".U -> 8.U(4.W)
      ))
    }

    def bankRc2FlatAddr(row_addr: UInt, col_addr: UInt): UInt = Cat(row_addr, col_addr)

    def loadRowBuffer(bank_sel: UInt, row_addr: UInt): Unit = {
      for (bank_idx <- 0 until BANK_COUNT) {
        when(bank_sel === bank_idx.U) {
          for (col_idx <- 0 until BANK_COL_COUNT) {
            bank_row_buffer(bank_idx)(col_idx) := bank_mem(bank_idx)(bankRc2FlatAddr(row_addr, col_idx.U))
          }
        }
      }
      bank_active_row(io.ba) := io.a
      bank_active_row_valid(io.ba) := true.B
    }

    def readRowBufferByCol(bank_sel: UInt, col_addr: UInt): UInt = {
      val data_vec = VecInit((0 until BANK_COUNT).map(i => bank_row_buffer(i)(col_addr)))
      Mux1H((0 until BANK_COUNT).map(i => (bank_sel === i.U) -> data_vec(i)))
    }

    def writeOpenRowByCol(bank_sel: UInt, col_addr: UInt, data: UInt, dqm: UInt): Unit = {
      val old_data = readRowBufferByCol(bank_sel, col_addr)
      val new_data = Cat(
        Mux(dqm(1), old_data(15, 8), data(15, 8)),
        Mux(dqm(0), old_data(7, 0), data(7, 0))
      )

      for (bank_idx <- 0 until BANK_COUNT) {
        when(bank_sel === bank_idx.U) {
          bank_row_buffer(bank_idx)(col_addr) := new_data
          bank_mem(bank_idx).write(bankRc2FlatAddr(bank_active_row(bank_idx), col_addr), new_data)
        }
      }
    }

    val any_bank_busy = VecInit((0 until BANK_COUNT).map(i => bankIsBusy(BankFSM.state(i)))).asUInt.orR
    val all_banks_idle = VecInit((0 until BANK_COUNT).map(i => BankFSM.state(i) === BankFSM.BankState.Idle)).asUInt.andR

    val read_bank_oh = VecInit((0 until BANK_COUNT).map(i => BankFSM.state(i) === BankFSM.BankState.ReadData))
    val write_bank_oh = VecInit((0 until BANK_COUNT).map(i => BankFSM.state(i) === BankFSM.BankState.WriteData))

    assert(PopCount(read_bank_oh) <= 1.U, "Multiple SDRAM banks are in ReadData at the same time")
    assert(PopCount(write_bank_oh) <= 1.U, "Multiple SDRAM banks are in WriteData at the same time")

    val read_data_vec = Wire(Vec(BANK_COUNT, UInt(16.W)))
    for (bank_idx <- 0 until BANK_COUNT) {
      read_data_vec(bank_idx) := readRowBufferByCol(bank_idx.U, bank_burst_col(bank_idx))
    }

    when(read_bank_oh.asUInt.orR) {
      dq_out := Mux1H((0 until BANK_COUNT).map(i => read_bank_oh(i) -> read_data_vec(i)))
    }

    dq_out_en := Mux(
      read_bank_oh.asUInt.orR,
      Cat(
        !read_dqm_q(DQM_READ_LATENCY - 1)(1),
        !read_dqm_q(DQM_READ_LATENCY - 1)(0)
      ),
      0.U(2.W)
    )

    when(io.cke) {
      read_dqm_q(0) := io.dqm
      for (delay_idx <- 1 until DQM_READ_LATENCY) {
        read_dqm_q(delay_idx) := read_dqm_q(delay_idx - 1)
      }

      for (bank_idx <- 0 until BANK_COUNT) {
        when(BankFSM.state(bank_idx) === BankFSM.BankState.ReadWait) {
          when(bank_read_wait_cnt(bank_idx) =/= 1.U) {
            bank_read_wait_cnt(bank_idx) := bank_read_wait_cnt(bank_idx) - 1.U
          }
        }

        when(BankFSM.state(bank_idx) === BankFSM.BankState.ReadData) {
          when(bank_read_cnt(bank_idx) =/= 1.U) {
            bank_burst_col(bank_idx) := bank_burst_col(bank_idx) + 1.U
            bank_read_cnt(bank_idx) := bank_read_cnt(bank_idx) - 1.U
          }
        }

        when(BankFSM.state(bank_idx) === BankFSM.BankState.WriteData) {
          writeOpenRowByCol(bank_idx.U, bank_burst_col(bank_idx), dq_in, io.dqm)
          when(bank_write_cnt(bank_idx) =/= 1.U) {
            bank_burst_col(bank_idx) := bank_burst_col(bank_idx) + 1.U
            bank_write_cnt(bank_idx) := bank_write_cnt(bank_idx) - 1.U
          }
        }
      }
      when(io.cs) {
        // Command Inhibit
      }.otherwise {
        switch(cmd) {
          is(Cmd.Nop) {
          }

          is(Cmd.Active) {
            assert(mode.mode_loaded, "SDRAM ACTIVE before LOAD MODE REGISTER")
            assert(!any_bank_busy, "BankFSM does not accept ACTIVE during ongoing burst")
            assert(BankFSM.state(io.ba) === BankFSM.BankState.Idle, "SDRAM ACTIVE requires selected bank in Idle state")
            loadRowBuffer(io.ba, io.a)
          }

          is(Cmd.Read) {
            assert(mode.mode_loaded, "SDRAM READ before LOAD MODE REGISTER")
            assert(!any_bank_busy, "BankFSM does not accept overlapping READ/WRITE bursts")
            assert(io.a(10) === 0.U, "Auto-precharge READ is not modeled")
            assert(BankFSM.state(io.ba) === BankFSM.BankState.Open, "SDRAM READ requires selected bank in Open state")
            assert(bank_active_row_valid(io.ba), "SDRAM READ before ACTIVE")
            bank_read_wait_cnt(io.ba) := mode.cas_latency - 1.U
            bank_burst_col(io.ba) := io.a(8, 0)
            bank_read_cnt(io.ba) := mode.burst_length
          }

          is(Cmd.Write) {
            assert(mode.mode_loaded, "SDRAM WRITE before LOAD MODE REGISTER")
            assert(!any_bank_busy, "BankFSM does not accept overlapping READ/WRITE bursts")
            assert(io.a(10) === 0.U, "Auto-precharge WRITE is not modeled")
            assert(BankFSM.state(io.ba) === BankFSM.BankState.Open, "SDRAM WRITE requires selected bank in Open state")
            assert(bank_active_row_valid(io.ba), "SDRAM WRITE before ACTIVE")
            val first_col = io.a(8, 0)
            writeOpenRowByCol(io.ba, first_col, dq_in, io.dqm)

            when(mode.burst_length =/= 1.U) {
              bank_burst_col(io.ba) := first_col + 1.U
              bank_write_cnt(io.ba) := mode.burst_length - 1.U
            }
          }

          is(Cmd.BurstTerminate) {
          }

          is(Cmd.Precharge) {
            assert(!any_bank_busy, "BankFSM does not accept PRECHARGE during ongoing burst")
            when(io.a(10)) {
              precharge_all_cmd_fire := true.B
              bank_active_row_valid.foreach(_ := false.B)
            }.otherwise {
              assert(BankFSM.state(io.ba) === BankFSM.BankState.Open, "SDRAM PRECHARGE requires selected bank in Open state")
              precharge_one_cmd_fire := true.B
              bank_active_row_valid(io.ba) := false.B
            }
          }

          is(Cmd.AutoRefresh) {
            assert(!any_bank_busy, "BankFSM does not accept REFRESH during ongoing burst")
            assert(all_banks_idle, "SDRAM AUTO REFRESH requires all banks in Idle state")
          }

          is(Cmd.LoadMode) {
            assert(all_banks_idle, "SDRAM LOAD MODE REGISTER requires all banks in Idle state")
            assert(io.a(3) === 0.U, "Unimplemented SDRAM burst_type")
            assert(io.a(8, 7) === 0.U, "Unimplemented SDRAM operating_mode")
            assert(io.a(9) === 0.U, "Unimplemented SDRAM write_burst_mode")
            assert(io.a(12, 10) === 0.U, "Unimplemented SDRAM reserved mode bits")
            mode.burst_length := decodeBurstLen(io.a)
            mode.burst_type := io.a(3)
            mode.cas_latency := io.a(6, 4)
            mode.operating_mode := io.a(8, 7)
            mode.write_burst_mode := io.a(9)
            mode.mode_loaded := true.B
          }
        }
      }
    }
  }
}

class AXI4SDRAM(address: Seq[AddressSet])(implicit p: Parameters) extends LazyModule {
  val beatBytes = 4
  val node = AXI4SlaveNode(Seq(AXI4SlavePortParameters(
    Seq(AXI4SlaveParameters(
        address       = address,
        executable    = true,
        supportsWrite = TransferSizes(1, beatBytes),
        supportsRead  = TransferSizes(1, beatBytes),
        interleavedId = Some(0))
    ),
    beatBytes  = beatBytes)))

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {
    val (in, _) = node.in(0)
    val sdram_bundle = IO(new SDRAMIO)

    val msdram = Module(new sdram_top_axi)
    msdram.io.clock := clock
    msdram.io.reset := reset.asBool
    msdram.io.in <> in
    sdram_bundle <> msdram.io.sdram
  }
}

class APBSDRAM(address: Seq[AddressSet])(implicit p: Parameters) extends LazyModule {
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
    val sdram_bundle = IO(new SDRAMIO)

    val msdram = Module(new sdram_top_apb)
    msdram.io.clock := clock
    msdram.io.reset := reset.asBool
    msdram.io.in <> in
    sdram_bundle <> msdram.io.sdram
  }
}
