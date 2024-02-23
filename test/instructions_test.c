#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/instructions.h"

int main(void) {
  Memory mem;
  init_memory(&mem, 200);
  assert(mem.data == mem.ip);
 	for (int i = 0; i < 10; ++i) {
 		*(mem.ip + i) = '0';
    assert(*(mem.ip + i) == '0');
 	}
  // 0 0 0 0 0 0 0 0 0 0
  // |
 	inc(&mem);
  // 1 0 0 0 0 0 0 0 0 0
  // |
  assert(out(&mem) == '1');
 	right(&mem);
 	right(&mem);
  // 1 0 0 0 0 0 0 0 0 0
  //     |
 	inc(&mem);
 	inc(&mem);
  // 1 0 2 0 0 0 0 0 0 0
  //     |
 	assert(out(&mem) == '2');
  jmp_if_nonzero(&mem, mem.head);
  // 1 0 2 0 0 0 0 0 0 0
  // |
 	assert(out(&mem) == '1');
  right(&mem);
  right(&mem);
  right(&mem);
  // 1 0 2 0 0 0 0 0 0 0
  //       |
  jmp_if_zero(&mem, mem.head + 6);
  // 1 0 2 0 0 0 0 0 0 0
  //             |
  assert((unsigned char)*mem.ip == (unsigned char)*(mem.head + 6));
  inc(&mem);
  inc(&mem);
  inc(&mem);
  inc(&mem);
  // 1 0 2 0 0 0 4 0 0 0
  //             |
  jmp_if_zero(&mem, mem.head + 1);
  assert(out(&mem) == '4');
  printf("[TEST] all instructions tests passed!\n");
	return 0;
}
