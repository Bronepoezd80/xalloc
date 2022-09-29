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
  free(bytes);
  bytes = (int*)jjxmalloc(100 * sizeof(int));
  free(bytes);

  return EXIT_SUCCESS;
}