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

#if defined(CONFIG_PMEM_MALLOC) && !defined(CONFIG_TARGET_SHARE)
static uint8_t *pmem = NULL;
#elif !defined(CONFIG_TARGET_SHARE)
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

#ifdef CONFIG_TARGET_SHARE
static uint8_t mrom[CONFIG_MROMSIZE] PG_ALIGN = {};
static uint8_t sram[CONFIG_SRAMSIZE] PG_ALIGN = {};
static uint8_t flash[CONFIG_FLASHSIZE] PG_ALIGN = {};
static uint8_t psram[CONFIG_PSRAMSIZE] PG_ALIGN = {};
static uint8_t sdram[CONFIG_SDRAMSIZE] PG_ALIGN = {};

typedef enum {
  REGION_MROM,
  REGION_SRAM,
  REGION_FLASH,
  REGION_PSRAM,
  REGION_SDRAM,
} region_kind_t;

typedef struct {
  region_kind_t kind;
  const char *name;
  paddr_t left;
  size_t size;
  uint8_t *space;
} mem_region_t;

int flag_mrom_init = 1;

static mem_region_t soc_regions[] = {
  { REGION_MROM,  "mrom",  MROM_LEFT,  CONFIG_MROMSIZE,  mrom  },
  { REGION_SRAM,  "sram",  SRAM_LEFT,  CONFIG_SRAMSIZE,  sram  },
  { REGION_FLASH, "flash", FLASH_LEFT, CONFIG_FLASHSIZE, flash },
  { REGION_PSRAM, "psram", PSRAM_LEFT, CONFIG_PSRAMSIZE, psram },
  { REGION_SDRAM, "sdram", SDRAM_LEFT, CONFIG_SDRAMSIZE, sdram },
};

static inline uint8_t *region_ptr(mem_region_t *r, paddr_t addr) {
  return r->space + addr - r->left;
}

static mem_region_t *find_region(paddr_t addr) {
  for (int i = 0; i < ARRLEN(soc_regions); i++) {
    mem_region_t *r = &soc_regions[i];
    if (addr - r->left < r->size) {
      return r;
    }
  }
  return NULL;
}

static word_t region_read(mem_region_t *r, paddr_t addr, int len) {
  return host_read(region_ptr(r, addr), len);
}

static void region_write(mem_region_t *r, paddr_t addr, int len, word_t data) {
  if (r->kind == REGION_MROM && !flag_mrom_init) {
    panic("MROM is read-only");
  }
  host_write(region_ptr(r, addr), len, data);
}
#endif

#ifdef CONFIG_TARGET_SHARE
uint8_t* guest_to_host(paddr_t paddr) {
  (void)paddr;
  panic("guest_to_host() should not be used in CONFIG_TARGET_SHARE");
  return NULL;
}

paddr_t host_to_guest(uint8_t *haddr) {
  (void)haddr;
  panic("host_to_guest() is not supported in CONFIG_TARGET_SHARE");
  return 0;
}
#else
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  return host_read(guest_to_host(addr), len);
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}
#endif

static void out_of_bound(paddr_t addr) {
#ifdef CONFIG_TARGET_SHARE
  panic(
    "address = " FMT_PADDR " is out of ysyxsoc memory map "
    "mrom[" FMT_PADDR ", " FMT_PADDR "], "
    "sram[" FMT_PADDR ", " FMT_PADDR "], "
    "flash[" FMT_PADDR ", " FMT_PADDR "], "
    "psram[" FMT_PADDR ", " FMT_PADDR "], "
    "sdram[" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
    addr,
    MROM_LEFT, MROM_RIGHT,
    SRAM_LEFT, SRAM_RIGHT,
    FLASH_LEFT, FLASH_RIGHT,
    PSRAM_LEFT, PSRAM_RIGHT,
    SDRAM_LEFT, SDRAM_RIGHT,
    cpu.pc
  );
#else
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
#endif
}

