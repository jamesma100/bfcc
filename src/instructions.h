#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef struct {
  char *head;
  char *data;
  char *ip;
  size_t initial_size;
} Memory;

void init_memory(Memory *mem, size_t initial_size);
void display_first_n(Memory *mem, int n);
void right(Memory *mem);
void left(Memory *mem);
void inc(Memory *mem);
void dec(Memory *mem);
char out(Memory *mem);
void in(Memory *mem);
void jmp_if_zero(Memory *mem, char *dest);
void jmp_if_nonzero(Memory *mem, char *dest);

#endif
