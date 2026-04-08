#ifndef __RISCV_H__
#define __RISCV_H__

#include "common.h"

word_t get_gpr(int i);
word_t get_pc();

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

typedef MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state) CPU_state;

static inline void update_cpu_state(CPU_state *s) {
  for (int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {
    s->gpr[i] = get_gpr(i);
  }
  s->pc = get_pc();
}


#endif
