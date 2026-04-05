#ifndef __DPI_C_H__
#define __DPI_C_H__

#include <stdint.h>

extern "C" void sim_halt(int exit_code);
extern "C" int pmem_read(uint32_t raddr);
extern "C" void pmem_write(uint32_t waddr, int wdata, char wmask);

#endif
