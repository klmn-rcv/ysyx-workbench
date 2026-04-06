#include "common.h"
#include "sim.h"
#include "sdb.h"
#include "state.h"
#include "debug.h"


VTop* top = new VTop;
#ifdef GEN_TRACE
vluint64_t sim_time = 0;
VerilatedVcdC* tfp = new VerilatedVcdC;
#endif

void init_disasm();

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
  printf("[sim] loaded %zu bytes from %s\n", n, path);
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

  // Run one cycle after releasing reset so the IFU updates PC to the
  // first valid instruction address before interactive execution starts.
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

static void process_args(int argc, char** argv) {
  const char *prefix = "--log=";
  const char *img_file = NULL;
  const char *log_file = NULL;

  for (int i = 1; i < argc; i++) {
    const char *arg = argv[i];
    if (strncmp(arg, prefix, strlen(prefix)) == 0) {
      log_file = arg + strlen(prefix);
      assert(*log_file != '\0');
    } 
    else {
      assert(img_file == NULL && "Only one binary image is allowed");
      img_file = arg;
    }
  }

  assert(img_file != NULL && "Usage: sim <binary_image> [--log=<log_file>]");

  std::memset(pmem, 0, sizeof(pmem));
  load_binary_image(img_file);
  init_log(log_file);
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
#ifdef GEN_TRACE
  Verilated::traceEverOn(true);
#endif

  process_args(argc, argv);

  // pmem_write(0x1218, 0x00100073U, 0xf); // 在halt指令处写入ebreak指令, 使仿真结束

#ifdef GEN_TRACE
  top->trace(tfp, 99);
  tfp->open("wave.vcd");
#endif

  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());

  init_sim();

  sdb_mainloop();

  printf("[sim] %s at cycle=%lu, exit_code=%d\n", 
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
