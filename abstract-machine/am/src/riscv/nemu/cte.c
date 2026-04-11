#include <am.h>  // riscv.h在这里面被包含了
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case MCAUSE_YIELD: c->mepc += 4; ev.event = EVENT_YIELD; break;
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));  // 设置mtvec寄存器（异常入口）

  // register event handler
  user_handler = handler;  // 注册事件处理回调函数

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
}

void yield() {
// 先传递系统调用号（-1表示yield），再ecall触发系统调用。立刻跳转到mtvec地址，并伴随mepc、mcause、mstatus的变化。
// riscv系统调用号通常通过a7寄存器传递，但在riscv-e架构中使用a5寄存器
// printf("DEBUG: yield() called\n");
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
