/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-09-27
 */
#include <stdio.h>
#include <stdlib.h>

#include <xalloc.h>

int main(void) {
  while (1) {
    printf("xmalloc() with %d bytes\n", 1000000000);
    int *bytes = (int *)xmalloc(1000000000);
  }

  return EXIT_SUCCESS;
}