/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/iringbuf.h>

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

#define IRINGBUF_NR 16

typedef struct {
  int write_pos;
  int count;
  char buf[IRINGBUF_NR][128];
} iringbuf_t;

static iringbuf_t iringbuf = {.write_pos = 0, .count = 0};

void iringbuf_push_line(const char *str) {
  assert(iringbuf.write_pos >= 0 && iringbuf.write_pos < IRINGBUF_NR);
  assert(iringbuf.count >= 0 && iringbuf.count <= IRINGBUF_NR);

  size_t n = strnlen(str, sizeof(iringbuf.buf[0]) - 1);
  memcpy(iringbuf.buf[iringbuf.write_pos], str, n);
  iringbuf.buf[iringbuf.write_pos][n] = '\0';
  iringbuf.write_pos = (iringbuf.write_pos + 1) % IRINGBUF_NR;
  if (iringbuf.count < IRINGBUF_NR) {
    iringbuf.count++;
  }
}

void iringbuf_rewrite_last_line(const char *str) {
  assert(iringbuf.write_pos >= 0 && iringbuf.write_pos < IRINGBUF_NR);
  assert(iringbuf.count > 0 && iringbuf.count <= IRINGBUF_NR);

  int pos = (iringbuf.write_pos + IRINGBUF_NR - 1) % IRINGBUF_NR;
  size_t n = strnlen(str, sizeof(iringbuf.buf[0]) - 1);
  memcpy(iringbuf.buf[pos], str, n);
  iringbuf.buf[pos][n] = '\0';
}

void iringbuf_print(void) {
  for (int i = 0; i < iringbuf.count; i++) {
    int pos = (iringbuf.write_pos + IRINGBUF_NR - iringbuf.count + i) % IRINGBUF_NR;
    const char *prefix = (i == iringbuf.count - 1 ? ANSI_FMT("  --> ", ANSI_FG_RED) : "      ");
    printf("%s%s\n", prefix, iringbuf.buf[pos]);
  }
}

void iringbuf_push_pc(vaddr_t pc) {
  char line[128];
  int n = snprintf(line, sizeof(line), FMT_WORD ": %-32s %s", pc, "???", "?? ?? ?? ??");
  assert(n >= 0 && n < (int)sizeof(line));
  iringbuf_push_line(line);
}

void iringbuf_backfill_inst(vaddr_t pc, uint32_t inst) {
  char asm_buf[64];
  char bytes_buf[16];
  char line[128];

  uint8_t *code = (uint8_t *)&inst;
  disassemble(asm_buf, sizeof(asm_buf), pc, code, 4);

  // 为了指令码在视觉上对齐，将反汇编中的制表符替换成空格
  for (char *p = asm_buf; *p != '\0'; p++) {
    if (*p == '\t')
        *p = ' ';
  }

  int nb = snprintf(bytes_buf, sizeof(bytes_buf), "%02x %02x %02x %02x",
      code[3], code[2], code[1], code[0]);
  assert(nb >= 0 && nb < (int)sizeof(bytes_buf));

  int nl = snprintf(line, sizeof(line), FMT_WORD ": %-32s %s", pc, asm_buf, bytes_buf);
  assert(nl >= 0 && nl < (int)sizeof(line));
  iringbuf_rewrite_last_line(line);
}