void init_mem() {
#if defined(CONFIG_PMEM_MALLOC) && !defined(CONFIG_TARGET_SHARE)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif

#ifndef CONFIG_TARGET_SHARE
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
#else
  memset(mrom, 0, CONFIG_MROMSIZE);
  memset(flash, 0, CONFIG_FLASHSIZE);
  IFDEF(CONFIG_MEM_RANDOM, memset(sram, rand(), CONFIG_SRAMSIZE));
  IFDEF(CONFIG_MEM_RANDOM, memset(psram, rand(), CONFIG_PSRAMSIZE));
  IFDEF(CONFIG_MEM_RANDOM, memset(sdram, rand(), CONFIG_SDRAMSIZE));
  Log("mrom  area [" FMT_PADDR ", " FMT_PADDR "]", MROM_LEFT, MROM_RIGHT);
  Log("sram  area [" FMT_PADDR ", " FMT_PADDR "]", SRAM_LEFT, SRAM_RIGHT);
  Log("flash area [" FMT_PADDR ", " FMT_PADDR "]", FLASH_LEFT, FLASH_RIGHT);
  Log("psram area [" FMT_PADDR ", " FMT_PADDR "]", PSRAM_LEFT, PSRAM_RIGHT);
  Log("sdram area [" FMT_PADDR ", " FMT_PADDR "]", SDRAM_LEFT, SDRAM_RIGHT);
#endif
}

word_t paddr_read(paddr_t addr, int len, mem_read_t read_type) {
  printf("DEBUG: NEMU: paddr_read called with addr = " FMT_PADDR ", len = %d, read_type = %d\n", addr, len, read_type);
#if defined(CONFIG_MTRACE) || defined(CONFIG_DTRACE)
  const char *str_type[] = { "inst", "data", "debug" };
#endif

#ifndef CONFIG_TARGET_SHARE
  if (likely(in_pmem(addr))) {
#ifdef CONFIG_MTRACE
    if (CONFIG_MTRACE_COND) {
      _Log("[mtrace] pmem_read (%s): addr = " FMT_PADDR ", len = %d\n", str_type[read_type], addr, len);
    }
#endif
    return pmem_read(addr, len);
  }
#else
  mem_region_t *r = find_region(addr);
  if (likely(r != NULL)) {
#ifdef CONFIG_MTRACE
    if (CONFIG_MTRACE_COND) {
      _Log("[mtrace] %s_read (%s): addr = " FMT_PADDR ", len = %d\n",
          r->name, str_type[read_type], addr, len);
    }
#endif
    return region_read(r, addr, len);
  }
#endif

#ifdef CONFIG_DEVICE
#ifdef CONFIG_DTRACE
  if (CONFIG_DTRACE_COND) {
    _Log("[dtrace] mmio_read (%s): addr = " FMT_PADDR ", len = %d\n", str_type[read_type], addr, len);
  }
#endif
  return mmio_read(addr, len);
#endif

  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  printf("DEBUG: NEMU: paddr_write called with addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
#ifndef CONFIG_TARGET_SHARE
  if (likely(in_pmem(addr))) {
#ifdef CONFIG_MTRACE
    if (CONFIG_MTRACE_COND) {
      _Log("[mtrace] pmem_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
    }
#endif
    pmem_write(addr, len, data);
    return;
  }
#else
  mem_region_t *r = find_region(addr);
  if (likely(r != NULL)) {
#ifdef CONFIG_MTRACE
    if (CONFIG_MTRACE_COND) {
      _Log("[mtrace] %s_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n",
          r->name, addr, len, data);
    }
#endif
    region_write(r, addr, len, data);
    return;
  }
#endif

#ifdef CONFIG_DEVICE
#ifdef CONFIG_DTRACE
  if (CONFIG_DTRACE_COND) {
    _Log("[dtrace] mmio_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
  }
#endif
  mmio_write(addr, len, data);
  return;
#endif

  out_of_bound(addr);
}
