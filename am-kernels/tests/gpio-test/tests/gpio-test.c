#include "trap.h"

#define GPIO_BASE       0x10002000u
#define GPIO_LED_ADDR   (GPIO_BASE + 0x0)
#define GPIO_SW_ADDR    (GPIO_BASE + 0x4)
#define GPIO_SEG_ADDR   (GPIO_BASE + 0x8)

static inline void mmio_write32(uintptr_t addr, uint32_t data) {
  *(volatile uint32_t *)addr = data;
}

static inline uint32_t mmio_read32(uintptr_t addr) {
  return *(volatile uint32_t *)addr;
}

static inline void gpio_set_led(uint16_t led) {
  mmio_write32(GPIO_LED_ADDR, (uint32_t)led);
}

static inline uint16_t gpio_get_switch(void) {
  return (uint16_t)(mmio_read32(GPIO_SW_ADDR) & 0xffffu);
}

static inline void gpio_set_seg(uint32_t value) {
  mmio_write32(GPIO_SEG_ADDR, value);
}

static inline uint32_t switch_to_seg(uint16_t sw) {
  return ((uint32_t)sw << 16) | sw;
}

static inline void delay(volatile uint32_t cycles) {
  while (cycles-- > 0)
    ;
}

int main() {
  static const uint16_t led_patterns[] = {
    0xffff, 0x0000, 0x5555, 0xaaaa, 0x0f0f, 0xf0f0, 0xa5a5, 0x5a5a,
  };
  static const uint32_t seg_patterns[] = {
    0x01234567u, 0x89abcdefu, 0x13579bdfu, 0x2468ace0u,
  };

  printf("gpio-test: switches are mirrored to LEDs and 7-seg displays.\n");

  for (int i = 0; i < (int)LENGTH(led_patterns); i++) {
    gpio_set_led(led_patterns[i]);
    gpio_set_seg(seg_patterns[i & 3]);
    delay(2000);
  }

  uint16_t last = 0xffffu;
  while (1) {
    uint16_t sw = gpio_get_switch();
    if (sw != last) {
      last = sw;
      gpio_set_led(sw);
      gpio_set_seg(switch_to_seg(sw));
      printf("gpio-test: switch = 0x%x\n", sw);
    }
  }

  return 0;
}
