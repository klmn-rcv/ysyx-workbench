#ifndef __ITRACE_H__
#define __ITRACE_H__

#include <stdint.h>

typedef struct {
  uint32_t inst;
  uint32_t pc;
  uint32_t dnpc;
  uint8_t need_skip_ref; // 这个字段表示该指令是否需要让ref跳过检查
  char logbuf[128];
} Inst;

extern Inst submit;

#endif
