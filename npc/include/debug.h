#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <cstdio>
#include "common.h"

#define Log(format, ...) \
  do { \
    std::printf(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__); \
  } while (0)

#endif
