#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
  printf("Hello World!\n");
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
