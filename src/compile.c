#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "instructions.h"
#include "preprocess.h"


int main(int argc, char *argv[]) {
  printf("[DEBUG]: starting compilation...\n");
  if (argc < 1) {
    fprintf(stderr, "Too few arguments. Exiting.\n");
    exit(1);
  }
  char *filename = argv[1];
  printf("[DEBUG]: Preprocessing file: %s\n", filename);
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

  while ((linelen = getline(&line, &linecap, fp)) > 0) {
    tmp = line;
    pos = 0;
    while (*tmp != '\0') {
      instructions.data[linenum][pos] = *tmp;
      switch(*tmp++) {
      case '<':
        printf("left(&mem);\n");
        pos++;
        break;
      case '>':
        printf("right(&mem);\n");
        pos++;
        break;
      case '+':
        printf("inc(&mem);\n");
        pos++;
        break;
      case '-':
        printf("dec(&mem);\n");
        pos++;
        break;
      case '[':
        dest_linenum = preprocess_info->open_to_close[linenum][pos].linenum;
        dest_pos = preprocess_info->open_to_close[linenum][pos].pos;
        printf("jmp_if_zero(&mem, &instructions, %d, %d);\n", dest_linenum, dest_pos);
        pos++;
        break;
      case ']':
        dest_linenum = preprocess_info->close_to_open[linenum][pos].linenum;
        dest_pos = preprocess_info->close_to_open[linenum][pos].pos;
        printf("jmp_if_nonzero(&mem, &instructions, %d, %d);\n", dest_linenum, dest_pos);
        pos++;
        break;
      case ',':
        printf("in(&mem);\n");
        pos++;
        break;
      case '.':
        printf("out(&mem);\n");
        pos++;
        break;
      }
    }
    linenum++;
  }
  free_instructions(&instructions);
  return 0;
}
