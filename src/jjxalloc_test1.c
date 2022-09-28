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
  printf("jjxmalloc() with 0 bytes\n");
  int* bytes = NULL;
  bytes = (int*)jjxmalloc(0);

  return EXIT_SUCCESS;
}