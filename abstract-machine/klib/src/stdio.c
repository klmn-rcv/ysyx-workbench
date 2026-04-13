#include <klib.h>
#include <limits.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

void putch(char ch);

static char *itoa(int val, char *buf, bool hex_flag, bool unsigned_flag) {
  char *p = buf;
  bool neg_flag = false;
  bool using_unsigned = hex_flag | unsigned_flag;

  if (!using_unsigned) {
    if (val == INT_MIN) {
      strcpy(buf, "-2147483648");
      return buf;
    }
    if(val < 0) {
      neg_flag = true;
      val = -val;
    }
  }

  unsigned int uval = (unsigned int)val;

  do {
    if(hex_flag) {
      *p++ = "0123456789abcdef"[uval % 16];
      uval /= 16;
    }
    else {
      *p++ = (uval % 10) + '0';
      uval /= 10;
    }
  } while(uval > 0);
  if(neg_flag) {
    *p++ = '-';
  }
  *p = '\0';
  return strrev(buf);
}

typedef int (*vformat_output_func)(void *ctx, char ch);

typedef struct {
  char *buf;        // output buffer
  size_t size;      // size of the buffer (including '\0')
  size_t need_write;   // chars needed to write
} vsnprintf_ctx;

static int vsnprintf_output(void *ctx, char ch) {
  vsnprintf_ctx *c = (vsnprintf_ctx *)ctx;
  // write only if there is space (leave room for '\0')
  if (c->buf && c->need_write < c->size - 1) {
    c->buf[c->need_write] = ch;
  }
  c->need_write++;
  return 0;
}

typedef struct {
    int count;        // count of chars that have been output
} vprintf_ctx;

static int vprintf_output(void *ctx, char ch) {
  vprintf_ctx *c = (vprintf_ctx *)ctx;
  putch(ch);
  c->count++;
  return 0;
}

// copy-paste is not a good habit, so I use vformat to implement vprintf and vsnprintf
static int vformat(vformat_output_func output, void *ctx, const char *fmt, va_list ap) {
  while (*fmt) {
    if (*fmt != '%') {
      // common chars
      if (output(ctx, *fmt) != 0) 
        return -1;
      fmt++;
      continue;
    }
    fmt++;
    if (*fmt == '\0') 
      break;   // format string ends up with %，ignore
    char conv = *fmt++;

    if (conv == 's') {
      char *s = va_arg(ap, char *);
      if (s == NULL) s = "(null)";
      while (*s) {
        if (output(ctx, *s) != 0) 
          return -1;
        s++;
      }
    } else if (conv == 'd') {
      int val = va_arg(ap, int);
      char buf[12];         // enough for -2147483648
      itoa(val, buf, false, false);
      char *p = buf;
      while (*p) {
        if (output(ctx, *p) != 0) 
          return -1;
        p++;
      }
    } else if (conv == 'c') {
      char ch = (char)va_arg(ap, int); // char is promoted to int when passed through '...'
      if (output(ctx, ch) != 0) 
        return -1;
    } else if (conv == 'x') {
      int val = va_arg(ap, int);
      char buf[9];          // enough for 8 hex digits + '\0'
      itoa(val, buf, true, false);
      char *p = buf;
      while (*p) {
        if (output(ctx, *p) != 0) 
          return -1;
        p++;
      }
    } else if (conv == 'u') {
      int val = va_arg(ap, int);
      char buf[11];         // enough for 10 digits + '\0'
      itoa(val, buf, false, true);
      char *p = buf;
      while (*p) {
        if (output(ctx, *p) != 0) 
          return -1;
        p++;
      }
    } else {
      // unsupport transform, output as original string
      if (output(ctx, '%') != 0) 
        return -1;
      if (output(ctx, conv) != 0) 
        return -1;
    }
  }

  return 0;
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int r = vprintf(fmt, ap);
  va_end(ap);
  return r;
}

int vprintf(const char *fmt, va_list ap) {
  vprintf_ctx ctx = { .count = 0 };
  int ret = vformat(vprintf_output, &ctx, fmt, ap);
  if(ret < 0)
    return -1;
  return ctx.count;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int r = vsprintf(out, fmt, ap);
  va_end(ap);
  return r;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, SIZE_MAX, fmt, ap);
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int r = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return r;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  vsnprintf_ctx ctx = { .buf = out, .size = n, .need_write = 0 };
  vformat(vsnprintf_output, &ctx, fmt, ap);
  
  if (n > 0 && out) {
    if (ctx.need_write < n) {
      out[ctx.need_write] = '\0';
    }
    else {
      out[n - 1] = '\0';
    }
  }
  return (int)ctx.need_write;
}

int __am_vsscanf_internal(const char *str, const char **end_pstr, const char *fmt, va_list ap) {
  const char *pstr = str;
  const char *pfmt = fmt;
  int item = -1;
  while (*pfmt) {
    char ch = *pfmt ++;
    if (isspace(ch)) {
      for (ch = *pfmt; isspace(ch); ch = *(++ pfmt));
      for (ch = *pstr; isspace(ch); ch = *(++ pstr));
      item ++;
      continue;
    }
    switch (ch) {
      case '%': break;
      default:
        if (*pstr == ch) { // match
          pstr ++;
          item ++;
          continue;
        }
        goto end; // fail
    }

    char *p;
    ch = *pfmt ++;
    switch (ch) {
      // conversion specifier
      case 'd':
        *(va_arg(ap, int *)) = strtol(pstr, &p, 10);
        if (p == pstr) goto end; // fail
        pstr = p;
        item ++;
        break;

      case 'c':
        *(va_arg(ap, char *)) = *pstr ++;
        item ++;
        break;

      default:
        printf("Unsupported conversion specifier '%c'\n", ch);
        assert(0);
    }
  }

end:
  if (end_pstr) {
    *end_pstr = pstr;
  }
  return item;
}

int vsscanf(const char *str, const char *fmt, va_list ap) {
  return __am_vsscanf_internal(str, NULL, fmt, ap);
}

int sscanf(const char *str, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int r = vsscanf(str, fmt, ap);
  va_end(ap);
  return r;
}

int __isoc99_sscanf(const char *str, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int r = vsscanf(str, fmt, ap);
  va_end(ap);
  return r;
}

#endif
