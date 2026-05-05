#include <am.h>

#define TIMER_ADDR_LOW  0x10000004
#define TIMER_ADDR_HIGH 0x10000008

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = ((uint64_t)(*(volatile uint32_t *)TIMER_ADDR_HIGH) << 32) |
               (uint64_t)(*(volatile uint32_t *)TIMER_ADDR_LOW);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
