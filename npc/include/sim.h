#ifndef __SIM_H__
#define __SIM_H__

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VTop.h"

#define MEM_SIZE 0x8000000

extern VTop* top;

#ifdef CONFIG_GEN_WAVE
extern vluint64_t sim_time;
extern VerilatedVcdC* tfp;
void end_wave(void);
#endif

#endif
