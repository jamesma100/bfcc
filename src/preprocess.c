#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "preprocess.h"
#include "stack.h"

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

  char *line = NULL;
  size_t linecap = 0;
  ssize_t linelen;
  char *tmp = NULL;

  int linenum = 0;
  int pos;
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
        push(&brackets, *tmp);
      } else {
        if (pop(&brackets) == '\0') {
          fprintf(stderr, "[ERROR] compiler error - bracket mismatch.\n");
          return 1;
        }
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
