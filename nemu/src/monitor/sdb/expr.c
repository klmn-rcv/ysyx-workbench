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

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

#include <assert.h>

enum {
  TK_NOTYPE = 256, TK_NUMBER, TK_PLUS, TK_MINUS, TK_MULTI, TK_DEVI, TK_EQ, TK_INEQ, 
  TK_AND, TK_OR, TK_LEFTPAR, TK_RIGHTPAR, TK_REG, TK_DEREF, TK_NEG
  
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"0", '0'},
  {"1", '1'},
  {"2", '2'},
  {"3", '3'},
  {"4", '4'},
  {"5", '5'},
  {"6", '6'},
  {"7", '7'},
  {"8", '8'},
  {"9", '9'},
  {"\\+", TK_PLUS},         // plus
  {"\\-", TK_MINUS},         // minus
  {"\\*", TK_MULTI},         // multiply (or maybe dereference)
  {"\\/", TK_DEVI},         // devide
  {"==", TK_EQ},        // equal
  {"!=", TK_INEQ},      // inequal
  {"&&", TK_AND},       // and
  {"\\|\\|", TK_OR},    // or
  {"\\(", TK_LEFTPAR},    // left parentheses
  {"\\)", TK_RIGHTPAR},    // right parentheses
  {"\\$", TK_REG},         // register
  {"a", 'a'},             // letter in register name
  {"r", 'r'},
  {"p", 'p'},
  {"t", 't'},
  {"g", 'g'},
  {"s", 's'},
  {"x", 'x'}              // x in '0x...' (hex number)
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[256];
} Token;

#define MAX_TOKENS 65536

