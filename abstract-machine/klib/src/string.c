#include <klib.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  for(len = 0; s[len] != '\0'; len++)
    ;
  return len;
}

char *strcpy(char *dst, const char *src) {
  char *retstr = dst;
  while((*dst++ = *src++) != '\0')
    ;
  return retstr;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for(i = 0; i < n && src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  while(i < n) {
    dst[i++] = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  char *retstr = dst;
  while(*dst++ != '\0')
    ;
  dst--;
  while((*dst++ = *src++) != '\0')
    ;
  return retstr;
}

int strcmp(const char *s1, const char *s2) {
  int ret = 0;
  while((ret = *s1 - *s2) == 0 && *s1++ != '\0' && *s2++ != '\0')
    ;
  return ret;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i;
  int ret = 0;
  for(i = 0; i < n && (ret = s1[i] - s2[i]) == 0 && s1[i] != '\0' && s2[i] != '\0'; i++)
    ;
  return ret;
}

void *memset(void *s, int c, size_t n) {
  unsigned char c_ch = (unsigned char)c;
  unsigned char *s_ch = (unsigned char *)s;
  for(size_t i = 0; i < n; i++) {
    s_ch[i] = c_ch;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *dst_ch = (unsigned char *)dst;
  unsigned char *src_ch = (unsigned char *)src;
  // 需要考虑重叠，根据情况选择不同复制方向
  if(dst_ch < src_ch) { // 正向复制
    for(size_t i = 0; i < n; i++) {
      dst_ch[i] = src_ch[i];
    }
  }
  else if(dst_ch > src_ch) {  // 反向复制
    for(size_t i = n; i > 0; i--) {
      dst_ch[i - 1] = src_ch[i - 1];
    }
    // 另一种写法：
    // for(size_t i = n - 1; i >= 0; i--) {
    //   dst_ch[i] = src_ch[i];
    // }
    // 这种写法是错误的，因为i是无符号类型，最后在i == 0的时候还进行i--会溢出，这是未定义行为！
    // 这样就无法预测i的值，如果按一般情形，i会wrap around，得到一个很大的值，那么循环会永不停止
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *out_ch = (unsigned char *)out;
  unsigned char *in_ch = (unsigned char *)in;
  for(size_t i = 0; i < n; i++) {
    out_ch[i] = in_ch[i];
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  unsigned char *s1_ch = (unsigned char *)s1;
  unsigned char *s2_ch = (unsigned char *)s2;
  int ret = 0;
  for(size_t i = 0; i < n; i++) {
    if((ret = s1_ch[i] - s2_ch[i]) != 0) {
      break;
    }
  }
  return ret;
}

char *strchr(const char *s, int c) {
  do {
    if (*s == c) return (char *)s;
    if (*s == '\0') break;
    s ++;
  } while (1);
  return NULL;
}

char *strrchr(const char *s, int c) {
  const char *p = s + strlen(s);
  do {
    if (*p == c) return (char *)p;
    if (s == p) break;
    p --;
  } while (1);
  return NULL;
}

char *strrev(char *s) {  // string reverse
    if (s == NULL) {
        return NULL;
    }
    char *left = s;
    char *right = s;
    while (*right != '\0') {
        right++;
    }
    right--;
    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    return s;
}

#endif
