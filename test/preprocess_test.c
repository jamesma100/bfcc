#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../src/stack.h"
#include "../src/preprocess.h"

int main(void) {
	assert(preprocess_file("./input/input.txt") == 0);
	assert(preprocess_file("./input/bad_input1.txt") == 1);
	assert(preprocess_file("./input/bad_input2.txt") == 1);
	return 0;
}
