#ifndef JJXALLOC_H__
#define JJXALLOC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>

  void* jjmalloc_or_exit(size_t size_, const char* file_, size_t line_)
  {
    void* alloc = NULL;
    alloc = malloc(size_);
    if (size_ == 0 || alloc == NULL) {
      fprintf(stderr,
              "%s: line %zu: malloc() of %zu bytes failed\n",
              file_,
              line_,
              size_);
      exit(EXIT_FAILURE);
    }
    return alloc;
  }

#define jjxmalloc(NBYTES_)                                                     \
  jjmalloc_or_exit((size_t)(NBYTES_), (char*)__FILE__, (size_t)__LINE__)

#ifdef __cplusplus
}
#endif

#endif /* JJXALLOC_H__ */