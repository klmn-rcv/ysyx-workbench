#ifndef __SIM_H__
#define __SIM_H__

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VysyxSoCFull.h"

#define MROM_SIZE _mrom_size
#define FLASH_SIZE _flash_size

#define MEM_SIZE 0x8000000

extern VysyxSoCFull* top;

#ifdef CONFIG_GEN_WAVE
extern vluint64_t sim_time;
extern VerilatedVcdC* tfp;
void end_wave(void);
#endif

#endif
