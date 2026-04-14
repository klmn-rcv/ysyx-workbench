#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)
#define MAP(c, f) c(f)

#if __riscv_xlen == 32
#define LOAD  lw
#define STORE sw
#define XLEN  4
#else
#define LOAD  ld
#define STORE sd
#define XLEN  8
#endif

// skip x2(sp): sp is restored by addi sp, sp, CONTEXT_SIZE
#define REGS_LO16(f) \
      f( 1)       f( 3) f( 4) f( 5) f( 6) f( 7) f( 8) f( 9) \
f(10) f(11) f(12) f(13) f(14) f(15)
#ifndef __riscv_e
#define REGS_HI16(f) \
                                    f(16) f(17) f(18) f(19) \
f(20) f(21) f(22) f(23) f(24) f(25) f(26) f(27) f(28) f(29) \
f(30) f(31)
#define NR_REGS 32
#else
#define REGS_HI16(f)  // if use E extension, REGS_HI16 is defined as empty
#define NR_REGS 16
#endif

#define REGS(f) REGS_LO16(f) REGS_HI16(f)

#define PUSH(n) STORE concat(x, n), (n * XLEN)(sp);   // "PUSH(1)" is: sw x1, 4(sp), "PUSH(3)" is: sw x3, 12(sp), ...
#define POP(n)  LOAD  concat(x, n), (n * XLEN)(sp);

#define CONTEXT_SIZE  ((NR_REGS + 3) * XLEN)
#define OFFSET_SP     ( 2 * XLEN)
#define OFFSET_CAUSE  ((NR_REGS + 0) * XLEN)
#define OFFSET_STATUS ((NR_REGS + 1) * XLEN)
#define OFFSET_EPC    ((NR_REGS + 2) * XLEN)

.align 3
.globl __am_asm_trap
__am_asm_trap:
  addi sp, sp, -CONTEXT_SIZE

  MAP(REGS, PUSH)  // == REGS(PUSH) == REGS_LO16(PUSH) REGS_HI16(PUSH) == PUSH(1) PUSH(3) ... PUSH(16) (when using E extension)

  csrr t0, mcause
  csrr t1, mstatus
  csrr t2, mepc

  STORE t0, OFFSET_CAUSE(sp)
  STORE t1, OFFSET_STATUS(sp)
  STORE t2, OFFSET_EPC(sp)

  # set mstatus.MPRV to pass difftest
  // MPRV=0：load/store 按当前特权级执行
  // MPRV=1：load/store 按mstatus.MPP级（即陷入M级之前的较低特权级）执行
  // 至于这里究竟为什么设MPRV=1，我目前还弄不清楚，这里后面再分析
  # li a0, (1 << 17)
  # or t1, t1, a0
  # csrw mstatus, t1

  mv a0, sp
  call __am_irq_handle

  mv sp, a0  // 切换到新进程的栈（sp现在指向新进程的上下文）

  // mcause不用恢复，之前把它放入栈中只是为了传递给__am_irq_handle
  LOAD t1, OFFSET_STATUS(sp)
  LOAD t2, OFFSET_EPC(sp)
  csrw mstatus, t1
  csrw mepc, t2

  MAP(REGS, POP)  // == REGS(POP) == REGS_LO16(POP) REGS_HI16(POP) == POP(1) POP(3) ... POP(16) (when using E extension)

  addi sp, sp, CONTEXT_SIZE
  mret
