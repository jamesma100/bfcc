#include <stdbool.h>
#include "preprocess.h"

#ifndef STACK_H
#define STACK_H

typedef struct {
  int top;
  size_t sz;
  bool is_empty;
  BracketInfo* data;
} Stack;

void init_stack(Stack *s, size_t initial_size);
bool push(Stack *s, BracketInfo *bi);
bool is_empty(Stack *s);
BracketInfo peek(Stack *s);
BracketInfo pop(Stack *s);
void free_stack(Stack *s);

#endif
