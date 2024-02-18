#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "preprocess.h"

uint32_t hash(BracketInfo *bi, size_t buf_sz) {
	uint32_t val = 0;
	val += (uint32_t)bi->linenum;
	val += (uint32_t)bi->pos;
	val += (uint32_t)(bi->type - 'a');
	return val % buf_sz;
}
