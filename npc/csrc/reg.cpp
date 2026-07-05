#include "common.h"
#include "sim.h"
#include TOP_ROOT_HEADER

#define REG_NUM 16

static const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

static const char *csr_regs[] = {
  "mstatus", "mtvec", "mepc", "mcause"/*, "mcycle", "mcycleh", "mvendorid", "marchid"*/
};

#ifdef SIM_MODE_NPC
#define ROOT_GPR(n) top->rootp->Top__DOT__core__DOT__regfile__DOT__regfile_##n
#define ROOT_CORE_FIELD(name) top->rootp->Top__DOT__core__DOT__##name
#else
#define ROOT_GPR(n) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__regfile__DOT__regfile_##n
#define ROOT_CORE_FIELD(name) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__##name
#endif

// 似乎只能这样写，没什么好的办法了
word_t get_gpr(int i) {
  switch (i) {
    case 0:  return (word_t)ROOT_GPR(0);
    case 1:  return (word_t)ROOT_GPR(1);
    case 2:  return (word_t)ROOT_GPR(2);
    case 3:  return (word_t)ROOT_GPR(3);
    case 4:  return (word_t)ROOT_GPR(4);
    case 5:  return (word_t)ROOT_GPR(5);
    case 6:  return (word_t)ROOT_GPR(6);
    case 7:  return (word_t)ROOT_GPR(7);
    case 8:  return (word_t)ROOT_GPR(8);
    case 9:  return (word_t)ROOT_GPR(9);
    case 10: return (word_t)ROOT_GPR(10);
    case 11: return (word_t)ROOT_GPR(11);
    case 12: return (word_t)ROOT_GPR(12);
    case 13: return (word_t)ROOT_GPR(13);
    case 14: return (word_t)ROOT_GPR(14);
    case 15: return (word_t)ROOT_GPR(15);
    default: assert(0); return 0;
  }
}

// word_t get_iw_pc() {
//   return (word_t)top->rootp->Top__DOT__core__DOT__ifu__DOT__io_out_bypass_pc_r;
// }

word_t get_pc() {
  return (word_t)ROOT_CORE_FIELD(wbu__DOT__submit_dnpc);
}

word_t get_if_pc() {
  return (word_t)ROOT_CORE_FIELD(ifu__DOT__pc);
}

word_t get_iw_pc() {
  return (word_t)ROOT_CORE_FIELD(bitsReg_pc);
}

word_t get_id_pc() {
  return (word_t)ROOT_CORE_FIELD(bitsReg_1_pc);
}

word_t get_ex_pc() {
  return (word_t)ROOT_CORE_FIELD(bitsReg_2_pc);
}

word_t get_ls_pc() {
  return (word_t)ROOT_CORE_FIELD(bitsReg_3_pc);
}

word_t get_lsw_pc() {
  return (word_t)ROOT_CORE_FIELD(bitsReg_4_pc);
}

word_t get_wb_pc() {
  return (word_t)ROOT_CORE_FIELD(bitsReg_5_pc);
}

word_t get_csr(int i) {
  switch (i) {
    case 0: return (word_t)ROOT_CORE_FIELD(csr__DOT__mstatus);
    case 1: return (word_t)ROOT_CORE_FIELD(csr__DOT__mtvec);
    case 2: return (word_t)ROOT_CORE_FIELD(csr__DOT__mepc);
    case 3: return (word_t)ROOT_CORE_FIELD(csr__DOT__mcause);
    // case 4: return (word_t)top->rootp->Top__DOT__core__DOT__csr__DOT__mcycle;
    // case 5: return (word_t)top->rootp->Top__DOT__core__DOT__csr__DOT__mcycleh;
    // case 6: return (word_t)top->rootp->Top__DOT__core__DOT__csr__DOT__mvendorid;
    // case 7: return (word_t)top->rootp->Top__DOT__core__DOT__csr__DOT__marchid;
    default: assert(0); return 0;
  }
}

word_t get_csr_by_name(const char *name) {
  for(int i = 0; i < sizeof(csr_regs) / sizeof(csr_regs[0]); i++) {
    if(strcmp(name, csr_regs[i]) == 0) {
      return get_csr(i);
    }
  }
  assert(0);
  return 0;
}

word_t get_priv() {
  return (word_t)ROOT_CORE_FIELD(csr__DOT__priv);
}

uint32_t gpr_str2val(const char *s, bool *success) {
  *success = false;
  for(int i = 0; i < REG_NUM; i++){
    if(strcmp(s,regs[i])==0){
      *success = true;
      return get_gpr(i);
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
      return get_gpr(N);
    }
  }
  return 0;
}

uint32_t csr_str2val(const char *s, bool *success) {
  *success = false;
  for(int i = 0; i < sizeof(csr_regs) / sizeof(csr_regs[0]); i++) {
    if(strcmp(s, csr_regs[i]) == 0) {
      *success = true;
      return get_csr(i);
    }
  }
  return 0;
}

uint32_t reg_str2val(const char *s, bool *success) {
  uint32_t val = gpr_str2val(s, success);
  if(*success == false) {
    val = csr_str2val(s, success);
  }
  if(*success == false && strcmp(s, "pc") == 0) {
    *success = true;
    return get_pc();
  }
  return val;
}

void reg_display() {
  for(int i = 0; i < REG_NUM; i++){
    bool success = false;
    uint32_t reg_value = gpr_str2val(regs[i], &success);
    if(success==false){
      assert(0);
    }
    printf("%s\t\tr%d\t\t0x%x\t\t%u\n", regs[i], i, reg_value, reg_value);
  }
  word_t pc_value = get_pc();
  printf("pc\t\tpc\t\t0x%x\t\t%u\n", pc_value, pc_value);
  for(int i = 0; i < sizeof(csr_regs) / sizeof(csr_regs[0]); i++) {
    bool success = false;
    uint32_t csr_value = csr_str2val(csr_regs[i], &success);
    if(success == false) {
      assert(0);
    }
    printf("%s\t\tcsr%d\t\t0x%x\t\t%u\n", csr_regs[i], i, csr_value, csr_value);
  }
}
