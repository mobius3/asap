#include <iostream>
#include "asap.h"

/* You have to opt-in to use literals by using its namespace */
using namespace asap::literals;

int main(int argc, char * argv[]) {
  /* Setting locale helps with local time format. It is not required. */
  setlocale(LC_ALL, "");

  /* Literals are shorthands for durations:
   * 1_second == asap::seconds(1),
   * 1_minute == asap::minutes(1),
   * 1_hour == asap::hours(1),
   * 1_day == asap::days(1),
   * 1_week == asap::weeks(1),
   * 1_month == asap::months(1),
   * 1_year == asap::years(1) != asap::months(12);
   *
   * these literals can be used to do time arithmetics.
   */
  std::cout << "next day                    \t->   " << asap::now() + 1_day << std::endl;
  std::cout << "1_day + 1_hour              \t->   " << 1_day + 1_hour << std::endl;
  std::cout << "1_day - (1_hour + 1_minute) \t->   " << 1_day - (1_hour + 1_minute) << std::endl;

  return 0;
}