static Token tokens[MAX_TOKENS] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  int num_index = 0;
  int reg_index = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if(nr_token >= MAX_TOKENS) {
        printf("make_token error: too many tokens\n");
        return false;
      }
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        // printf("DEBUG: make_token: token_type is %d\n", rules[i].token_type);

        switch (rules[i].token_type) {          
          case TK_NOTYPE:  
            num_index = 0;
            reg_index = 0;
            break;
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':  
          case '6':
          case '7':
          case '8':
          case '9':
            if(tokens[nr_token - 1].type == TK_REG) {
              tokens[nr_token - 1].str[reg_index++] = rules[i].token_type;
              tokens[nr_token - 1].str[reg_index] = '\0';
            }
            else if(num_index == 0)
              tokens[nr_token++].type = TK_NUMBER;
            if(tokens[nr_token - 1].type == TK_NUMBER) {
              tokens[nr_token - 1].str[num_index++] = rules[i].token_type;
              tokens[nr_token - 1].str[num_index] = '\0';
            }
            
            break;
          case TK_PLUS:
          case TK_MINUS:
          case TK_MULTI:
          case TK_DEVI:
          case TK_AND:
          case TK_OR:
          case TK_EQ:
          case TK_INEQ:
          case TK_LEFTPAR:
          case TK_RIGHTPAR:
            tokens[nr_token++].type = rules[i].token_type;
            num_index = 0;
            reg_index = 0;
            break;
          
          case TK_REG:
              tokens[nr_token++].type = TK_REG;
              num_index = 0;
              reg_index = 0;
              tokens[nr_token - 1].str[0] = '\0';
            
            break;
          case 'a':
          case 'r':
          case 'p':
          case 't':
          case 'g':
          case 's':
            if(tokens[nr_token - 1].type == TK_REG) {
              tokens[nr_token - 1].str[reg_index++] = rules[i].token_type;
              tokens[nr_token - 1].str[reg_index] = '\0';
            }
            else {
              printf("make_token error: invalid token '%c'\n", rules[i].token_type);
              return false;
            }
            break;

          case 'x':
            if(tokens[nr_token - 1].type == TK_REG) {
              tokens[nr_token - 1].str[reg_index++] = rules[i].token_type;
              tokens[nr_token - 1].str[reg_index] = '\0';
            }
            else if(tokens[nr_token - 1].type == TK_NUMBER && num_index == 1) {  // hex number
              tokens[nr_token - 1].str[num_index++] = 'x';
              tokens[nr_token - 1].str[num_index] = '\0';
            }
            break;
          
          default: 
            assert(0);
            break;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

bool check_parentheses(int p, int q) {
  // printf("DEBUG: check_parentheses (begin): p is %d, q is %d\n", p, q);

  int par_diff = 0;  // the difference of left and right parenthese number
  for(int i = p; i <= q; i++) {
    if(tokens[i].type == TK_LEFTPAR)
      par_diff++;
    else if(tokens[i].type == TK_RIGHTPAR)
      par_diff--;

    // printf("DEBUG: check_parentheses (1): par_diff is %d\n", par_diff);

    if(i != p && i != q && par_diff == 0) {
      // printf("DEBUG: check_parentheses (2): par_diff is %d\n", par_diff);
      return false;
    }
  }
  if(par_diff == 0 && tokens[p].type == TK_LEFTPAR && tokens[q].type == TK_RIGHTPAR)
    return true;
  else {
    return false;
  }
}

int find_mainop(int p, int q, bool *valid) {  // return the index of the main operation
  // printf("DEBUG: Enter find_mainop, p is %d, q is %d\n", p, q);
  int par_diff = 0;     // judge whether in parentheses
  int index = -1;
  bool and_or_flag = false;
  bool eq_ineq_flag = false;
  bool plus_minus_flag = false;
  for(int i = p; i <= q; i++) {
    if(tokens[i].type == TK_LEFTPAR)
      par_diff++;
    else if(tokens[i].type == TK_RIGHTPAR)
      par_diff--;
    if(par_diff < 0) {
      // Invalid expression!!!
      // printf("DEBUG: find_mainop (1): par_diff = %d, invalid expression\n", par_diff);
      *valid = false;
      return -1;
    }
    if(par_diff == 0) {
      if(tokens[i].type == TK_AND || tokens[i].type == TK_OR) {
        index = i;
        and_or_flag = true;
      }
      else if(and_or_flag == false && (tokens[i].type == TK_EQ || tokens[i].type == TK_INEQ)) {
        index = i;
        eq_ineq_flag = true;
      }
      else if(and_or_flag == false && eq_ineq_flag == false && (tokens[i].type == TK_PLUS || tokens[i].type == TK_MINUS)) {
        index = i;
        plus_minus_flag = true;
      }
      else if(and_or_flag == false && eq_ineq_flag == false && plus_minus_flag == false && (tokens[i].type == TK_MULTI || tokens[i].type == TK_DEVI)) {
        index = i;
      }
    }
  }
  if(par_diff != 0) {
    // Invalid expression!!!
    // printf("DEBUG: find_mainop (2): par_diff == %d, invalid expression\n", par_diff);
    *valid = false;
    return -1;
  }
  // printf("DEBUG: Exit find_mainop, p is %d, q is %d, index is %d\n", p, q, index);
  return index;
}


word_t eval(int p, int q, bool *success) {
  if(*success == false) {
    return 0;
  } 
  // printf("DEBUG: eval (begin): p is %d, q is %d\n", p, q);
  // *success = true;
  if (p > q) {
    /* Bad expression */
    assert(0);
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number (or somrthing else? --like TK_DEREF and TK_REG).
     * Return the value of the number.
     */
    if(tokens[p].type == TK_NUMBER) {
      int ret = 0;
      if(tokens[p].str[0] == '0' && tokens[p].str[1] == 'x') { // hex number
        for(int i = 2; i < 32; i++) {
          if(tokens[p].str[i] == '\0') break;
          ret = ret * 16 + tokens[p].str[i] - '0';
        }
      } else {         // decimal number
        for(int i = 0; i < 32; i++) {
          if(tokens[p].str[i] == '\0') break;
          ret = ret * 10 + tokens[p].str[i] - '0';
        }
      }
      // printf("DEBUG: eval (1): p: %d, q: %d, ret: %d\n", p, q, ret);
      return ret;
    }else if(tokens[p].type == TK_REG) {
      word_t isa_reg_str2val(const char *s, bool *success);
      // bool success = false;
      // printf("DEBUG: tokens[p].str (reg name): %s\n", tokens[p].str);
      word_t ret = isa_reg_str2val(tokens[p].str, success);
      if(*success == false) {
        printf("eval: reg name not found\n");
        // assert(0);
      }
      // printf("DEBUG: eval (2): p: %d, q: %d, ret: %d\n", p, q, ret);
      return ret;
    } else {
      assert(0);
    }
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    word_t ret = eval(p + 1, q - 1, success);
    // printf("DEBUG: eval (3): p: %d, q: %d, ret: %d\n", p, q, ret);
    return ret;
  }
  else {
    /* We should do more things here. */
    int op_index = find_mainop(p, q, success);
    if(*success == false) {
      printf("eval: invalid expression\n");
      return 0;
    }
    // printf("DEBUG: op_index is %d\n", op_index);
    if(op_index == -1) {  // only TK_DEREF can go into this if
      // printf("DEBUG: p is %d, q is %d, tokens[p].type is %d\n", p, q, tokens[p].type);
      // assert(tokens[p].type == TK_DEREF);
      if(tokens[p].type == TK_DEREF) {
        // printf("DEBUG: eval: p is %d, q is %d\n", p, q);
        word_t vaddr_debug_read(vaddr_t addr, int len);  // read data in memory
        vaddr_t vaddr = eval(p + 1, q, success);  // p + 1 to q (p is TK_DEREF)
        word_t ret = vaddr_debug_read(vaddr, 4);
        // printf("DEBUG: eval (4): p: %d, q: %d, ret: %d\n", p, q, ret);
        return ret;
      }
      else if(tokens[p].type == TK_NEG) {
        word_t ret = -eval(p + 1, q, success);
        // printf("DEBUG: eval (5): p: %d, q: %d, ret: %d\n", p, q, ret);
        return ret;
      }
      else if(tokens[p].type == TK_REG) {
        printf("eval: invalid expression (invalid '$')\n");
        *success = false;
        return 0;
      }
      else {
        assert(0);
      }
    }

    else {
      word_t op1 = eval(p, op_index - 1, success);
      word_t op2 = eval(op_index + 1, q, success);
      switch (tokens[op_index].type) {
        case TK_PLUS: return op1 + op2;
        case TK_MINUS: return op1 - op2;
        case TK_MULTI: return op1 * op2;
        case TK_DEVI: 
          if(op2 == 0) {
            printf("eval error: divide by zero! p is %d, q is %d, op_index is %d\n", p, q, op_index);
            *success = false;
            return 0;
          }
          return op1 / op2;
        case TK_AND:   return op1 && op2;
        case TK_OR:    return op1 || op2;
        case TK_EQ:    return op1 == op2;
        case TK_INEQ:  return op1 != op2;
        
        default:
          assert(0);
          break;
      }
    }
  }
}


// static void print_type(int idx) {
//   idx -= 256;
//   char *type_names[] = { "TK_NOTYPE", "TK_NUMBER", "TK_PLUS", "TK_MINUS", "TK_MULTI", "TK_DEVI", "TK_EQ", "TK_INEQ", 
//   "TK_AND", "TK_OR", "TK_LEFTPAR", "TK_RIGHTPAR", "TK_REG", "TK_DEREF", "TK_NEG" };
//   printf("%s", type_names[idx]);
// }

//// 辅助debug的打印token数组的函数
// static void print_tokens() {
//   for(int i = 0; i < nr_token; i++) {
//     printf("tokens[%d]: type: ", i);
//     print_type(tokens[i].type);  
//     printf(", str: %s\n", tokens[i].str);
//   }
// }

word_t expr(char *e, bool *success) {
  // printf("DEBUG: expr: e is %s\n", e);
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == TK_MULTI && (i == 0 || tokens[i - 1].type == TK_LEFTPAR || tokens[i - 1].type == TK_PLUS
                                  || tokens[i - 1].type == TK_MINUS || tokens[i - 1].type == TK_MULTI
                                  || tokens[i - 1].type == TK_DEVI || tokens[i - 1].type == TK_AND 
                                  || tokens[i - 1].type == TK_OR || tokens[i - 1].type == TK_EQ 
                                  || tokens[i - 1].type == TK_INEQ || tokens[i - 1].type == TK_NEG) ) {
      tokens[i].type = TK_DEREF;
    }
    else if (tokens[i].type == TK_MINUS && (i == 0 || tokens[i - 1].type == TK_LEFTPAR || tokens[i - 1].type == TK_PLUS
                                  || tokens[i - 1].type == TK_MINUS || tokens[i - 1].type == TK_MULTI
                                  || tokens[i - 1].type == TK_DEVI || tokens[i - 1].type == TK_AND 
                                  || tokens[i - 1].type == TK_OR || tokens[i - 1].type == TK_EQ 
                                  || tokens[i - 1].type == TK_INEQ || tokens[i - 1].type == TK_NEG) ) {
      tokens[i].type = TK_NEG;
    }
  }

  // print_tokens();

  *success = true;
  word_t ret = eval(0, nr_token - 1, success);
  return ret;
}
