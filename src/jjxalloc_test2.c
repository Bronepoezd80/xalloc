/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-09-27
 */
#include <stdio.h>
#include <stdlib.h>

#include <jjxalloc.h>

int
main(void)
{
  printf("jjxmalloc() with %zu bytes\n", 1000 * sizeof(int));
  int* bytes = (int*)jjxmalloc(1000 * sizeof(int));
  printf("jjxmalloc() allocated %zu bytes\n", jjxallocated_size(bytes));
  jjxfree(bytes);
  printf("jjxmalloc() allocated %zu bytes\n", jjxallocated_size(bytes));
  bytes = (int*)jjxmalloc(100 * sizeof(int));
  printf("jjxmalloc() allocated %zu bytes\n", jjxallocated_size(bytes));
  jjxfree(bytes);
  printf("jjxmalloc() allocated %zu bytes\n", jjxallocated_size(bytes));

  int* zero = NULL;
  printf("jjxmalloc() allocated %zu bytes\n", jjxallocated_size(zero));

  return EXIT_SUCCESS;
}