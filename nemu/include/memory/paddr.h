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

#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)

#ifdef CONFIG_TARGET_SHARE
#define MROM_LEFT   ((paddr_t)CONFIG_MROMBASE)
#define MROM_RIGHT  ((paddr_t)CONFIG_MROMBASE + CONFIG_MROMSIZE - 1)
#define SRAM_LEFT   ((paddr_t)CONFIG_SRAMBASE)
#define SRAM_RIGHT  ((paddr_t)CONFIG_SRAMBASE + CONFIG_SRAMSIZE - 1)
#define FLASH_LEFT  ((paddr_t)CONFIG_FLASHBASE)
#define FLASH_RIGHT ((paddr_t)CONFIG_FLASHBASE + CONFIG_FLASHSIZE - 1)
#define PSRAM_LEFT  ((paddr_t)CONFIG_PSRAMBASE)
#define PSRAM_RIGHT ((paddr_t)CONFIG_PSRAMBASE + CONFIG_PSRAMSIZE - 1)
#define SDRAM_LEFT  ((paddr_t)CONFIG_SDRAMBASE)
#define SDRAM_RIGHT ((paddr_t)CONFIG_SDRAMBASE + CONFIG_SDRAMSIZE - 1)
#define RESET_VECTOR (FLASH_LEFT + CONFIG_PC_RESET_OFFSET)
#else
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
#endif

enum {
  MEM_READ_INST,
  MEM_READ_DATA,
  MEM_READ_DEBUG
};

typedef uint8_t mem_read_t;

/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

#ifdef CONFIG_TARGET_SHARE
extern int flag_mrom_init;
#endif

static inline bool in_pmem(paddr_t addr) {
#ifdef CONFIG_TARGET_SHARE
  return false;
#else
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
#endif
}

word_t paddr_read(paddr_t addr, int len, mem_read_t read_type);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
