.PHONY: all src test
FLAGS = -Wall -Werror -pedantic

SRC = stack instructions preprocess
TEST = stack-test instructions-test preprocess-test

src: ${SRC}
test: ${TEST}
all: ${SRC} ${TEST}

stack: src/stack.c src/stack.h
	gcc -c src/stack.c -o bin/stack.o ${FLAGS}

stack-test: src/stack.c src/stack.h src/preprocess.h test/stack_test.c
	gcc test/stack_test.c src/stack.c src/preprocess.c -o bin/stack_test ${FLAGS}

instructions: src/instructions.c src/instructions.h
	gcc -c src/instructions.c -o bin/instructions.o ${FLAGS}

instructions-test: src/instructions.c src/instructions.h test/instructions_test.c
	gcc test/instructions_test.c src/instructions.c -o bin/instructions_test ${FLAGS}

preprocess: src/stack.c src/stack.h src/preprocess.c src/preprocess.h
	gcc -c src/preprocess.c -o bin/preprocess ${FLAGS}

preprocess-test: src/stack.c src/stack.h src/preprocess.c src/preprocess.h test/preprocess_test.c
	gcc src/stack.c src/preprocess.c test/preprocess_test.c -o bin/preprocess_test ${FLAGS}
