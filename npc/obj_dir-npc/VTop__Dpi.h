// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at build-npc/Ftrace.sv:18:32
    extern void ftrace(unsigned int pc, unsigned int target_pc, unsigned char inst_type, int rd, int rs1, int imm);
    // DPI import at build-npc/Iringbuf.sv:13:32
    extern void iringbuf_after_ifetch(unsigned int pc, unsigned int inst);
    // DPI import at build-npc/Iringbuf.sv:12:32
    extern void iringbuf_before_ifetch(unsigned int pc);
    // DPI import at build-npc/Iringbuf.sv:14:32
    extern void iringbuf_flush_after_ifetch(unsigned int pc);
    // DPI import at build-npc/Iringbuf.sv:11:32
    extern void iringbuf_reset();
    // DPI import at build-npc/Itrace.sv:11:34
    extern void itrace(unsigned int pc, unsigned int inst, unsigned int dnpc, char need_skip_ref);
    // DPI import at build-npc/Mem.sv:46:33
    extern int pmem_read(unsigned int raddr, unsigned char read_type);
    // DPI import at build-npc/Mem.sv:47:34
    extern void pmem_write(unsigned int waddr, int wdata, unsigned char wmask);
    // DPI import at build-npc/Halt.sv:9:34
    extern void sim_halt(int exit_code, unsigned int exit_pc);

#ifdef __cplusplus
}
#endif

#endif  // guard
