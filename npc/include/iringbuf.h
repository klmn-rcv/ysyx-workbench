#ifndef __CPU_IRINGBUF_H__
#define __CPU_IRINGBUF_H__

#include <stdint.h>
#include <config.h>

#ifdef CONFIG_ITRACE

void iringbuf_print(void);
void iringbuf_push_pc(uint32_t pc);
void iringbuf_backfill_inst(uint32_t pc, uint32_t inst);
void iringbuf_flush_refill_pos(uint32_t pc);

#endif

#endif
