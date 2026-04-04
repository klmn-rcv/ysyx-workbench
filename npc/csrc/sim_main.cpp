#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <chrono>

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VTop.h"

// #define GEN_TRACE

#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

#define MEM_SIZE 0x10000000

static vluint64_t main_time = 0;
static uint64_t rtc_snapshot = 0; // 防止直接读main_time可能导致的高32位和低32位不一致
static auto boot_time = std::chrono::steady_clock::now();
static const uint32_t start_pc = 0x80000000;
static auto* top = new VTop;
#ifdef GEN_TRACE
static auto* tfp = new VerilatedVcdC;
#endif

char pmem[MEM_SIZE];  // memory

// DPI-C function
static bool sim_end = false;
static int sim_exit_code = 0;
extern "C" void sim_halt(int exit_code) {
  sim_end = true;
  sim_exit_code = exit_code;
}

extern "C" int pmem_read(int raddr) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  if (raddr == 0x10000004) { // 时钟低32位
    return static_cast<uint32_t>(rtc_snapshot);
  }
  if (raddr == 0x10000008) { // 时钟高32位
    auto now = std::chrono::steady_clock::now();
    rtc_snapshot = std::chrono::duration_cast<std::chrono::microseconds>(now - boot_time).count();
    return static_cast<uint32_t>(rtc_snapshot >> 32);
  }
  const uint32_t mem_addr = static_cast<uint32_t>(raddr - start_pc) & ~0x3u;
  if(mem_addr + 4 > MEM_SIZE) {
    printf("[sim] pmem_read out of bounds at address 0x%x\n", mem_addr);
    assert(false);
  }
  // assert(mem_addr + 4 <= MEM_SIZE && "pmem_read out of bounds");
  return *reinterpret_cast<int*>(pmem + mem_addr);
}
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  if(waddr == 0x10000000) { // 串口
    putchar(wdata & 0xFF);
    return;
  }
  const uint32_t mem_addr = static_cast<uint32_t>(waddr - start_pc) & ~0x3u;
  if (mem_addr + 4 > MEM_SIZE) {
    printf("[sim] pmem_write out of bounds at address 0x%x\n", mem_addr);
    assert(false);
  }
  wmask &= 0xf;  // 长度为4位的掩码
  uint32_t byte_mask = 0;
  if (wmask & 0x1) byte_mask |= 0x000000FF;
  if (wmask & 0x2) byte_mask |= 0x0000FF00;
  if (wmask & 0x4) byte_mask |= 0x00FF0000;
  if (wmask & 0x8) byte_mask |= 0xFF000000;
  int *p = reinterpret_cast<int *>(pmem + mem_addr);
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

  if (argc < 2) {
    assert(false && "Usage: sim <binary_image>");
  }

  std::memset(pmem, 0, sizeof(pmem));
  load_binary_image(argv[1]);

  // pmem_write(0x1218, 0x00100073U, 0xf); // 在halt指令处写入ebreak指令, 使仿真结束

#ifdef GEN_TRACE
  top->trace(tfp, 99);
  tfp->open("wave.vcd");
#endif

  int cycles = 0;
  top->clock = 0;
  top->reset = 1;

  // 仿真主循环
  while (!sim_end) {
    top->clock = 0;
    top->eval();
#ifdef GEN_TRACE
    tfp->dump(main_time++);
#endif

    top->clock = 1;
    top->eval();
#ifdef GEN_TRACE
    tfp->dump(main_time++);
#endif

    if (cycles == 1) {
      top->reset = 0;
    }

    cycles++;
  }

  std::printf("[sim] %s at cycle=%d, exit_code=%d\n", 
        sim_exit_code == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
                             ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED),
        cycles, sim_exit_code);

#ifdef GEN_TRACE
  tfp->close();
  delete tfp;
#endif
  delete top;
  return 0;
}
