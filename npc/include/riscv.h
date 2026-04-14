#ifndef __RISCV_H__
#define __RISCV_H__

#include "common.h"

word_t get_gpr(int i);
word_t get_pc();
word_t get_csr_by_name(const char *name);
word_t get_priv();

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  word_t mstatus, mepc, mcause, mtvec;
  word_t priv;  // current privilege mode
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

typedef MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state) CPU_state;

static inline void update_cpu_state(CPU_state *s) {
  for (int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {
    s->gpr[i] = get_gpr(i);
  }
  s->pc = get_pc();
  s->mstatus = get_csr_by_name("mstatus");
  s->mepc = get_csr_by_name("mepc");
  s->mcause = get_csr_by_name("mcause");
  s->mtvec = get_csr_by_name("mtvec");
  s->priv = get_priv();
}


#endif
