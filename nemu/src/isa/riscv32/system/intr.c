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

#include <isa.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */

  cpu.mcause = NO;  // 中断位目前还没办法处理
  cpu.mepc = epc;  // 对于系统调用，epc要加4，但这是软件的任务，而这里是硬件，只把epc存到mepc就行了

  word_t mie = CSR_READ(cpu.mstatus, MSTATUS_MIE);
  CSR_WRITE(cpu.mstatus, MSTATUS_MPIE, mie);
  CSR_WRITE(cpu.mstatus, MSTATUS_MIE, 0);
  CSR_WRITE(cpu.mstatus, MSTATUS_MPP, cpu.priv);
  cpu.priv = M_MODE;

  return cpu.mtvec & ~0x3;  // mtvec低2位是MODE，不一定是全零
}

word_t isa_return_trap() {
  word_t mpie = CSR_READ(cpu.mstatus, MSTATUS_MPIE);
  CSR_WRITE(cpu.mstatus, MSTATUS_MIE, mpie);
  CSR_WRITE(cpu.mstatus, MSTATUS_MPIE, 1);
  cpu.priv = CSR_READ(cpu.mstatus, MSTATUS_MPP);
  CSR_WRITE(cpu.mstatus, MSTATUS_MPP, M_MODE);
  return cpu.mepc;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
