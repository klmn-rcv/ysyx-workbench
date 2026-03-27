#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VTop.h"


#define MEM_SIZE 0x20000000

static vluint64_t main_time = 0;

char pmem[MEM_SIZE];  // memory

// DPI-C function
static bool sim_end = false;
extern "C" void sim_halt() {
  sim_end = true;
}

extern "C" int pmem_read(int raddr) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  const uint32_t addr = static_cast<uint32_t>(raddr) & ~0x3u;
  assert(addr + 4 <= MEM_SIZE && "pmem_read out of bounds");
  return *reinterpret_cast<int*>(pmem + addr);
}
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  const uint32_t addr = static_cast<uint32_t>(waddr) & ~0x3u;
  assert(addr + 4 <= MEM_SIZE && "pmem_write out of bounds");
  wmask &= 0xf;  // 长度为4位的掩码
  uint32_t byte_mask = 0;
  if (wmask & 0x1) byte_mask |= 0x000000FF;
  if (wmask & 0x2) byte_mask |= 0x0000FF00;
  if (wmask & 0x4) byte_mask |= 0x00FF0000;
  if (wmask & 0x8) byte_mask |= 0xFF000000;
  int *p = reinterpret_cast<int *>(pmem + addr);
  *p = (*p & ~byte_mask) | (wdata & byte_mask);
}

static void load_binary_image(const char* path) {
  std::FILE* fp = std::fopen(path, "rb");
  if (fp == nullptr) {
    std::fprintf(stderr, "[sim] failed to open bin file: %s\n", path);
    std::exit(1);
  }

  const size_t n = std::fread(pmem, 1, MEM_SIZE, fp);
  if (std::ferror(fp)) {
    std::fprintf(stderr, "[sim] failed to read bin file: %s\n", path);
    std::fclose(fp);
    std::exit(1);
  }
  std::fclose(fp);
  std::printf("[sim] loaded %zu bytes from %s\n", n, path);
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  std::memset(pmem, 0, sizeof(pmem));
  load_binary_image("test/src/logisim-bin/sum.bin");

  pmem_write(0x224, 0x00100073U, 0xf); // 在halt指令处写入ebreak指令, 使仿真结束

  auto* top = new VTop;
  auto* tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open("wave.vcd");

  int cycles = 0;
  top->clock = 0;
  top->reset = 1;
  while (!sim_end) {
    top->clock = 0;
    top->eval();
    tfp->dump(main_time++);

    top->clock = 1;
    top->eval();
    tfp->dump(main_time++);

    if (cycles == 1) {
      top->reset = 0;
    }

    cycles++;
  }

  std::printf("[sim] finished at cycle=%d\n", cycles);

  tfp->close();
  delete tfp;
  delete top;
  return 0;
}
