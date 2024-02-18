#include <stdbool.h>

typedef struct {
  int top;
  size_t sz;
  bool is_empty;
  char* data;
} Stack;

void init_stack(Stack *s, size_t initial_size);
bool push(Stack *s, char c);
bool is_empty(Stack *s);
char peek(Stack *s);
char pop(Stack *s);
void free_stack(Stack *s);
