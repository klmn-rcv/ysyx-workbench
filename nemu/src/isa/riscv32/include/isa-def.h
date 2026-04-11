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

#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  word_t mstatus, mepc, mcause, mtvec;
  word_t priv;  // current privilege mode
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

// decode
typedef struct {
  uint32_t inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

#define U_MODE       0
#define S_MODE       1
#define M_MODE       3

// CSR number in CSR instructions
#define MSTATUS      0x300
#define MTVEC        0x305
#define MEPC         0x341
#define MCAUSE       0x342

// these are field masks
#define MSTATUS_MIE  0x00000008
#define MSTATUS_MPIE 0x00000080
#define MSTATUS_MPP  0x00001800

static inline int mask2shift(word_t mask) {
  int shift = 0;
  while (((mask >> shift) & 1) == 0) shift++;
  return shift;
}

#define CSR_READ(reg, field) (((reg) & (field)) >> mask2shift(field))
#define CSR_WRITE(reg, field, val) \
  do { \
    int __shift = mask2shift(field); \
    (reg) = ((reg) & ~(field)) | ((((word_t)(val)) << __shift) & (field)); \
  } while (0)


/* Exception/Interrupt code */
#define MCAUSE_ECALL_FROM_U  8
#define MCAUSE_ECALL_FROM_S  9
#define MCAUSE_ECALL_FROM_M  11

#endif
