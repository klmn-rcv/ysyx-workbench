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

#define MSTATUS_MIE_SHIFT       3
#define MSTATUS_MPIE_SHIFT      7
#define MSTATUS_MPP_SHIFT       11  // 12-11

#define MSTATUS_MIE_WIDTH       1
#define MSTATUS_MPIE_WIDTH      1
#define MSTATUS_MPP_WIDTH       2

#define CSR_FIELD_SHIFT(field) field##_SHIFT
#define CSR_FIELD_WIDTH(field) field##_WIDTH
#define CSR_READ(reg, field) BITS((reg), CSR_FIELD_SHIFT(field) + CSR_FIELD_WIDTH(field) - 1, CSR_FIELD_SHIFT(field))
#define CSR_WRITE(reg, field, val) \
  do { \
    (reg) = ((reg) & ~((word_t)BITMASK(CSR_FIELD_WIDTH(field)) << CSR_FIELD_SHIFT(field))) | \
            (((word_t)(val) & BITMASK(CSR_FIELD_WIDTH(field))) << CSR_FIELD_SHIFT(field)); \
  } while (0)

#endif
