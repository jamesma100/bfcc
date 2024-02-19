#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <stdbool.h>

typedef struct {
  int linenum;
  int pos;
} BracketInfo;


bool cmp_bracket_info(BracketInfo *me, BracketInfo *you);
int preprocess_file(char* input_file);
int preprocess(FILE* fp);

#endif
