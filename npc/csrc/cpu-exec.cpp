#include <chrono>
#include <cstdio>
#include <locale.h>

#include "common.h"
#include "sim.h"
#include "sdb.h"
#include "state.h"
#include "debug.h"
#include "cpu-exec.h"

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

uint64_t g_nr_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

#ifdef CONFIG_ITRACE
Inst s;
#endif

static void trace_and_difftest() {
#ifdef CONFIG_ITRACE
  log_write("%s\n", s.logbuf);
#endif
  if (g_print_step && log_fp != stdout) { IFDEF(CONFIG_ITRACE, puts(s.logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(s.pc, dnpc));

#ifdef CONFIG_WATCHPOINT
  bool check_all_wp_no_change(int *NO, char **expr_str);
  int NO;  char *expr_str;
  bool no_change = check_all_wp_no_change(&NO, &expr_str);
  if(!no_change) {
    npc_state.state = NPC_STOP;
    printf("Hit watchpoint %d: %s\n", NO, expr_str);
  }
#endif
}

static void cycle_once() {
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
}

static void exec_once() {

  cycle_once();
  npc_state.cycles++;

#ifdef CONFIG_ITRACE
  char *p = s.logbuf;
  p += snprintf(p, sizeof(s.logbuf), FMT_WORD ":", s.pc);

  int i;
  uint8_t *inst = reinterpret_cast<uint8_t*>(&s.inst);
  for (i = 3; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  memset(p, ' ', 1);
  p += 1;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s.logbuf + sizeof(s.logbuf) - p,
      s.pc, reinterpret_cast<uint8_t*>(&s.inst), 4);
#endif
}

static void execute(uint64_t n) {
  for (;n > 0; n --) {
    exec_once();
    g_nr_inst++;
    trace_and_difftest();
    if (npc_state.state != NPC_RUNNING) break;
    // IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  Log("host time spent = %llu us", (unsigned long long)g_timer);
  Log("total guest instructions = %llu", (unsigned long long)g_nr_inst);
  if (g_timer > 0) {
    Log("simulation frequency = %llu inst/s",
        (unsigned long long)(g_nr_inst * 1000000 / g_timer));
  } else {
    Log("Finish running in less than 1 us and can not calculate the simulation frequency");
  }
}

extern "C" void assert_fail_msg() {
  reg_display();
  statistic();
#ifdef CONFIG_ITRACE
  // iringbuf_print();
#endif
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

  auto timer_start = std::chrono::steady_clock::now();

  execute(n);

  auto timer_end = std::chrono::steady_clock::now();
  g_timer += (uint64_t)std::chrono::duration_cast<std::chrono::microseconds>(timer_end - timer_start).count();

  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      Log("npc: %s at pc = " FMT_WORD,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          npc_state.halt_pc);
      // fall through
    case NPC_QUIT: statistic();
  }
}
