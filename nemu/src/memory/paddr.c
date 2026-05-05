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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
static uint8_t mrom[CONFIG_MROMSIZE] PG_ALIGN = {};
static uint8_t sram[CONFIG_SRAMSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }
uint8_t* guest_to_mrom(paddr_t paddr) { return mrom + paddr - CONFIG_MROMBASE; }
paddr_t mrom_to_guest(uint8_t *maddr) { return maddr - mrom + CONFIG_MROMBASE; }
uint8_t* guest_to_sram(paddr_t paddr) { return sram + paddr - CONFIG_SRAMBASE; }
paddr_t sram_to_guest(uint8_t *saddr) { return saddr - sram + CONFIG_SRAMBASE; }

int flag_mrom_init = 1; // 完成MROM初始化之后就将它置为0，此后不再允许对MROM的写入

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static word_t mrom_read(paddr_t addr, int len) {
  // printf("DEBUG: In mrom_read, addr = 0x%08x, len = %d\n", addr, len);
  word_t ret = host_read(guest_to_mrom(addr), len);
  return ret;
}

static void mrom_write(paddr_t addr, int len, word_t data) {
  if(flag_mrom_init) {
    host_write(guest_to_mrom(addr), len, data);
  }
  else {
    printf("Error: MROM is read-only\n");
    assert(0);
  }
}

static word_t sram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_sram(addr), len);
  return ret;
}

static void sram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_sram(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len, mem_read_t read_type) {
#if defined(CONFIG_MTRACE) || defined(CONFIG_DTRACE)
  const char *str_type[] = { "inst", "data", "debug" };
#endif
  if (likely(in_pmem(addr))) {
#ifdef CONFIG_MTRACE
    if(CONFIG_MTRACE_COND)
      _Log("[mtrace] pmem_read (%s): addr = " FMT_PADDR ", len = %d\n", str_type[read_type], addr, len);
#endif
    return pmem_read(addr, len);
  }
  else if(in_mrom(addr)) {
#ifdef CONFIG_MTRACE
    if(CONFIG_MTRACE_COND)
      _Log("[mtrace] mrom_read (%s): addr = " FMT_PADDR ", len = %d\n", str_type[read_type], addr, len);
#endif
    word_t data = mrom_read(addr, len);
    _Log("DEBUG: [mtrace] mrom_read: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
    return data;
  }
  else if(in_sram(addr)) {
#ifdef CONFIG_MTRACE
    if(CONFIG_MTRACE_COND)
      _Log("[mtrace] sram_read (%s): addr = " FMT_PADDR ", len = %d\n", str_type[read_type], addr, len);
#endif
    word_t data = sram_read(addr, len);
    _Log("DEBUG: [mtrace] sram_read: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
    return data;
  }
#ifdef CONFIG_DEVICE
#ifdef CONFIG_DTRACE
  if(CONFIG_DTRACE_COND)
    _Log("[dtrace] mmio_read (%s): addr = " FMT_PADDR ", len = %d\n", str_type[read_type], addr, len);
#endif
  return mmio_read(addr, len);
#endif
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
#ifdef CONFIG_MTRACE
    if(CONFIG_MTRACE_COND)
      _Log("[mtrace] pmem_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
#endif
    pmem_write(addr, len, data); 
    return; 
  }
  else if(in_mrom(addr)) {
#ifdef CONFIG_MTRACE
    if(CONFIG_MTRACE_COND)
      _Log("[mtrace] mrom_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
#endif
    _Log("DEBUG: [mtrace] mrom_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
    mrom_write(addr, len, data);
    return;
  }
  else if(in_sram(addr)) {
#ifdef CONFIG_MTRACE
    if(CONFIG_MTRACE_COND)
      _Log("[mtrace] sram_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
#endif
    _Log("DEBUG: [mtrace] sram_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
    sram_write(addr, len, data);
    return;
  }
#ifdef CONFIG_DEVICE
#ifdef CONFIG_DTRACE
  if(CONFIG_DTRACE_COND)
    _Log("[dtrace] mmio_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
#endif
  mmio_write(addr, len, data); return;
#endif
  out_of_bound(addr);
}
