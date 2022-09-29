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
  std::cout << "::jjxmalloc() with " << (1000 * sizeof(int)) << " bytes"
            << std::endl;
  int* bytes = (int*)::jjxmalloc(1000 * sizeof(int));
  ::free(bytes);
  bytes = (int*)::jjxmalloc(100 * sizeof(int));
  ::free(bytes);

  return EXIT_SUCCESS;
}