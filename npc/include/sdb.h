#ifndef __SDB_H__
#define __SDB_H__

#include <stdint.h>
#include <stdbool.h>

void init_sdb();
void sdb_mainloop();
void reg_display();
uint32_t expr(char *e, bool *success);

#endif
