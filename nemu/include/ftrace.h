#ifdef CONFIG_FTRACE

#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <stdint.h>

#define MAX_FUNC_NUM 1000

typedef struct {
    char name[128];
    uint32_t start_addr;
    uint32_t end_addr;  // not included
} func_t;

typedef struct {
    int count;
    func_t arr[MAX_FUNC_NUM];
} func_array_t;

extern func_array_t func_array;
void init_ftrace(const char *elf_file);
int func_array_search(char *name, uint32_t addr, bool *is_func_entry);

#endif

#endif
