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

  int num_rows = 100;
  int num_cols = 100;

  Instructions instructions;
  init_instructions(&instructions, num_rows, num_cols);

  jmp_if_nonzero(&mem, &instructions, 2, 7);
  assert(
    instructions.linenum == 2 &&
    instructions.pos == 7
  );
  right(&mem);
  // 1 0 2 0 0 0 0 0 0 0
  //       |
  jmp_if_zero(&mem, &instructions, 6, 9);
  assert(
    instructions.linenum == 6 &&
    instructions.pos == 9
  );

  free_instructions(&instructions);
  free_memory(&mem);

  printf("[TEST] all instructions tests passed!\n");
  return 0;
}
