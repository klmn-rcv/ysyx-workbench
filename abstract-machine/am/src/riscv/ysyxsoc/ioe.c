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

#define KBD_BASE  0x10011000L
#define KBD_DATA  0   // R

void __am_timer_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);

static int keymap_normal[256] = {
  [0x01] = AM_KEY_F9,
  [0x03] = AM_KEY_F5,
  [0x04] = AM_KEY_F3,
  [0x05] = AM_KEY_F1,
  [0x06] = AM_KEY_F2,
  [0x07] = AM_KEY_F12,
  [0x09] = AM_KEY_F10,
  [0x0a] = AM_KEY_F8,
  [0x0b] = AM_KEY_F6,
  [0x0c] = AM_KEY_F4,
  [0x0d] = AM_KEY_TAB,
  [0x0e] = AM_KEY_GRAVE,
  [0x11] = AM_KEY_LALT,
  [0x12] = AM_KEY_LSHIFT,
  [0x14] = AM_KEY_LCTRL,
  [0x15] = AM_KEY_Q,
  [0x16] = AM_KEY_1,
  [0x1a] = AM_KEY_Z,
  [0x1b] = AM_KEY_S,
  [0x1c] = AM_KEY_A,
  [0x1d] = AM_KEY_W,
  [0x1e] = AM_KEY_2,
  [0x21] = AM_KEY_C,
  [0x22] = AM_KEY_X,
  [0x23] = AM_KEY_D,
  [0x24] = AM_KEY_E,
  [0x25] = AM_KEY_4,
  [0x26] = AM_KEY_3,
  [0x29] = AM_KEY_SPACE,
  [0x2a] = AM_KEY_V,
  [0x2b] = AM_KEY_F,
  [0x2c] = AM_KEY_T,
  [0x2d] = AM_KEY_R,
  [0x2e] = AM_KEY_5,
  [0x31] = AM_KEY_N,
  [0x32] = AM_KEY_B,
  [0x33] = AM_KEY_H,
  [0x34] = AM_KEY_G,
  [0x35] = AM_KEY_Y,
  [0x36] = AM_KEY_6,
  [0x3a] = AM_KEY_M,
  [0x3b] = AM_KEY_J,
  [0x3c] = AM_KEY_U,
  [0x3d] = AM_KEY_7,
  [0x3e] = AM_KEY_8,
  [0x41] = AM_KEY_COMMA,
  [0x42] = AM_KEY_K,
  [0x43] = AM_KEY_I,
  [0x44] = AM_KEY_O,
  [0x45] = AM_KEY_0,
  [0x46] = AM_KEY_9,
  [0x49] = AM_KEY_PERIOD,
  [0x4a] = AM_KEY_SLASH,
  [0x4b] = AM_KEY_L,
  [0x4c] = AM_KEY_SEMICOLON,
  [0x4d] = AM_KEY_P,
  [0x4e] = AM_KEY_MINUS,
  [0x52] = AM_KEY_APOSTROPHE,
  [0x54] = AM_KEY_LEFTBRACKET,
  [0x55] = AM_KEY_EQUALS,
  [0x58] = AM_KEY_CAPSLOCK,
  [0x59] = AM_KEY_RSHIFT,
  [0x5a] = AM_KEY_RETURN,
  [0x5b] = AM_KEY_RIGHTBRACKET,
  [0x5d] = AM_KEY_BACKSLASH,
  [0x66] = AM_KEY_BACKSPACE,
  [0x76] = AM_KEY_ESCAPE,
  [0x78] = AM_KEY_F11,
  [0x83] = AM_KEY_F7,
};

static int keymap_extended[256] = {
  [0x11] = AM_KEY_RALT,
  [0x14] = AM_KEY_RCTRL,
  [0x2f] = AM_KEY_APPLICATION,
  [0x4a] = AM_KEY_SLASH,
  [0x5a] = AM_KEY_RETURN,
  [0x69] = AM_KEY_END,
  [0x6b] = AM_KEY_LEFT,
  [0x6c] = AM_KEY_HOME,
  [0x70] = AM_KEY_INSERT,
  [0x71] = AM_KEY_DELETE,
  [0x72] = AM_KEY_DOWN,
  [0x74] = AM_KEY_RIGHT,
  [0x75] = AM_KEY_UP,
  [0x7a] = AM_KEY_PAGEDOWN,
  [0x7d] = AM_KEY_PAGEUP,
};

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; cfg->has_rtc = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_config(AM_UART_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_rx(AM_UART_RX_T *uart) {
  if (*(volatile uint8_t *)(UART_BASE + UART_LSR) & 1) {
    uart->data = *(volatile uint8_t *)(UART_BASE + UART_RX);
  } else {
    uart->data = 0xff;
  }
}
static void __am_input_keybrd(AM_INPUT_KEYBRD_T *keybrd) {
  static bool has_e0_prefix = false;
  static bool has_f0_prefix = false;
  static int skip_e1_bytes = 0;

  keybrd->keydown = false;
  keybrd->keycode = AM_KEY_NONE;

  uint8_t scancode = *(volatile uint8_t *)(KBD_BASE + KBD_DATA);
  if (scancode == 0x00) {
    return;
  }

  if (skip_e1_bytes > 0) {
    skip_e1_bytes--;
    return;
  }

  if (scancode == 0xe1) {
    has_e0_prefix = false;
    has_f0_prefix = false;
    skip_e1_bytes = 7; // 按下Pause/Break键会产生一个长达8个字节的特殊序列：0xE1, 0x14, 0x77, 0xE1, 0xF0, 0x14, 0xF0, 0x77，这里需要逐个字节忽略
    return;
  }

  if (scancode == 0xe0) {
    has_e0_prefix = true;
    return;
  }

  if (scancode == 0xf0) {
    has_f0_prefix = true;
    return;
  }

  int keycode = has_e0_prefix ? keymap_extended[scancode] : keymap_normal[scancode];
  bool keydown = !has_f0_prefix;
  has_e0_prefix = false;
  has_f0_prefix = false;

  if (keycode != AM_KEY_NONE) {
    keybrd->keydown = keydown;
    keybrd->keycode = keycode;
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
