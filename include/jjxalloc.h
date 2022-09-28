#ifndef JJXALLOC_H__
#define JJXALLOC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>

  void* jjmalloc_or_exit(size_t nbytes_, const char* file_, size_t line_)
  {
    void* x = NULL;
    if (nbytes_ == 0 || (x = malloc(nbytes_)) == NULL) {
      fprintf(stderr,
              "%s: line %lu: malloc() of %zu bytes failed\n",
              file_,
              line_,
              nbytes_);
      exit(EXIT_FAILURE);
    }
    return x;
  }

  void jjfree_or_exit(void* ptr_, const char* file_, size_t line_)
  {
    if (ptr_ == NULL) {
      fprintf(
        stderr, "%s: line %lu: no memory to free with free()\n", file_, line_);
      exit(EXIT_FAILURE);
    }
    free(ptr_);
    ptr_ = NULL;
    return;
  }

#define jjxmalloc(NBYTES_)                                                     \
  jjmalloc_or_exit((size_t)(NBYTES_), (char*)__FILE__, (size_t)__LINE__)

#define jjxfree(PTR_) jjfree_or_exit((PTR_), (char*)__FILE__, (size_t)__LINE__)

#ifdef __cplusplus
}
#endif

#endif /* JJXALLOC_H__ */