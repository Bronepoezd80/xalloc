#ifndef JJXALLOC_H__
#define JJXALLOC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>

#define xmalloc(SIZE_)                                                         \
  malloc_or_exit((size_t)(SIZE_), (char*)__FILE__, (size_t)__LINE__)

#define xrealloc(POINTER_, SIZE_)                                              \
  realloc_or_exit(POINTER_, (size_t)(SIZE_), (char*)__FILE__, (size_t)__LINE__)

#define xcalloc(POINTER_, SIZE_)                                               \
  calloc_or_exit(                                                              \
    (size_t)(ELEMENTS_), (size_t)(SIZE_), (char*)__FILE__, (size_t)__LINE__)

  // static void

  void* malloc_or_exit(size_t size_, const char* file_, size_t line_)
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

  void* calloc_or_exit(size_t elements_,
                       size_t size_,
                       const char* file_,
                       size_t line_)
  {
    void* alloc = NULL;
    if (elements_ == 0 || size_ == 0) {
      fprintf(stderr,
              "%s: line %zu: calloc() of %zu bytes failed\n",
              file_,
              line_,
              size_);
      exit(EXIT_FAILURE);
    }
    alloc = calloc(elements_, size_);
    if (alloc == NULL) {
      fprintf(stderr,
              "%s: line %zu: realloc() of %zu bytes failed\n",
              file_,
              line_,
              size_);
      exit(EXIT_FAILURE);
    }
    return alloc;
  }

  void* realloc_or_exit(void* pointer_,
                        size_t size_,
                        const char* file_,
                        size_t line_)
  {
    void* alloc = NULL;
    if (pointer_ == NULL) {
      return malloc_or_exit(size_, file_, line_);
    }
    alloc = realloc(pointer_, size_);
    if (size_ == 0 || alloc == NULL) {
      fprintf(stderr,
              "%s: line %zu: realloc() of %zu bytes failed\n",
              file_,
              line_,
              size_);
      exit(EXIT_FAILURE);
    }
    return alloc;
  }

#ifdef __cplusplus
}
#endif

#endif /* JJXALLOC_H__ */