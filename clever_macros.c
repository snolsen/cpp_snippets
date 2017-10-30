/*
* Error-checking by return value: if C++ exceptions can't be used, this macro avoids
* endless repetition of "int retval = someFunc(); if (retval != SUCCESS) ..."
*/
#define CHECK(x) do { \
  int retval = (x); \
  if (retval != 0) { \
    fprintf(stderr, "Runtime error: %s returned %d at %s:%d", #x, retval, __FILE__, __LINE__); \
    return /* or throw or whatever */; \
  } \
} while (0)