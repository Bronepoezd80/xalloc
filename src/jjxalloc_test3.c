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
  while (1) {
    printf("jjxmalloc() with %d bytes\n", 1000000000);
    int* bytes = (int*)jjxmalloc(1000000000);
    printf("jjxmalloc() allocated %zu bytes\n", jjxallocated_size(bytes));
  }

  return EXIT_SUCCESS;
}