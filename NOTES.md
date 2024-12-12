# CFlowLang Notes

## Compiling Shared Object Files
Use flags for position independent code (PIC) and shared object.
```bash
cc -fPIC -shared -o file.so file.c 
```
This creates a shared object file which can be opened with `dlfcn` C library.
```c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
  void *handle = dlopen("/opt/wfl/nctsiridis/libworker_a.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "Error: %s\n", dlerror());
  }
  dlerror();
  // hello_a is a function defined in libworker_a.so 
  void (*hello)() = dlsym(handle, "hello_a");
  char *error = dlerror();
  if (error != NULL) {
    fprintf(stderr, "Error: %s\n", dlerror());
    dlclose(handle);
    exit(EXIT_FAILURE);
  }
  
  hello();

  dlclose(handle);

  return 0;
}
```
