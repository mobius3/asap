#include "datetime.h"
#include <iostream>
#include <limits>
#include "types.h"

int main(int argc, char * argv[]) {
  asap::datetime x(2017, 0, 1);
  asap::duration d = asap::days(10);
  std::cout << x << std::endl;
  std::cout << asap::days(395) + asap::minute(1) << std::endl;
  return 0;
}
