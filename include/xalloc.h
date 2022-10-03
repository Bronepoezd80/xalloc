/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-03
 */
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

#ifdef __cplusplus
}
#endif

#endif /* JJXALLOC_H__ */