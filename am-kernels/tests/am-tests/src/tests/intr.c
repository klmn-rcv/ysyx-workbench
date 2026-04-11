#include <amtest.h>

// 就是 user_handler（事件处理回调函数）
Context *simple_trap(Event ev, Context *ctx) {
  switch(ev.event) {
    case EVENT_IRQ_TIMER:
      putch('t'); break;
    case EVENT_IRQ_IODEV:
      putch('d'); break;
    case EVENT_YIELD:
      putch('y'); break;
    default:
      panic("Unhandled event"); break;
  }
  return ctx;
}

void hello_intr() {
  printf("Hello, AM World @ " __ISA__ "\n");
  printf("  t = timer, d = device, y = yield\n");
  io_read(AM_INPUT_CONFIG);
  iset(1);
  while (1) {
    // 这里用带 volatile 的循环是为了防止调用 yield 的频率过高导致输出过快
    // 普通循环可能被完全优化掉，而带 volatile 的循环必须老老实实执行 1000 万次内存操作
    for (volatile int i = 0; i < 10000000; i++) ;
    yield();
  }
}
