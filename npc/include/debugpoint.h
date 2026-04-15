#ifndef __DEBUGPOINT_H__
#define __DEBUGPOINT_H__

#include "common.h"

typedef enum {
  PT_WATCHPOINT,
  PT_BREAKPOINT,
} DebugPointType;

void init_pt_pool();
bool check_all_wp_no_change(int *NO, char **expr_str, uint32_t *old_value, uint32_t *new_value);
bool check_bp_hit(uint32_t pc, int *NO, uint32_t *addr);
int init_new_wp(char *s);
int init_new_bp(uint32_t addr);
bool delete_pt(int NO, DebugPointType type);
void display_pt(DebugPointType type);

#endif
