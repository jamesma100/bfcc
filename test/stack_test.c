#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../src/stack.h"

int main(void) {
  Stack s;
  init_stack(&s, 10);

  for (int i = 0; i < 10; ++i) {
    BracketInfo bi = {2, 5};
    push(&s, &bi);
    BracketInfo actual = pop(&s);
    assert(cmp_bracket_info(&bi, &actual));
  }

  BracketInfo actual_pop = pop(&s);
  BracketInfo null = {-1, -1};
  assert(cmp_bracket_info(&actual_pop, &null));

  BracketInfo actual_peek = peek(&s);
  assert(cmp_bracket_info(&actual_peek, &null));

  for (int i = 0; i < 11; ++i) {
    BracketInfo something = {i, i + 30};
    push(&s, &something);
  }
  BracketInfo expected_pop = {10, 40};
  actual_pop = pop(&s);
  assert(cmp_bracket_info(&actual_pop, &expected_pop));
  assert(s.sz == 20);

  free_stack(&s);
  assert(s.sz == 0);
}
