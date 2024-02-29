#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "instructions.h"
#include "preprocess.h"


int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Too few arguments. Exiting.\n");
    exit(1);
  }
  char *filename = argv[1];
  PreprocessInfo *preprocess_info = preprocess_file(filename);

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Unable to open file. Exiting\n");
    exit(1);
  }
  char *line = NULL;
  size_t linecap = 0;
  ssize_t linelen;
  char *tmp = NULL;

  int linenum = 0;
  int pos;
  int dest_linenum;
  int dest_pos;

  int num_rows = 200;
  int num_cols = 200;
  Instructions instructions;
  init_instructions(&instructions, num_rows, num_cols);

  Memory mem;
  init_memory(&mem, 100);

  while ((linelen = getline(&line, &linecap, fp)) > 0) {
    tmp = line;
    pos = 0;
    while (*tmp != '\0') {
      instructions.data[linenum][pos] = *tmp;
      tmp++;
      pos++;
    }
    linenum++;
  }
  fclose(fp);
  linenum = 0;
  pos = 0;
  char instruction;
  while (true) {
    if (linenum >= num_rows || linenum >= num_cols) {
      break;
    }
    if (pos == 0 && instructions.data[linenum][pos] == '\0') {
      break;
    }
    if (instructions.data[linenum][pos] == '\0') {
      linenum++;
      pos = 0;
      continue;
    }
    instruction = instructions.data[linenum][pos];
    switch(instruction) {
      case '<':
        left(&mem);
        pos++;
        break;
      case '>':
        right(&mem);
        pos++;
        break;
      case '+':
        inc(&mem);
        pos++;
        break;
      case '-':
        dec(&mem);
        pos++;
        break;
      case '[':
        dest_linenum = preprocess_info->open_to_close[linenum][pos].linenum;
        dest_pos = preprocess_info->open_to_close[linenum][pos].pos + 1;
        if (*(mem.ptr) == 0) {
          linenum = dest_linenum;
          pos = dest_pos;
        } else {
          pos++;
        }
        break;
      case ']':
        dest_linenum = preprocess_info->close_to_open[linenum][pos].linenum;
        dest_pos = preprocess_info->close_to_open[linenum][pos].pos + 1;
        if (*(mem.ptr) != 0) {
          linenum = dest_linenum;
          pos = dest_pos;
        } else {
          pos++;
        }
        break;
      case ',':
        in(&mem);
        pos++;
        break;
      case '.':
        out(&mem);
        pos++;
        break;
      default:
        pos++;
        break;
    }
  }
  free_preprocess_info(preprocess_info);
  free_instructions(&instructions);
  free_memory(&mem);
  return 0;
}
