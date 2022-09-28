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
    size_t* ptr = NULL;
    ptr = (size_t*)malloc(sizeof(size_t) + nbytes_);
    if (nbytes_ == 0 || ptr == NULL) {
      fprintf(stderr,
              "%s: line %zu: malloc() of %zu bytes failed\n",
              file_,
              line_,
              nbytes_);
      exit(EXIT_FAILURE);
    }
    *ptr = nbytes_;
    return &ptr[1];
  }

  void jjfree(void* ptr_)
  {
    free((size_t*)ptr_ - 1);
    ((size_t*)ptr_)[-1] = 0;
    ptr_ = NULL;
    return;
  }

  size_t jjallocated_size(void* ptr_)
  {
    if (ptr_ == NULL) {
      return 0;
    }
    return ((size_t*)ptr_)[-1];
  }

#define jjxmalloc(NBYTES_)                                                     \
  jjmalloc_or_exit((size_t)(NBYTES_), (char*)__FILE__, (size_t)__LINE__)

#define jjxfree(PTR_) jjfree((PTR_))

#define jjxallocated_size(PTR_) jjallocated_size((PTR_))

#ifdef __cplusplus
}
#endif

#endif /* JJXALLOC_H__ */