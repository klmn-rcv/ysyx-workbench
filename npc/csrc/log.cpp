#include "common.h"
#include <cstdio>

FILE *log_fp = NULL;

void init_log(const char *log_file) {
  log_fp = stdout;
  if(log_file != NULL) {
    log_fp = fopen(log_file, "w");
    if (log_fp == NULL) {
      fprintf(stderr, "Failed to open log file: %s\n", log_file);
      exit(1);
    }
  }
}
