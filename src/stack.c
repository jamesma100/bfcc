#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

void init_stack(Stack *s, size_t initial_size) {
  s->top = -1;
  s->sz = initial_size;
  s->is_empty = true;
  s->data = (char*)malloc(10*sizeof(char));
}

bool push(Stack *s, char c) {
  if (s->top+1 >= s->sz) {
    s->sz *= 2;
    s->data = realloc(s->data, s->sz * sizeof(char));
  }
  *(s->data + (++s->top)) = c;

  if (s->is_empty) {
    s->is_empty = false;
  }
  return true;
}

bool is_empty(Stack *s) {
  return s->is_empty;
}

char peek(Stack *s) {
  if (s->top < 0) {
    fprintf(stderr, "[DEBUG] peek error: stack is empty\n");
    return '\0';
  } else {
    return *(s->data + s->top);
  }
}

char pop(Stack *s) {
  if (s->top < 0) {
    fprintf(stderr, "[DEBUG] pop error: stack is empty\n");
    return '\0';
  } else {
    char res = *(s->data + s->top);
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
