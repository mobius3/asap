#include "datetime.h"
#include <iostream>
#include <limits>
#include "types.h"

int main(int argc, char * argv[]) {
  asap::datetime x(2017, 0, 1);
  asap::duration d(360);
  std::cout << x << std::endl;
  std::cout << d << std::endl;
  return 0;
}
