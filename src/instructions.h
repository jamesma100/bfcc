#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef struct {
  char *data;
  char *ip;
} Memory;

void init_memory(Memory *mem, size_t initial_size);
void right(Memory *mem);
void left(Memory *mem);
void inc(Memory *mem);
void dec(Memory *mem);
char out(Memory *mem);
void in(Memory *mem);
void jmp_if_zero(Memory *mem, int offset);
void jmp_if_nonzero(Memory *mem, int offset);

#endif
