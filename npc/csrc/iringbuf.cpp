#include <common.h>

#ifdef CONFIG_ITRACE

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

#define IRINGBUF_NR 16

typedef struct {
  int push_pos;
  int refill_pos;
  int count;
  char buf[IRINGBUF_NR][128];
} iringbuf_t;

static iringbuf_t iringbuf = {.push_pos = 0, .refill_pos = 0, .count = 0};

static void iringbuf_push(const char *str) {
  assert(iringbuf.push_pos >= 0 && iringbuf.push_pos < IRINGBUF_NR);
  assert(iringbuf.count >= 0 && iringbuf.count <= IRINGBUF_NR);

  size_t n = strnlen(str, sizeof(iringbuf.buf[0]) - 1);
  memcpy(iringbuf.buf[iringbuf.push_pos], str, n);
  iringbuf.buf[iringbuf.push_pos][n] = '\0';
  iringbuf.push_pos = (iringbuf.push_pos + 1) % IRINGBUF_NR;
  if (iringbuf.count < IRINGBUF_NR) {
    iringbuf.count++;
  }
}

static void iringbuf_refill(const char *str) {
  assert(iringbuf.refill_pos >= 0 && iringbuf.refill_pos < IRINGBUF_NR);
  assert(iringbuf.count > 0 && iringbuf.count <= IRINGBUF_NR);

  size_t n = strnlen(str, sizeof(iringbuf.buf[0]) - 1);
  memcpy(iringbuf.buf[iringbuf.refill_pos], str, n);
  iringbuf.buf[iringbuf.refill_pos][n] = '\0';
  iringbuf.refill_pos = (iringbuf.refill_pos + 1) % IRINGBUF_NR;
}

void iringbuf_print(void) {
  for (int i = 0; i < iringbuf.count; i++) {
    int pos = (iringbuf.push_pos + IRINGBUF_NR - iringbuf.count + i) % IRINGBUF_NR;
    const char *prefix = (i == iringbuf.count - 1 ? ANSI_FMT("  --> ", ANSI_FG_RED) : "      ");
    printf("%s%s\n", prefix, iringbuf.buf[pos]);
  }
}

void iringbuf_push_pc(uint32_t pc) {
  char line[128];
  int n = snprintf(line, sizeof(line), FMT_WORD ": %-32s %s", pc, "???", "?? ?? ?? ??");
  assert(n >= 0 && n < (int)sizeof(line));
  iringbuf_push(line);
}

void iringbuf_backfill_inst(uint32_t pc, uint32_t inst) {
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
  iringbuf_refill(line);
}

#endif
