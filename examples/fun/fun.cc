#include "datetime.h"
#include <iostream>
#include <limits>

int main(int argc, char * argv[]) {
  asap::datetime x;
  asap::duration d(std::numeric_limits<uint64_t>::max());
  std::cout << x << std::endl;
  std::cout << d << std::endl;
  return 0;
}
