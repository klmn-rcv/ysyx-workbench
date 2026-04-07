#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include "macro.h"
#include "config.h"

#ifdef CONFIG_ITRACE
#include "itrace.h"
#include "iringbuf.h"
#endif

// ------ log ------

#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

#define FMT_WORD "0x%08" PRIx32
#define FMT_PADDR "0x%08" PRIx32

extern FILE *log_fp;
void init_log(const char *log_file);

#define log_write(...) \
  do { \
    if (log_fp != NULL) { \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
    } \
  } while (0)

#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
    log_write(__VA_ARGS__); \
  } while (0)

#endif
