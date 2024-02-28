#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "preprocess.h"
#include "instructions.h"

/**
 * Allocates initial memory
 */
void init_memory(Memory *mem, size_t initial_size) {
  mem->data = (int*)malloc(initial_size * sizeof(int));
  mem->head = mem->data;
  mem->ptr = mem->data;
  mem->initial_size = initial_size;
  // TODO: lazy initialization
  for (int i = 0; i < initial_size; ++i) {
  	mem->data[i] = 0;
  }
}

/**
 * Free memory
 */
void free_memory(Memory *mem) {
	free(mem->data);
	mem->data = NULL;
	mem->head = NULL;
	mem->ptr = NULL;
}

/**
 * Inititialize instructions
 */
void init_instructions(Instructions *instructions, int num_rows, int num_cols) {
	instructions->num_rows = num_rows;
	instructions->num_cols = num_cols;
  char **data = (char**) malloc(sizeof(char*) * num_rows);
  for (int i = 0; i < num_rows; ++i) {
    data[i] = (char*)malloc(sizeof(char) * num_cols);
  }
  instructions->data = data;
  instructions->linenum = 0;
  instructions->pos = 0;
  // TODO: lazy initialization
  for (int i = 0; i < num_rows; ++i) {
  	for (int j = 0; j < num_cols; ++j) {
  		instructions->data[i][j] = '\0';
  	}
  }
}

/**
 * Free memory allocated for instructions
 */
void free_instructions(Instructions *instructions) {
	for (int i = 0; i < instructions->num_rows; ++i) {
		free(instructions->data[i]);
		instructions->data[i] = NULL;
	}
	free(instructions->data);
	instructions->data = NULL;
	instructions->num_rows = 0;
	instructions->num_cols = 0;
	instructions->linenum = 0;
	instructions->pos = 0;
}

/**
 * Displays first n elements
 */
void display_first_n(Memory *mem, int n) {
	if (n >= mem->initial_size) {
		fprintf(stderr, "[ERROR]: not enough elements to display\n");
		exit(1);
	}
	printf("[DEBUG]: displaying first ten elements:\n");
	for (int i = 0; i < n; ++i) {
		printf("%c ", *(mem->data + i));
	}
	printf("\n");

}

/**
 * Moves instruction pointer right by one
 */
void right(Memory *mem) {
	mem->ptr++;
}

/**
 * Moves instruction pointer left by one
 */
void left(Memory *mem) {
	mem->ptr--;
}

/**
 * Increments data currently pointed to by instruction pointer
 */
void inc(Memory *mem) {
	(*mem->ptr)++;
}

/**
 * Decrements data currently pointed to by instruction pointer
 */
void dec(Memory *mem) {
	(*mem->ptr)--;
}

/**
 * Outputs data currently pointed to by instruction pointer
 */
char out(Memory *mem) {
	printf("%c\n", *mem->ptr);
	return *mem->ptr;
}

/**
 * Reads from stdin and sets instruction pointer to point to read data
 */
void in(Memory *mem) {
	char c;
	scanf(" %c", &c);
	*mem->ptr = c;
}
