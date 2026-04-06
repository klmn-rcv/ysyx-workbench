#ifndef __DPI_C_H__
#define __DPI_C_H__

#include <stdint.h>

enum {
  MEM_SRC_INST = 0,
  MEM_SRC_DATA = 1,
  MEM_SRC_DEBUG = 2
};

extern "C" void sim_halt(int exit_code, uint32_t exit_pc);
extern "C" int pmem_read(uint32_t raddr, uint8_t src_type);
extern "C" void pmem_write(uint32_t waddr, int wdata, uint8_t wmask, uint8_t src_type);
extern "C" void iringbuf_before_ifetch(uint32_t pc);
extern "C" void iringbuf_after_ifetch(uint32_t pc, uint32_t inst);

#endif
