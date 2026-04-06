#ifndef __SIM_H__
#define __SIM_H__

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VTop.h"

// #define GEN_TRACE

#define MEM_SIZE 0x10000000

extern VTop* top;

#ifdef GEN_TRACE
extern vluint64_t sim_time;
extern VerilatedVcdC* tfp;
#endif

#endif
