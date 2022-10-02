#ifndef JJXALLOC_H__
#define JJXALLOC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#define xmalloc(SIZE_) \
  malloc_or_exit((size_t)(SIZE_), (char*)__FILE__, (size_t)__LINE__)

#define xrealloc(PTR_, SIZE_) \
  realloc_or_exit(PTR_, (size_t)(SIZE_), (char*)__FILE__, (size_t)__LINE__)

#define xcalloc(PTR_, SIZE_)                                         \
  calloc_or_exit((size_t)(ELEMS_), (size_t)(SIZE_), (char*)__FILE__, \
                 (size_t)__LINE__)

static void xalloc_die(const char* func_, const char* file_, size_t line_,
                       size_t size_) {
  fprintf(stderr, "%s: line %zu: %s of %zu bytes failed!\n", file_, line_,
          func_, size_);
  abort();
}

void* malloc_or_exit(size_t size_, const char* file_, size_t line_) {
  void* alloc = NULL;
  alloc = malloc(size_);
  if (size_ == 0 || alloc == NULL) {
    xalloc_die("malloc()", file_, line_, size_);
  }
  return alloc;
}

void* calloc_or_exit(size_t elems_, size_t size_, const char* file_,
                     size_t line_) {
  void* alloc = NULL;
  if (elems_ == 0 || size_ == 0) {
    xalloc_die("calloc()", file_, line_, elems_ * size_);
  }
  alloc = calloc(elems_, size_);
  if (alloc == NULL) {
    xalloc_die("calloc()", file_, line_, elems_ * size_);
  }
  return alloc;
}

void* realloc_or_exit(void* ptr_, size_t size_, const char* file_,
                      size_t line_) {
  void* alloc = NULL;
  if (ptr_ == NULL) {
    return malloc_or_exit(size_, file_, line_);
  }
  alloc = realloc(ptr_, size_);
  if (size_ == 0 || alloc == NULL) {
    xalloc_die("realloc()", file_, line_, size_);
  }
  return alloc;
}

#ifdef __cplusplus
}
#endif

#endif /* JJXALLOC_H__ */