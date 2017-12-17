#include "duration.h"
#include "datetime.h"
#include "operators.h"
#include "period.h"

#include <iostream>

int main(int argc, char * argv[]) {
  asap::datetime x, y = x + asap::months(4);
  for (auto dt : asap::period(x, y).every(asap::weeks(1))) {
    std::cout << dt << std::endl;
  }
  return 0;
}
