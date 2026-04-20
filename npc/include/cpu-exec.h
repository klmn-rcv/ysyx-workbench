#ifndef __CPU_EXEC_H__
#define __CPU_EXEC_H__

#include <stdint.h>
#include "config.h"
#include "macro.h"

extern uint64_t g_nr_commit;
void cpu_exec(uint64_t n);

#endif
