#include "common.h"
#include "sdb.h"
#include "debugpoint.h"

#define NR_WP 32

typedef struct debugpoint {
  int NO;
  struct debugpoint *next;

  DebugPointType type;

  union {
    struct {
      uint32_t old_value;
      char *expr;
    } wp;

    struct {
      uint32_t addr;
    } bp;
  } data;
} DebugPoint;

static DebugPoint pt_pool[NR_WP] = {};
static DebugPoint *head = NULL, *free_ = NULL;

// DebugPoint公共接口
void init_pt_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    pt_pool[i].NO = i;
    pt_pool[i].type = PT_WATCHPOINT;
    pt_pool[i].next = (i == NR_WP - 1 ? NULL : &pt_pool[i + 1]);
  }

  head = NULL;
  free_ = pt_pool;
}

DebugPoint* new_pt() {
  if(free_ == NULL) {
    return NULL;
  }
  else {
    DebugPoint* current = head;
    if(head == NULL) {
      head = free_;
      free_ = free_->next;
      head->next = NULL;
      return head;
    } else {
      while(current->next != NULL) {
        current = current->next;
      }
      current->next = free_;
      free_ = free_->next;
      current->next->next = NULL;
      return current->next;
    }
  }
}

static void clear_pt(DebugPoint *pt) {
  if (pt->type == PT_WATCHPOINT) {
    free(pt->data.wp.expr);
    pt->data.wp.expr = NULL;
    pt->data.wp.old_value = 0;
  } else {
    pt->data.bp.addr = 0;
  }
  pt->type = PT_WATCHPOINT;
}

void free_pt(DebugPoint *pt) {
  DebugPoint *current = head;
  while(current != NULL) {
    if(pt == current)
      break;
    current = current->next;
  }
  if(current != pt || current == NULL)
    assert(0);
  if(pt == head) {
    head = head->next;
    pt->next = free_;   // insert at head of free_
    free_ = pt;
    clear_pt(pt);
  } else {
    DebugPoint *current = head;
    while(current->next != NULL) {
      if(pt == current->next)
        break;
      current = current->next;
    }
    current->next = pt->next;
    pt->next = free_;
    free_ = pt;
    clear_pt(pt);
  }
}

static DebugPoint *find_pt(int NO, DebugPointType type) {
  DebugPoint *current = head;
  while(current != NULL) {
    if(current->NO == NO && current->type == type) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

static bool search_pt(int NO, DebugPointType type) {
  return find_pt(NO, type) != NULL;
}

bool delete_pt(int NO, DebugPointType type) {
  DebugPoint *current = find_pt(NO, type);
  if(current == NULL) {
    return false;
  }
  free_pt(current);
  return true;
}

void display_pt(DebugPointType type) {
  for(int i = 0; i < NR_WP; i++) {  // ensure that the display is in order of NO
    if(search_pt(i, type)) {
      if(type == PT_WATCHPOINT) {
        printf("watchpoint %d: %s\n", i, pt_pool[i].data.wp.expr);
      } else {
        printf("breakpoint %d: 0x%08x\n", i, pt_pool[i].data.bp.addr);
      }
    }
  }
}

// watchpoint专用接口
int init_new_wp(char *s) { // 返回值：0表示正常退出，1表示没有空闲DebugPoint，2表示表达式不合法
  DebugPoint *wp = new_pt();
  if(wp == NULL) {
    return 1;
  }
  bool success = false;
  wp->type = PT_WATCHPOINT;
  wp->data.wp.expr = strdup(s);
  wp->data.wp.old_value = expr(wp->data.wp.expr, &success);
  if(success == false) {
    free_pt(wp);
    return 2;
  }
  return 0;
}

bool check_all_wp_no_change(int *NO, char **expr_str, uint32_t *old_value, uint32_t *new_value) {
  DebugPoint *current = head;
  while(current != NULL) {
    if(current->type == PT_WATCHPOINT) {
      bool success = false;
      uint32_t new_value_tmp = expr(current->data.wp.expr, &success);
      if(new_value_tmp != current->data.wp.old_value) {    // hit watchpoint
        *NO = current->NO;
        *expr_str = current->data.wp.expr;
        *old_value = current->data.wp.old_value;
        *new_value = new_value_tmp;
        current->data.wp.old_value = new_value_tmp;
        return false;
      }
      current->data.wp.old_value = new_value_tmp;
    }
    current = current->next;
  }
  return true;
}

// breakpoint专用接口
int init_new_bp(uint32_t addr) {  // 返回值：0表示正常退出，1表示没有空闲DebugPoint
  DebugPoint *bp = new_pt();
  if(bp == NULL) {
    return 1;
  }

  bp->type = PT_BREAKPOINT;
  bp->data.bp.addr = addr;
  return 0;
}

bool check_bp_hit(uint32_t pc, int *NO, uint32_t *addr) {
  DebugPoint *current = head;
  while(current != NULL) {
    if(current->type == PT_BREAKPOINT && current->data.bp.addr == pc) {
      *NO = current->NO;
      *addr = current->data.bp.addr;
      return true;
    }
    current = current->next;
  }
  return false;
}
