#include "datetime.h"
#include <iostream>

int main(int argc, char * argv[]) {
  asap::datetime x(0);
  asap::duration d(123456789);
  std::cout << x << std::endl;
  std::cout << d << std::endl;
  return 0;
}
