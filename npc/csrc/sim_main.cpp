#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VCPU.h"
#include "VCPU___024root.h"

static vluint64_t main_time = 0;
double sc_time_stamp() { return static_cast<double>(main_time); }

namespace {

constexpr uint32_t kResetPc = 0x0;
constexpr int kMaxCycles = 64;

uint32_t encode_addi(uint32_t rd, uint32_t rs1, int32_t imm12) {
  const uint32_t imm = static_cast<uint32_t>(imm12) & 0xfffU;
  return (imm << 20) | ((rs1 & 0x1fU) << 15) | (0x0U << 12) | ((rd & 0x1fU) << 7) | 0x13U;
}

uint32_t encode_jalr(uint32_t rd, uint32_t rs1, int32_t imm12) {
  const uint32_t imm = static_cast<uint32_t>(imm12) & 0xfffU;
  return (imm << 20) | ((rs1 & 0x1fU) << 15) | (0x0U << 12) | ((rd & 0x1fU) << 7) | 0x67U;
}

uint32_t pmem_read(const std::vector<uint32_t>& prog, uint32_t pc) {
  if ((pc & 0x3U) != 0) {
    std::fprintf(stderr, "[sim] unaligned fetch pc=0x%08x\n", pc);
    return encode_addi(0, 0, 0);
  }
  const uint32_t idx = (pc - kResetPc) >> 2;
  if (idx < prog.size()) {
    return prog[idx];
  }
  return encode_addi(0, 0, 0);  // nop
}

}  // namespace

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  auto* top = new VCPU;
  auto* tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open("wave.vcd");

  // Smoke program for 2-instruction stage.
  // 0x00: addi x1, x0, 1
  // 0x04: addi x2, x1, 2
  // 0x08: jalr x0, x0, 0   (jump back to 0x00)
  std::vector<uint32_t> prog = {
    encode_addi(1, 0, 1),
    encode_addi(2, 1, 2),
    encode_jalr(0, 0, 0),
  };

  int cycles = 0;
  uint32_t inst_rsp = encode_addi(0, 0, 0);  // memory output register
  top->clock = 0;
  top->reset = 1;
  while (!Verilated::gotFinish() && cycles < kMaxCycles) {
    top->clock = 0;     // negedge
    top->eval();
    tfp->dump(main_time++);
    
    inst_rsp = pmem_read(prog, static_cast<uint32_t>(top->io_pc)); // just at the posedge

    top->clock = 1;     // posedge
    top->eval();
    top->io_inst = inst_rsp;      // input signal after the posedge
    top->eval();
    tfp->dump(main_time++);

    if (cycles == 1) {
      top->reset = 0;
    }

    cycles++;
  }

  std::printf("[sim] finished at cycle=%d pc=0x%08x\n", cycles, static_cast<uint32_t>(top->io_pc));

  tfp->close();
  delete tfp;
  delete top;
  return 0;
}
