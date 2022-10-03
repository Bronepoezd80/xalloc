/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-03
 */
#include <xalloc.h>

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
    xalloc_die("realloc()", file_, line_, size_);
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