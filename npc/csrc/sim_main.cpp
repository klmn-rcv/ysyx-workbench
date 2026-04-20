#include "common.h"
#include "sim.h"
#include "sdb.h"
#include "state.h"
#include "debug.h"
#include "difftest.h"

VTop* top = new VTop;
#ifdef CONFIG_GEN_WAVE
vluint64_t sim_time = 0;
VerilatedVcdC* tfp = new VerilatedVcdC;
#endif

void init_disasm();
void sdb_set_batch_mode();

char pmem[MEM_SIZE];  // memory

static const char *img_file = NULL;
static const char *log_file = NULL;
static const char *elf_file = NULL;
static const char *diff_so_file = NULL;
static int difftest_port = 1234;

static long load_image(const char* path) {
  std::FILE* fp = std::fopen(path, "rb");
  if (fp == nullptr) {
    std::fprintf(stderr, "[sim] failed to open bin file: %s\n", path);
    std::exit(1);
  }

  const long n = std::fread(pmem, 1, MEM_SIZE, fp);
  if (std::ferror(fp)) {
    std::fprintf(stderr, "[sim] failed to read bin file: %s\n", path);
    std::fclose(fp);
    std::exit(1);
  }
  std::fclose(fp);
  printf("[sim] loaded %ld bytes from %s\n", n, path);
  return n;
}

static void init_sim() {
  top->clock = 0;
  top->reset = 1;

  // 保持原来的两周期复位过程
  for (int i = 0; i < 2; i++) {
    top->clock = 0;
    top->eval();
#ifdef CONFIG_GEN_WAVE
    tfp->dump(sim_time++);
#endif

    top->clock = 1;
    top->eval();
#ifdef CONFIG_GEN_WAVE
    tfp->dump(sim_time++);
#endif
    npc_state.cycles++;
  }

  top->clock = 0;
  top->reset = 0;

//   // Run one cycle after releasing reset so the IFU updates PC to the
//   // first valid instruction address before interactive execution starts.
//   top->clock = 0;
//   top->eval();
// #ifdef CONFIG_GEN_WAVE
//   tfp->dump(sim_time++);
// #endif

//   top->clock = 1;
//   top->eval();
// #ifdef CONFIG_GEN_WAVE
//   tfp->dump(sim_time++);
// #endif
//   npc_state.cycles++;
}

static void parse_args(int argc, char** argv) {
  const char *prefix_log = "--log=";
  const char *prefix_elf = "--elf=";
  const char *prefix_diff = "--diff=";
  const char *str_batch = "--batch";

  for (int i = 1; i < argc; i++) {
    const char *arg = argv[i];
    if (strncmp(arg, prefix_log, strlen(prefix_log)) == 0) {
      log_file = arg + strlen(prefix_log);
      assert(*log_file != '\0');
    }
    else if (strncmp(arg, prefix_elf, strlen(prefix_elf)) == 0) {
      elf_file = arg + strlen(prefix_elf);
      assert(*elf_file != '\0');
    }
    else if (strncmp(arg, prefix_diff, strlen(prefix_diff)) == 0) {
      diff_so_file = arg + strlen(prefix_diff);
      assert(*diff_so_file != '\0');
    }
    else if (strcmp(arg, str_batch) == 0) {
      sdb_set_batch_mode();
    }
    else {
      assert(img_file == NULL && "Only one binary image is allowed");
      img_file = arg;
    }
  }

  assert(img_file != NULL && "Usage: sim <binary_image> [--log=<log_file>] [--elf=<elf_file>] [--diff=<diff_so_file>]");
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
#ifdef CONFIG_GEN_WAVE
  Verilated::traceEverOn(true);
  top->trace(tfp, 99);
  tfp->open("wave.vcd");
#endif

  parse_args(argc, argv);

  init_log(log_file);

  std::memset(pmem, 0, sizeof(pmem));

  long img_size = load_image(img_file);

#ifdef CONFIG_FTRACE
  init_ftrace(elf_file);
#endif

  init_sim();

  IFDEF(CONFIG_DIFFTEST, init_difftest(diff_so_file, img_size, difftest_port));

  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());

  sdb_mainloop();

  printf("[sim] %s at cycle=%lu, exit_code=%d\n", 
        npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
                             ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED),
        npc_state.cycles, npc_state.halt_ret);

#ifdef CONFIG_GEN_WAVE
  tfp->close();
  delete tfp;
#endif
  delete top;
  return 0;
}
