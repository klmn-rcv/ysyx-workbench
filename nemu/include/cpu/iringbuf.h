#ifndef __CPU_IRINGBUF_H__
#define __CPU_IRINGBUF_H__

#include <common.h>

void iringbuf_push_line(const char *str);
void iringbuf_rewrite_last_line(const char *str);
void iringbuf_print(void);
void iringbuf_push_pc(vaddr_t pc);
void iringbuf_backfill_inst(vaddr_t pc, uint32_t inst);

#endif
