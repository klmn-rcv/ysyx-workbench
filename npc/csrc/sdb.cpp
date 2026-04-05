#include <cstdio>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include "state.h"
#include "cpu-exec.h"
#include "debug.h"
#include "dpi-c.h"

NPCState npc_state = { .state = NPC_STOP, .cycles = 0, .halt_pc = 0, .halt_ret = 0 };

static bool is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  return -1;
}

static int cmd_si(char *args) {
  if(args == NULL)
    cpu_exec(1);
  else{
    int N = 0;
    for(int i = 0; i < strlen(args); i++){
      if(isdigit(args[i]))
        N = N * 10 + args[i] - '0';
      else {
        std::printf("si: args error: not a number\n");
        return 0;
      }
    }
    cpu_exec(N);
  }
  return 0;
}

static int cmd_info(char *args) {
  if(args == NULL) {
    std::printf("info: need an argument\n");
    return 0;
  }
  void wp_display();
  if(strcmp(args, "r")==0 || strcmp(args, "register")==0){
    reg_display();
  }else if(strcmp(args, "w")==0 || strcmp(args, "watchpoint")==0){
    wp_display();
  }
  else {
    std::printf("info: invalid option '%s'\n", args);
  }
  return 0;
}

static int cmd_x(char *args) {
  if(args == NULL) {
    std::printf("x: need an argument\n");
    return 0;
  }
  args = strtok(args, " ");
  int N = 0;
  for(int i = 0; i < strlen(args); i++){
    if(isdigit(args[i]))
      N = N * 10 + args[i] - '0';
    else {
      std::printf("x: args error: not a number\n");
      return 0;
    }
  }
  args = args + strlen(args) + 1;
  bool success = false;
  uint32_t addr = expr(args, &success);
  if(success == false) {
    std::printf("x: invalid expression\n");
    return 0;
  }
  // uint32_t pmem_read(uint32_t addr);  // read data in memory
  for(int i = 0; i < N; i++) {
    if(i % 4 == 0) {
      std::printf(ANSI_FG_GREEN "0x%08x:" ANSI_NONE "\t", addr);
    }
    std::printf("0x%08x\t", pmem_read(addr));
    addr += 4;
    if(i % 4 == 3)
      std::printf("\n");
  }
  if(N % 4 != 0)
    std::printf("\n");
  return 0;
}

static int cmd_p(char *args) {
  if(args == NULL) {
    std::printf("p: need an argument\n");
    return 0;
  }
  bool success = false;
  uint32_t value = expr(args, &success);
  if(success == false) {
    std::printf("p: failed for previous error\n");
    return 0;
  }
  std::printf("%u\n", value);
  return 0;
}

static int cmd_w(char *args) {
// #ifndef CONFIG_WATCHPOINT
//   std::printf("ATTENTION: watchpoint not activated\n");
// #endif
  if(args == NULL) {
    std::printf("w: need an argument\n");
    return 0;
  }
  int init_new_wp(char *s);
  int exit_status = init_new_wp(args);
  if(exit_status == 1) {
    std::printf("w: invalid expression\n");
    return 0;
  }
  else if(exit_status == 2) {
    std::printf("w: too much watchpoints existing\n");
    return 0;
  }
  return 0;
}

static int cmd_d(char *args) {
// #ifndef CONFIG_WATCHPOINT
//   std::printf("ATTENTION: watchpoint not activated\n");
// #endif
  if(args == NULL) {
    std::printf("d: need an argument\n");
    return 0;
  }
  bool success1 = false;
  uint32_t NO = expr(args, &success1);
  if(success1 == false) {
    std::printf("d: invalid expression\n");
    return 0;
  }
  bool delete_wp(int NO);
  bool success2 = delete_wp(NO);
  if(success2 == false) {
    std::printf("d: watchpoint not found\n");
    return 0;
  }
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "si", "Single-step execution", cmd_si },
  { "info", "Print register status and watchpoint information", cmd_info },
  { "x", "Output consecutive N 4 bytes in the address in hexadecimal", cmd_x },
  { "p", "Find the value of the expression EXPR", cmd_p },
  { "w", "Suspend program execution when the value of expression EXPR changes", cmd_w },
  { "d", "Deletes the watchpoint with ID N", cmd_d }
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      std::printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        std::printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    std::printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

//// 测试expr表达式求值函数
// static void test_expr() {
//   FILE *fp = fopen("tools/gen-expr/build/input", "r");

//   char line[65536];
//   while (fgets(line, sizeof(line), fp) != NULL) {
//     line[strcspn(line, "\n")] = '\0';
//     char *space = strchr(line, ' ');
//     assert(space != NULL);
//     *space = '\0';
//     char *golden_val_str = line;
//     char *expression = golden_val_str + strlen(golden_val_str) + 1;
//     uint32_t golden_value = atoi(golden_val_str);

//     bool success = false;
//     uint32_t value = expr(expression, &success);
//     if(success == false) {
//       std::printf("test_expr: expr parsing failed\n");
//       assert(0);
//     }
//     if(value != golden_value) {
//       std::printf("test_expr: calculate failed!\n");
//       assert(0);
//     }
//   }
//   std::printf("test_expr: pass!\n");
// }

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  // test_expr(); // 测试expr表达式求值函数

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

// #ifdef CONFIG_DEVICE
//     extern void sdl_clear_event_queue();
//     sdl_clear_event_queue();
// #endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { 
          npc_state.state = NPC_QUIT; // prevent error information after quit
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) { std::printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
