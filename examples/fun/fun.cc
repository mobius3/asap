#include "datetime.h"
#include <iostream>
#include <limits>

int main(int argc, char * argv[]) {
  asap::datetime x;
  asap::duration d(360);
  std::cout << x + 1234 << std::endl;
  std::cout << d << std::endl;
  return 0;
}
