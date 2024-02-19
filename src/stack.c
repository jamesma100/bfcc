#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

void init_stack(Stack *s, size_t initial_size) {
  s->top = -1;
  s->sz = initial_size;
  s->is_empty = true;
  s->data = (BracketInfo*)malloc(100*sizeof(BracketInfo));
}

bool push(Stack *s, BracketInfo *bi) {
  if (s->top+1 >= s->sz) {
    s->sz *= 2;
    s->data = realloc(s->data, s->sz * sizeof(BracketInfo));
  }
  *(s->data + (++s->top)) = *bi;

  if (s->is_empty) {
    s->is_empty = false;
  }
  return true;
}

bool is_empty(Stack *s) {
  return s->is_empty;
}

BracketInfo peek(Stack *s) {
  if (s->top < 0) {
    fprintf(stderr, "[DEBUG] peek error: stack is empty\n");
    return (BracketInfo){-1, -1};
  } else {
    return *(s->data + s->top);
  }
}

BracketInfo pop(Stack *s) {
  if (s->top < 0) {
    fprintf(stderr, "[DEBUG] pop error: stack is empty\n");
    return (BracketInfo){-1, -1};
  } else {
    BracketInfo res = *(s->data + s->top);
    s->top--;
    if (s->top == -1) {
      s->is_empty = true;
    }
    return res;
  }
}

void free_stack(Stack *s) {
  free(s->data);
  s->data = NULL;
  s->sz = 0;
  s->top = -1;
}
