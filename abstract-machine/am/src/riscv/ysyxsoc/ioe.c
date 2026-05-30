#include <am.h>
#include <klib-macros.h>

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

void __am_timer_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; cfg->has_rtc = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = false;  }
static void __am_uart_rx(AM_UART_RX_T *uart) {
  if (*(volatile uint8_t *)(UART_BASE + UART_LSR) & 1) {
    uart->data = *(volatile uint8_t *)(UART_BASE + UART_RX);
  }
  else {
    uart->data = 0xff;
  }
}

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
  [AM_TIMER_CONFIG] = __am_timer_config,
  [AM_TIMER_RTC   ] = __am_timer_rtc,
  [AM_TIMER_UPTIME] = __am_timer_uptime,
  [AM_INPUT_CONFIG] = __am_input_config,
  [AM_INPUT_KEYBRD] = __am_input_keybrd,
  [AM_UART_CONFIG]  = __am_uart_config,
  [AM_UART_RX     ] = __am_uart_rx,
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) lut[i] = fail;
  __am_timer_init();
  return true;
}

void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
