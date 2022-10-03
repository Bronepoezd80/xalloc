/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-03
 */
#include <cstdio>
#include <cstdlib>

#include <iostream>

#include <xalloc.h>

int main(void) {
  while (1) {
    std::cout << "::xmalloc() with " << 1000000000 << " bytes" << std::endl;
    int *bytes = (int *)::xmalloc(1000000000);
  }

  return EXIT_SUCCESS;
}