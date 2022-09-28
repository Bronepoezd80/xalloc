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
  std::cout << "::jjxmalloc() allocated " << ::jjxallocated_size(bytes)
            << " bytes" << std::endl;
  ::jjxfree(bytes);
  std::cout << "::jjxmalloc() allocated " << ::jjxallocated_size(bytes)
            << " bytes" << std::endl;
  bytes = (int*)::jjxmalloc(100 * sizeof(int));
  std::cout << "::jjxmalloc() allocated " << ::jjxallocated_size(bytes)
            << " bytes" << std::endl;
  ::jjxfree(bytes);
  std::cout << "::jjxmalloc() allocated " << ::jjxallocated_size(bytes)
            << " bytes" << std::endl;

  int* zero = NULL;
  std::cout << "::jjxmalloc() allocated " << ::jjxallocated_size(bytes)
            << " bytes" << std::endl;

  return EXIT_SUCCESS;
}