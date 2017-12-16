#include "datetime.h"
#include <iostream>
#include <limits>
#include <period.h>
#include "types.h"

int main(int argc, char * argv[]) {
  asap::datetime x(2017, 0, 1);
  asap::datetime y(2017, 2, 1);

  asap::period range(x, y);

  for (asap::datetime dt : range.each(asap::month(1))) {
    std::cout << "got: " << dt << std::endl;
  }

  return 0;
}
