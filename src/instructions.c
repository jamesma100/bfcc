#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "preprocess.h"
#include "instructions.h"

/**
 * Allocates initial memory
 */
void init_memory(Memory *mem, size_t initial_size) {
  mem->data = (char*)malloc(initial_size * sizeof(char));
  mem->ip = mem->data;
}

/**
 * Moves instruction pointer right by one
 */
void right(Memory *mem) {
	mem->ip++;
}

/**
 * Moves instruction pointer left by one
 */
void left(Memory *mem) {
	mem->ip--;
}

/**
 * Increments data currently pointed to by instruction pointer
 */
void inc(Memory *mem) {
	(*mem->ip)++;
}

/**
 * Decrements data currently pointed to by instruction pointer
 */
void dec(Memory *mem) {
	(*mem->ip)--;
}

/**
 * Outputs data currently pointed to by instruction pointer
 */
char out(Memory *mem) {
	return *mem->ip;
}

/**
 * Reads from stdin and sets instruction pointer to point to read data
 */
void in(Memory *mem) {
	char c;
	scanf("%c", &c);
	*mem->ip = c;
}

/**
 * Jump to matching closing bracket if current data is zero
 */
void jmp_if_zero(Memory *mem, int offset) {
	if (*mem->ip == 0) {
		mem->ip += offset;
	}
}

/**
 * Jump to matching opening bracket if current data is nonzero
 */
void jmp_if_nonzero(Memory *mem, int offset) {
	if (*mem->ip != 0) {
		mem->ip -= offset;
	}
}
