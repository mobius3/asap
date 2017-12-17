#include "duration.h"
#include "datetime.h"
#include "operators.h"
#include "period.h"

#include <iostream>

int main(int argc, char * argv[]) {


  asap::datetime x;
  asap::datetime y = x + asap::years(1.5) + asap::months(2);

  asap::period period(x, y);

  for (asap::datetime dt : period.every(asap::month(1))) {
    std::cout << "got: " << dt << std::endl;
  }

  return 0;
}
