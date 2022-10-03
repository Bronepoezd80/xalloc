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
  std::cout << "::xmalloc() with 0 bytes" << std::endl;
  int *bytes = nullptr;
  bytes = (int *)::xmalloc(0);

  return EXIT_SUCCESS;
}