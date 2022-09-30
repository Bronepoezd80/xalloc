/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-09-27
 */
#include <stdio.h>
#include <stdlib.h>

#include <xalloc.h>

int
main(void)
{
  printf("xmalloc() with 0 bytes\n");
  int* bytes = NULL;
  bytes = (int*)xmalloc(0);

  return EXIT_SUCCESS;
}