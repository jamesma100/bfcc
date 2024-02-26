#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/instructions.h"

int main(void) {
  Memory mem;
  init_memory(&mem, 200);
  assert(mem.data == mem.ptr);
  for (int i = 0; i < 10; ++i) {
    *(mem.ptr + i) = '0';
    assert(*(mem.ptr + i) == '0');
  }
  // 0 0 0 0 0 0 0 0 0 0
  // |
  inc(&mem);
  // 1 0 0 0 0 0 0 0 0 0
  // |
  assert(out(&mem) == 1);
  right(&mem);
  right(&mem);
  // 1 0 0 0 0 0 0 0 0 0
  //     |
  inc(&mem);
  inc(&mem);
  // 1 0 2 0 0 0 0 0 0 0
  //     |
  assert(out(&mem) == 2);

  free_memory(&mem);

  printf("[TEST] all instructions tests passed!\n");
  return 0;
}
