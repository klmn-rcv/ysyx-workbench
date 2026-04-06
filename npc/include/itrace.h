#ifndef __INST_H__
#define __INST_H__

#include <stdint.h>

typedef struct {
  uint32_t inst;
  uint32_t pc;
  char logbuf[128];
} Inst;

extern Inst s;

#endif
