#include "sim.h"
#include "VTop___024root.h"

#define REG_NUM 16

// 似乎只能这样写，没什么好的办法了
static uint32_t gpr(int i) {
  switch (i) {
    case 0:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_0;
    case 1:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_1;
    case 2:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_2;
    case 3:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_3;
    case 4:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_4;
    case 5:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_5;
    case 6:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_6;
    case 7:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_7;
    case 8:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_8;
    case 9:  return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_9;
    case 10: return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_10;
    case 11: return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_11;
    case 12: return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_12;
    case 13: return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_13;
    case 14: return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_14;
    case 15: return (uint32_t)top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_15;
    default: assert(0); return 0;
  }
}

static const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

uint32_t reg_str2val(const char *s, bool *success) {
  *success = false;
  for(int i = 0; i < REG_NUM; i++){
    if(strcmp(s,regs[i])==0){
      *success = true;
      return gpr(i);
    }
  }
  if(s[0] == 'r' && isdigit(s[1])) {
    int N = 0;
    for(int i = 1; i <= 2; i++) {
      if(isdigit(s[i]))
        N = N * 10 + s[i] - '0';
    }
    if(N >= 0 && N < REG_NUM) {
      *success = true;
      return gpr(N);
    }
  }
  return 0;
}

void reg_display() {
  for(int i = 0; i < REG_NUM; i++){
    bool success = false;
    uint32_t reg_value = reg_str2val(regs[i], &success);
    if(success==false){
      assert(0);
    }
    printf("%s\t\tr%d\t\t0x%x\t\t%u\n", regs[i], i, reg_value, reg_value);
  }
}
