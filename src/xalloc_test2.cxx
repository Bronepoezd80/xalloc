/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-09-27
 */
#include <cstdio>
#include <cstdlib>

#include <iostream>

#include <xalloc.h>

int
main(void)
{
  std::cout << "::xmalloc() with " << (1000 * sizeof(int)) << " bytes"
            << std::endl;
  int* bytes = (int*)::xmalloc(1000 * sizeof(int));
  ::free(bytes);
  bytes = (int*)::xmalloc(100 * sizeof(int));
  ::free(bytes);

  return EXIT_SUCCESS;
}