#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <stdbool.h>

typedef struct {
  int linenum;
  int pos;
} BracketInfo;

typedef struct {
  BracketInfo **open_to_close;
  BracketInfo **close_to_open;
} PreprocessInfo;


bool cmp_bracket_info(BracketInfo *me, BracketInfo *you);
void free_bi_array(BracketInfo **bi);
PreprocessInfo* preprocess_file(char* input_file);
PreprocessInfo* preprocess(FILE* fp);

#endif
