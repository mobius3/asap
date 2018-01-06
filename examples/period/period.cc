#include <iostream>
#include "asap.h"

int main(int argc, char * argv[]) {
  /* Setting locale helps with local time format. It is not required. */
  setlocale(LC_ALL, "");

  /* Creates a period, from now until tomorrow. */
  auto period = asap::now().until(asap::tomorrow());

  /* Iterates from now until tomorrow, by every hour, using oldschool iterators.
   * Be aware that tomorrow happens to be next day *exactly* at midnight, which means
   * unless asap::now() is exactly at 0 minutes and 0 seconds, the next day will
   * never be printed. */
  auto everyhour = period.every(asap::hours(1));
  std::cout << "every hour until tomorrow:" << std::endl;
  for (auto i = everyhour.begin(); i != everyhour.end(); i++) {
    std::cout << "* " << *i << std::endl;
  }
  std::cout << std::endl;

  /* you can also use the newschool for :) */
  std::cout << "every 3 hours until tomorrow:" << std::endl;
  for (auto d: period.every(asap::hour(3))) {
    std::cout << "* " << d << std::endl;
  }

  return 0;
}
