#include <iostream>
#include "asap.h"

/* You have to opt-in to use literals by using its namespace */
using namespace asap::literals;

int main(int argc, char * argv[]) {
  /* Setting locale helps with local time format. It is not required. */
  setlocale(LC_ALL, "");

  std::cout << "next day                    \t->   " << asap::now() + 1_day << std::endl;
  std::cout << "1_day + 1_hour              \t->   " << 1_day + 1_hour << std::endl;
  std::cout << "1_day - (1_hour + 1_minute) \t->   " << 1_day - (1_hour + 1_minute) << std::endl;

  return 0;
}
