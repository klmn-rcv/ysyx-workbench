#ifndef __ITRACE_H__
#define __ITRACE_H__

#include <stdint.h>

typedef struct {
  uint32_t inst;
  uint32_t pc;
  uint32_t dnpc;
  char logbuf[128];
} Inst;

extern Inst s;

#endif
