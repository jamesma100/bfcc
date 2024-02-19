#include <stdio.h>
#include "../src/hashmap.h"

void print_bi(BracketInfo *bi) {
	printf("[DEBUG]: linenum: %d, pos: %d\n", bi->linenum, bi->pos);
}

int main(void) {
	printf("hello world\n");
	// printf("%d\n", hash(&bi, 5));

	int num_rows = 10;
	int num_cols = 10;
	BracketInfo **open_to_close = (BracketInfo**) malloc(sizeof(BracketInfo*) * num_rows);
	for (int i = 0; i < num_rows; ++i) {
		open_to_close[i] = (BracketInfo*)malloc(sizeof(BracketInfo) * num_cols);
	}
	BracketInfo **close_to_open = (BracketInfo**) malloc(sizeof(BracketInfo*) * num_rows);
	for (int i = 0; i < num_rows; ++i) {
		close_to_open[i] = (BracketInfo*)malloc(sizeof(BracketInfo) * num_cols);
	}
	BracketInfo close = {0, 2};
	BracketInfo open = {9, 4};

	close_to_open[close.linenum][close.pos] = open;
	open_to_close[open.linenum][open.pos] = close;
	print_bi(&close_to_open[0][2]); // 9, 4
	print_bi(&open_to_close[9][4]); // 0, 1
	return 0;
}
