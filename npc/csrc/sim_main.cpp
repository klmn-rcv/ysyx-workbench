#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include "sim.h"
#include "sdb.h"
#include "state.h"
#include "debug.h"


VTop* top = new VTop;
#ifdef GEN_TRACE
vluint64_t sim_time = 0;
VerilatedVcdC* tfp = new VerilatedVcdC;
#endif

char pmem[MEM_SIZE];  // memory

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

static void init_sim() {
  top->clock = 0;
  top->reset = 1;

  // 保持原来的两周期复位过程
  for (int i = 0; i < 2; i++) {
    top->clock = 0;
    top->eval();
#ifdef GEN_TRACE
    tfp->dump(sim_time++);
#endif

    top->clock = 1;
    top->eval();
#ifdef GEN_TRACE
    tfp->dump(sim_time++);
#endif
    npc_state.cycles++;
  }

  top->clock = 0;
  top->reset = 0;
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

  init_sdb();

  init_sim();

  sdb_mainloop();

  std::printf("[sim] %s at cycle=%lu, exit_code=%d\n", 
        npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
                             ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED),
        npc_state.cycles, npc_state.halt_ret);

#ifdef GEN_TRACE
  tfp->close();
  delete tfp;
#endif
  delete top;
  return 0;
}
