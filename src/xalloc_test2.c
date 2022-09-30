/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-09-27
 */
#include <stdio.h>
#include <stdlib.h>

#include <xalloc.h>

int main(void) {
  printf("xmalloc() with %zu bytes\n", 1000 * sizeof(int));
  int *bytes = (int *)xmalloc(1000 * sizeof(int));
  free(bytes);
  bytes = (int *)xmalloc(100 * sizeof(int));
  free(bytes);

  return EXIT_SUCCESS;
}