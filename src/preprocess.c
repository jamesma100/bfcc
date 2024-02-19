#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

bool cmp_bracket_info(BracketInfo *me, BracketInfo *you) {
  return (me->linenum == you->linenum && me->pos == you->pos);
}

int preprocess_file(char* input_file) {
  FILE *fp;
  fp = fopen(input_file, "r");
  if (fp == NULL) {
    printf("Unable to open file. exiting\n");
    exit(1);
  }
  return preprocess(fp);
}

int preprocess(FILE *fp) {
  Stack brackets;
  init_stack(&brackets, 100);

  int num_cols = 100;
  int num_rows = 100;
  BracketInfo **open_to_close = (BracketInfo**) malloc(sizeof(BracketInfo*) * num_rows);
  for (int i = 0; i < num_rows; ++i) {
    open_to_close[i] = (BracketInfo*)malloc(sizeof(BracketInfo) * num_cols);
  }
  BracketInfo **close_to_open = (BracketInfo**) malloc(sizeof(BracketInfo*) * num_rows);
  for (int i = 0; i < num_rows; ++i) {
    close_to_open[i] = (BracketInfo*)malloc(sizeof(BracketInfo) * num_cols);
  }

  char *line = NULL;
  size_t linecap = 0;
  ssize_t linelen;
  char *tmp = NULL;

  int linenum = 0;
  int pos;
  BracketInfo open_bi;
  BracketInfo close_bi;
  BracketInfo null_bi = {-1, -1};
  while ((linelen = getline(&line, &linecap, fp)) > 0) {
    fwrite(line, linelen, 1, stdout);
    tmp = line;
    pos = 0;
    while (*tmp != '\0') {
      if (*tmp != '[' && *tmp != ']') {
        tmp++;
        pos++;
        continue;
      }
      if (*tmp == '[') {
        open_bi = (BracketInfo){linenum, pos};
        push(&brackets, &open_bi);
      } else {
        open_bi = pop(&brackets);
        if (cmp_bracket_info(&open_bi, &null_bi)) {
          fprintf(stderr, "[ERROR] compiler error - bracket mismatch.\n");
          return 1;
        }
        close_bi = (BracketInfo){linenum, pos};
        open_to_close[open_bi.linenum][open_bi.pos] = close_bi;
        close_to_open[close_bi.linenum][close_bi.pos] = open_bi;
      }
      printf("[DEBUG] bracket info: linenum: %d, pos: %d, char: %c\n", linenum, pos, *tmp);
      pos++;
      tmp++;
    }
    linenum++;
  }
  if (!is_empty(&brackets)) {
    fprintf(stderr, "[ERROR] compiler error - bracket mismatch.\n");
    return 1;
  }
  return 0;
}
