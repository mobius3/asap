#include "datetime.h"
#include <iostream>
#include <limits>
#include "types.h"

int main(int argc, char * argv[]) {
  asap::datetime x;
  asap::duration d(360);
  std::cout << x + asap::days(10) << std::endl;
  std::cout << d << std::endl;
  return 0;
}
