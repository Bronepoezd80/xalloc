/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-09-27
 */
#include <cstdio>
#include <cstdlib>

#include <iostream>

#include <jjxalloc.h>

int
main(void)
{
  while (1) {
    std::cout << "::jjxmalloc() with " << 1000000000 << " bytes" << std::endl;
    int* bytes = (int*)::jjxmalloc(1000000000);
  }

  return EXIT_SUCCESS;
}