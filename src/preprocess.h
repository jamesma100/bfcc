typedef struct {
  int linenum;
  int pos;
  char type;
} BracketInfo;


int preprocess_file(char* input_file);
int preprocess(FILE* fp);
