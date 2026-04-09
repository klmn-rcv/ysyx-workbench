/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <dlfcn.h>
#include "difftest.h"
#include "debug.h"
#include "state.h"
#include "sdb.h"

extern char pmem[];

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef CONFIG_DIFFTEST

template <typename T>
static inline T load_difftest_symbol(void *handle, const char *symbol) {
  return reinterpret_cast<T>(dlsym(handle, symbol));
}

static const paddr_t RESET_VECTOR = 0x80000000;

void init_difftest(const char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = load_difftest_symbol<decltype(ref_difftest_memcpy)>(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = load_difftest_symbol<decltype(ref_difftest_regcpy)>(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = load_difftest_symbol<decltype(ref_difftest_exec)>(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = load_difftest_symbol<decltype(ref_difftest_raise_intr)>(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = load_difftest_symbol<void (*)(int)>(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, pmem, img_size, DIFFTEST_TO_REF);

  CPU_state cpu;
  update_cpu_state(&cpu);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static bool difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  CPU_state cpu;
  CPU_state *dut_r = &cpu;
  update_cpu_state(dut_r);
  int gpr_num = MUXDEF(CONFIG_RVE, 16, 32);
  for (int i = 0; i < gpr_num; i++) {
    if (dut_r->gpr[i] != ref_r->gpr[i]) {
      Log(ANSI_FG_RED "Difftest: gpr %d mismatch (dut: " FMT_WORD ", ref: " FMT_WORD ")" ANSI_NONE, i, dut_r->gpr[i], ref_r->gpr[i]);
      return false;
    }
  }
  if(dut_r->pc != ref_r->pc) {
    Log(ANSI_FG_RED "Difftest: pc mismatch (dut: " FMT_WORD ", ref: " FMT_WORD ")" ANSI_NONE, dut_r->pc, ref_r->pc);
    return false;
  }
  return true;
}

static void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    Log(ANSI_FG_RED "Difftest: Failed at pc = " FMT_WORD ANSI_NONE, pc);
    reg_display();
    IFDEF(CONFIG_ITRACE, iringbuf_print());
  }
}

void difftest_step(vaddr_t pc) {
  CPU_state ref_r;

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r, pc);
}
#else
void init_difftest(const char *ref_so_file, long img_size, int port) { }
#endif
