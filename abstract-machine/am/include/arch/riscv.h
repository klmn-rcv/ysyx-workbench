#ifndef ARCH_H__
#define ARCH_H__

#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

struct Context {
  // now the order of these members matches trap.S
  uintptr_t gpr[NR_REGS], mcause, mstatus, mepc;
  void *pdir;  // trap.S里没有这个成员，所以这里有潜在问题，但为了编译通过，必须先保持原样
};

#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif

#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]

#endif
