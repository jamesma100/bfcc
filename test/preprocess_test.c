#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../src/stack.h"
#include "../src/preprocess.h"

int main(void) {
	PreprocessInfo *preprocess_info = preprocess_file("./input/hello_world_long.bf");
	assert(preprocess_info != NULL);
	assert(
		preprocess_info->open_to_close[0][14].linenum == 0 &&
		preprocess_info->open_to_close[0][14].pos == 33
	);
	assert(
		preprocess_info->close_to_open[0][33].linenum == 0 &&
		preprocess_info->close_to_open[0][33].pos == 14
	);
	assert(
		preprocess_info->open_to_close[0][43].linenum == 0 &&
		preprocess_info->open_to_close[0][43].pos == 45
	);
	assert(
		preprocess_info->close_to_open[0][45].linenum == 0 &&
		preprocess_info->close_to_open[0][45].pos == 43
	);
	free_bi_array(preprocess_info->open_to_close);
	free_bi_array(preprocess_info->close_to_open);
	free(preprocess_info);
	preprocess_info = NULL;

	assert(preprocess_file("./input/bad_input1.bf") == NULL);
	assert(preprocess_file("./input/bad_input2.bf") == NULL);
	printf("[TEST] all preprocess tests passed!\n");
	return 0;
}
