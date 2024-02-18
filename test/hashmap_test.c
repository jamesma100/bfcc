#include <stdio.h>
#include "../src/hashmap.h"

int main(void) {
	printf("hello world\n");
	BracketInfo bi = {0, 2, 'h'};
	printf("%d\n", hash(&bi, 5));

	return 0;
}
