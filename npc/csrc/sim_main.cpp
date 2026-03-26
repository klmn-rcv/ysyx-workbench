#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VCPU.h"
#include "VCPU___024root.h"

#define MEM_SIZE 0x8000000

static vluint64_t main_time = 0;

// namespace {

// constexpr uint32_t kResetPc = 0x0;

// uint32_t encode_addi(uint32_t rd, uint32_t rs1, int32_t imm12) {
//   const uint32_t imm = static_cast<uint32_t>(imm12) & 0xfffU;
//   return (imm << 20) | ((rs1 & 0x1fU) << 15) | (0x0U << 12) | ((rd & 0x1fU) << 7) | 0x13U;
// }

// uint32_t encode_jalr(uint32_t rd, uint32_t rs1, int32_t imm12) {
//   const uint32_t imm = static_cast<uint32_t>(imm12) & 0xfffU;
//   return (imm << 20) | ((rs1 & 0x1fU) << 15) | (0x0U << 12) | ((rd & 0x1fU) << 7) | 0x67U;
// }

// // TODO: encode_ebreak
// uint32_t encode_ebreak() {
//   return 0x00100073U;
// }

// uint32_t pmem_read(const std::vector<uint32_t>& prog, uint32_t pc) {
//   if ((pc & 0x3U) != 0) {
//     std::fprintf(stderr, "[sim] unaligned fetch pc=0x%08x\n", pc);
//     return encode_addi(0, 0, 0);
//   }
//   const uint32_t idx = (pc - kResetPc) >> 2;
//   if (idx < prog.size()) {
//     return prog[idx];
//   }
//   return encode_addi(0, 0, 0);  // nop
// }

// }  // namespace

char pmem[MEM_SIZE];  // memory

// DPI-C function
static bool sim_end = false;
extern "C" void sim_halt() {
  sim_end = true;
}

extern "C" int pmem_read(int raddr) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  raddr &= ~0x3u;
  return *reinterpret_cast<int*>(pmem + raddr);
}
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  waddr &= ~0x3u;
  wmask &= 0xf;  // 长度为4位的掩码
  uint32_t byte_mask = 0;
  if (wmask & 0x1) byte_mask |= 0x000000FF;
  if (wmask & 0x2) byte_mask |= 0x0000FF00;
  if (wmask & 0x4) byte_mask |= 0x00FF0000;
  if (wmask & 0x8) byte_mask |= 0xFF000000;
  int *p = reinterpret_cast<int *>(pmem + waddr);
  *p = (*p & ~byte_mask) | (wdata & byte_mask);
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  auto* top = new VCPU;
  auto* tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open("wave.vcd");

  // Smoke program for 2-instruction stage.
  // 0x00: addi x1, x0, 4
  // 0x04: addi x2, x1, 8
  //// 0x08: jalr x0, x2, 0 (now commended)
  // 0x08: ebreak
  // std::vector<uint32_t> prog = {
  //   encode_addi(1, 0, 4),
  //   encode_addi(2, 1, 4),
  //   // encode_jalr(0, 2, 0),
  //   encode_ebreak()
  // };

  int cycles = 0;
  uint32_t inst_rsp = encode_addi(0, 0, 0);  // memory output register
  top->clock = 0;
  top->reset = 1;
  while (!sim_end) {
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
