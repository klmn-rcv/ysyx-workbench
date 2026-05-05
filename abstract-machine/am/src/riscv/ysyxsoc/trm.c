#include <am.h>
#include <klib.h>
// #include <klib-macros.h>

extern char _heap_start;
extern char _heap_end;
int main(const char *args);

#define UART_BASE 0x10000000L
#define UART_TX   0

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  *(volatile uint8_t *)(UART_BASE + UART_TX) = ch;
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : : "r"(code));
  while (1);
}

void _trm_init() {
  // // 测试CSR功能
  // uint32_t mvendorid, marchid;
  // asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
  // asm volatile("csrr %0, marchid" : "=r"(marchid));
  // printf("mvendorid = 0x%x, marchid = 0x%x\n", mvendorid, marchid);

  int ret = main(mainargs);
  halt(ret);
}
