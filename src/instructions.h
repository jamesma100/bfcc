#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef struct {
  char *head;
  char *data;
  char *ptr;
  size_t initial_size;
} Memory;

typedef struct {
  int num_rows;
  int num_cols;
  char **data;
  int linenum;
  int pos;
} Instructions;

void init_memory(Memory *mem, size_t initial_size);
void free_memory(Memory *mem);
void init_instructions(Instructions *instructions, int num_rows, int num_cols);
void free_instructions(Instructions *instructions);
void display_first_n(Memory *mem, int n);
void right(Memory *mem);
void left(Memory *mem);
void inc(Memory *mem);
void dec(Memory *mem);
char out(Memory *mem);
void in(Memory *mem);

#endif
