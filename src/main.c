#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

enum Cmd {
  SHARED_OBJECT,
  FUNCTION,
  ENTRYPOINT,
  FLOW
};
const char* CmdStringMap[] = {
  "so",
  "fn",
  "end",
  "flow"
};

struct FileData {
  char* content;
  size_t pos;
  size_t size;
};

char *next_token(struct FileData* fd) {
  //chop white space and newlines
  while (content[pos] != " \n";
  return "NOT IMPLEMENTED";
}

struct FileData *read_file_data(char *path) {
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    perror("Could not read file\n");
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  char* buffer = (char*)malloc(file_size + 1);
  if (buffer == NULL) {
    perror("Error allocating file buffer\n");
    fclose(file);
    return NULL;
  }

  size_t bytes_read = fread(buffer, 1, file_size, file);
  buffer[bytes_read] = '\0';

  fclose(file);
  struct FileData *fd = (struct FileData*)malloc(sizeof(struct FileData));
  if (fd == NULL) {
    perror("Error allocating FileData struct\n");
    return NULL;
  }

  fd->content = buffer;
  fd->pos = 0;
  fd->size = bytes_read;

  return fd;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s file.fl\n", argv[0]);
    return 1;
  }

  struct FileData *file_data = read_file_data(argv[1]);
  if (file_data == NULL) {
    printf("Failed to read file data\n");
    return 1;
  }

  printf("File Data: %s", file_data->content);

  return 0;
}

// map string -> function ? 
// Tokenize -> Preprocess -> Run
/*
How the interpeter might work:
  every time a function writes something to a channel, this information will be hashed
  that hashed value will reveal the next functions and how they take input from that output
  if specified by the call, create a new thread, otherwise execute in order 

  IMPORTANT
  If a body of functions want to have acces to some global variables, this can be acheived by
  initiating a flow with the context of those variables. These will be accesibly by all within
  the context of that flow. This way scoping can be achieved with flowlang
*/
