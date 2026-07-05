#ifndef __SIM_H__
#define __SIM_H__

#include <verilated.h>
#include <verilated_vcd_c.h>

#include TOP_HEADER

// #define MROM_SIZE 0x1000
// #define FLASH_SIZE 0x10000000

// #define MEM_SIZE 0x8000000

extern TOP_CLASS* top;

#ifdef CONFIG_GEN_WAVE
extern vluint64_t sim_time;
extern VerilatedVcdC* tfp;
void end_wave(void);
#endif

#endif
