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
 	inc(&mem);
  assert(out(&mem) == '1');
 	right(&mem);
 	right(&mem);
 	inc(&mem);
 	inc(&mem);
 	assert(out(&mem) == '2');
 	jmp_if_nonzero(&mem, 2);
 	assert(out(&mem) == '1');
  printf("[TEST] all instructions tests passed!\n");
	return 0;
}
