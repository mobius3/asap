#include <iostream>
#include "asap.h"

int main(int argc, char * argv[]) {
  /* Setting locale helps with local time format. It is not required. */
  setlocale(LC_ALL, "");

  auto p = asap::now().until(asap::now() + asap::days(10));

  for (auto d: p.every(asap::days(1))) {
    std::cout << d << std::endl;
  }

  return 0;
}
