#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "../src/stack.h"

int main(void) {
  Stack s;
  init_stack(&s, 10);

  for (int i = 0; i < 10; ++i) {
    push(&s, 'a' + i);
    char actual = pop(&s);
    assert('a' + i == actual);
  }

  assert(pop(&s) == '\0');
  assert(peek(&s) == '\0');

  for (int i = 0; i < 11; ++i) {
    push(&s, 'a');
  }
  assert(pop(&s) == 'a');
  assert(s.sz == 20);

  free_stack(&s);
  assert(s.sz == 0);
}
