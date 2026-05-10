#include <am.h>
#include <klib.h>
// #include <klib-macros.h>

extern char _heap_start;
extern char _heap_end;
int main(const char *args);

#define UART_BASE 0x10000000L
#define UART_RX   0   // R
#define UART_TX   0   // W
#define UART_IER  1   // R/W
#define UART_IIR  2   // R
#define UART_FCR  2   // W
#define UART_LCR  3   // R/W
#define UART_MCR  4   // W
#define UART_LSR  5   // R
#define UART_MSR  6   // R

#define UART_DLLO 0   // R/W
#define UART_DLHI 1   // R/W

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void init_uart(void) {
  *(volatile uint8_t *)(UART_BASE + UART_LCR) = 0x80; // set DLAB=1 to access baud rate divisor
  *(volatile uint8_t *)(UART_BASE + UART_DLLO) = 0x01; // set baud rate divisor to 1 (115200 baud)
  *(volatile uint8_t *)(UART_BASE + UART_DLHI) = 0x00; // set baud rate divisor to 1 (115200 baud)
  *(volatile uint8_t *)(UART_BASE + UART_LCR) = 0x03; // set 8N1 format (8 data bits, no parity, 1 stop bit)
  *(volatile uint8_t *)(UART_BASE + UART_FCR) = 0xC6; // clear FIFO and set trigger level to 14 bytes (Bit 0 is ignored in 16550)
  *(volatile uint8_t *)(UART_BASE + UART_IER) = 0x00; // disable all interrupts
}

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

  init_uart();

  int ret = main(mainargs);
  halt(ret);
}
