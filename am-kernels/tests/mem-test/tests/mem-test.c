#include "trap.h"

extern char _heap_start;
extern char _heap_end;

void fail() {
  halt(1);
}

void test8(uintptr_t start, uintptr_t end) {
  for (uintptr_t addr = start; addr < end; addr++) {
    *(volatile uint8_t *)addr = (uint8_t)(addr & 0xff);
  }
  for (uintptr_t addr = start; addr < end; addr++) {
    uint8_t expect = (uint8_t)(addr & 0xff);
    uint8_t got = *(volatile uint8_t *)addr;
    if (got != expect) {
      fail();
    }
  }
}

void test16(uintptr_t start, uintptr_t end) {
  for (uintptr_t addr = start; addr + sizeof(uint16_t) <= end; addr += sizeof(uint16_t)) {
    *(volatile uint16_t *)addr = (uint16_t)(addr & 0xffff);
  }
  for (uintptr_t addr = start; addr + sizeof(uint16_t) <= end; addr += sizeof(uint16_t)) {
    uint16_t expect = (uint16_t)(addr & 0xffff);
    uint16_t got = *(volatile uint16_t *)addr;
    if (got != expect) {
      fail();
    }
  }
}

void test32(uintptr_t start, uintptr_t end) {
  for (uintptr_t addr = start; addr + sizeof(uint32_t) <= end; addr += sizeof(uint32_t)) {
    *(volatile uint32_t *)addr = (uint32_t)addr;
  }
  for (uintptr_t addr = start; addr + sizeof(uint32_t) <= end; addr += sizeof(uint32_t)) {
    uint32_t expect = (uint32_t)addr;
    uint32_t got = *(volatile uint32_t *)addr;
    if (got != expect) {
      fail();
    }
  }
}

#if __riscv_xlen >= 64
void test64(uintptr_t start, uintptr_t end) {
  for (uintptr_t addr = start; addr + sizeof(uint64_t) <= end; addr += sizeof(uint64_t)) {
    *(volatile uint64_t *)addr = (uint64_t)addr;
  }
  for (uintptr_t addr = start; addr + sizeof(uint64_t) <= end; addr += sizeof(uint64_t)) {
    uint64_t expect = (uint64_t)addr;
    uint64_t got = *(volatile uint64_t *)addr;
    if (got != expect) {
      fail();
    }
  }
}
#endif

int main() {
  uintptr_t start = (uintptr_t)&_heap_start;
  uintptr_t end = (uintptr_t)&_heap_end;

  check(start < end);
  check((start & 0x7) == 0);

  test8(start, end);
  test16(start, end);
  test32(start, end);
#if __riscv_xlen >= 64
  test64(start, end);
#endif

  return 0;
}
