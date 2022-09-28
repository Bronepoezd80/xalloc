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
  std::cout << "::jjxmalloc() with 0 bytes" << std::endl;
  int* bytes = NULL;
  bytes = (int*)::jjxmalloc(0);

  return EXIT_SUCCESS;
}