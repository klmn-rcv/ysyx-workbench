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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char clear_u_buf[65536] = {};  // 数字没有后缀u的表达式，作为生成结果输出
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static int pos; // buf的下标指针
static int buf_overflow_flag; // 缓冲区溢出标志

static uint32_t choose(uint32_t num) {
  return rand() % num;
}

static void gen(char c) {
  if(buf_overflow_flag) {
    return;
  }
  else if(pos + 1 < 65536) {
    buf[pos++] = c;
    buf[pos] = '\0';
  }
  else {
    buf_overflow_flag = 1;
  }
}

static void gen_num() {
  uint32_t num = rand() & 0xffffffff;
  char temp[32];
  int len = sprintf(temp, "%uu", num); // 这里要在数字后面加u，否则gcc会进行有符号运算
  if(pos + len < 65536) {
    strncpy(buf + pos, temp, len);
    pos += len;
    buf[pos] = '\0';
  }
  else {
    buf_overflow_flag = 1;
  }
}

static void gen_rand_op() {
  switch(choose(4)) {
    case 0: gen('+'); break;
    case 1: gen('-'); break;
    case 2: gen('*'); break;
    default: gen('/'); break;
  }
}

static void gen_rand_space() {
  int rand_num = rand() % 10000;
  int space_num = 0;
  for(int i = 10; i > 1; i--) {
    if(rand_num % i == 0) {
      space_num = i - 1;
      break;
    }
  }
  for(int i = 0; i < space_num; i++) {
    gen(' ');
  }
}

static void init_buf() {
  pos = 0;
  buf[0] = '\0';
  buf_overflow_flag = 0;
}

static void gen_rand_expr(int depth) {
  // 若递归深度过大，直接生成数字，防止栈溢出
  if (depth > 30) {
    gen_num();
    return;
  }
  switch(choose(3) + (depth == 0)) { // 避免生成只有单个数的表达式（这些表达式甚至占总数的1/3）
    case 0:
      gen_num();
      break;
    case 1:
      gen('(');
      gen_rand_space();
      gen_rand_expr(depth + 1);
      gen_rand_space();
      gen(')');
      break;
    default:
      gen_rand_expr(depth + 1);
      gen_rand_space();
      gen_rand_op();
      gen_rand_space();
      gen_rand_expr(depth + 1);
      break;
  }
}

static void clear_u() {
  clear_u_buf[0] = '\0';
  int num_u = 0;
  int i;
  for(i = 0; buf[i] != '\0'; i++) {
    assert(i < 65536);
    if(buf[i] == 'u') {
      num_u++;
      continue;
    }
    else {
      clear_u_buf[i - num_u] = buf[i];
    }
  }
  assert(buf[i] == '\0');
  clear_u_buf[i - num_u] = '\0';
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    // if(i % 200 == 0) {
    //   fprintf(stderr, "DEBUG: i = %d\n", i);
    // }
    
    init_buf();
    gen_rand_expr(0);

    if(buf_overflow_flag) {
      i--;
      continue;
    }

    sprintf(code_buf, code_format, buf);

    // printf("DEBUG: code_buf is %s\n", code_buf);
    // printf("DEBUG: buf is %s\n", buf);
  
    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -Werror /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) {
      i--;
      continue;
    }

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    clear_u();  // 删除表达式中数字的后缀u

    printf("%u %s\n", result, clear_u_buf);
  }
  return 0;
}
