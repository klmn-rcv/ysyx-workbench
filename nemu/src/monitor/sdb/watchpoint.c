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

#include "sdb.h"

#include <string.h>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  uint32_t old_value;
  char *expr;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}


WP* new_wp() {
  if(free_ == NULL)
    assert(0);
  else {
    WP* current = head;
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
void free_wp(WP *wp) {
  WP *current = head;
  while(current != NULL) {
    if(wp == current)
      break;
    current = current->next;
  }
  if(current != wp || current == NULL)
    assert(0);
  if(wp == head) {
    head = head->next;
    wp->next = free_;   // insert at head of free_
    free_ = wp;
    free(wp->expr);
    wp->expr = NULL;
    wp->old_value = 0;
  } else {
    WP *current = head;
    while(current->next != NULL) {
      if(wp == current->next)
        break;
      current = current->next;
    }
    current->next = wp->next;
    wp->next = free_;
    free_ = wp;
    free(wp->expr);
    wp->expr = NULL;
    wp->old_value = 0;
  }
}

bool init_new_wp(char *s) {
  WP *wp = new_wp();
  bool success = false;
  wp->expr = strdup(s);
  wp->old_value = expr(wp->expr, &success);
  if(success == false) {
    return false;
  }
  return true;
}

bool delete_wp(int NO) {
  WP *current = head;
  while(current != NULL) {
    if(current->NO == NO)
      break;
    current = current->next;
  }
  if(current->NO != NO) {
    return false;
  }
  free_wp(current);
  return true;
}

bool check_all_wp_no_change(int *NO, char **expr_str) {
  WP *current = head;
  while(current != NULL) {
    bool success = false;
    word_t new_value = expr(current->expr, &success);
    if(new_value != current->old_value) {    // hit watchpoint
      *NO = current->NO;
      *expr_str = current->expr;
      current->old_value = new_value;
      return false;
    }
    current->old_value = new_value;
    current = current->next;
  }
  return true;
}

bool search_wp(int NO) {  // search wp by NO
  WP *current = head;
  while(current != NULL) {
    if(current->NO == NO) {
      return true;
    }
    current = current->next;
  }
  return false;
}

void wp_display() {
  for(int i = 0; i < NR_WP; i++) {  // ensure that the display is in order of NO
    if(search_wp(i)) {
      printf("watchpoint %d: %s\n", i, wp_pool[i].expr);
    }
  }
}
