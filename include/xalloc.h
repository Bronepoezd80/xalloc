#ifndef JJXALLOC_H__
#define JJXALLOC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#define ALLOC_MAXSIZE (((size_t)0) - 1)

#define xmalloc(SIZE_) \
  malloc_or_exit((size_t)(SIZE_), (char*)__FILE__, (size_t)__LINE__)

#define xrealloc(PTR_, SIZE_) \
  realloc_or_exit(PTR_, (size_t)(SIZE_), (char*)__FILE__, (size_t)__LINE__)

#define xcalloc(PTR_, SIZE_)                                         \
  calloc_or_exit((size_t)(ELEMS_), (size_t)(SIZE_), (char*)__FILE__, \
                 (size_t)__LINE__)

static void xalloc_die(const char*, const char*, size_t, size_t);
void* malloc_or_exit(size_t, const char*, size_t);
void* calloc_or_exit(size_t, size_t, const char*, size_t);
void* realloc_or_exit(void*, size_t, const char*, size_t);

static void xalloc_die(const char* msg_, const char* file_, size_t line_,
                       size_t size_) {
  fprintf(stderr, "%s: line %zu: %s of %zu bytes failed!\n", file_, line_, msg_,
          size_);
  abort();
}

void* malloc_or_exit(size_t size_, const char* file_, size_t line_) {
  if (size_ == 0) {
    xalloc_die("malloc()", file_, line_, size_);
  }
  void* alloc = NULL;
  alloc = malloc(size_);
  if (alloc == NULL) {
    xalloc_die("malloc()", file_, line_, size_);
  }
  return alloc;
}

void* calloc_or_exit(size_t nelems_, size_t size_, const char* file_,
                     size_t line_) {
  if (nelems_ == 0 || size_ == 0 || nelems_ * size_ == 0 ||
      ALLOC_MAXSIZE / nelems_ < size_) {
    xalloc_die("calloc()", file_, line_, nelems_ * size_);
  }
  void* alloc = NULL;
  alloc = calloc(nelems_, size_);
  if (alloc == NULL) {
    xalloc_die("calloc()", file_, line_, nelems_ * size_);
  }
  return alloc;
}

void* realloc_or_exit(void* ptr_, size_t size_, const char* file_,
                      size_t line_) {
  if (size_ == 0) {
    xalloc_die("malloc()", file_, line_, size_);
  }
  if (ptr_ == NULL) {
    return malloc_or_exit(size_, file_, line_);
  }
  void* new_alloc = NULL;
  new_alloc = realloc(ptr_, size_);
  if (new_alloc == NULL) {
    xalloc_die("realloc()", file_, line_, size_);
  }
  return new_alloc;
}

#ifdef __cplusplus
}
#endif

#endif /* JJXALLOC_H__ */