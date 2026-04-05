#ifndef __COMMON_H__
#define __COMMON_H__

#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

#define FMT_WORD "0x%08" PRIx32

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#endif
