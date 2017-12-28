#include <iostream>
#include "asap.h"

int main(int argc, char * argv[]) {
  /* Setting locale helps with local time format. It is not required. */
  setlocale(LC_ALL, "");

  /* duration types represent durations in various granularities, from seconds to days. */
  auto ten_years = asap::years(10);

  /* you can specify a fraction of a duration: */
  auto half_year = asap::years(0.5f);

  /* you can sum and subtract durations. be aware that the right operand will be converted to the first operand
   * granularity (i.e, when adding years + days, days will be converted to a fraction of a year) */
  auto one_year_and_quarter = asap::years(1) + asap::months(3);

  /* you can add or subtract a duration from a datetime */
  auto ten_years_from_now = asap::now() + ten_years;

  /* subtracting two datetimes yields a duration, in seconds */
  auto another_ten_years = ten_years_from_now - asap::now();

  std::cout << "ten_years = " << ten_years << std::endl;
  std::cout << "one_year_and_quarter = " << one_year_and_quarter << std::endl;
  std::cout << "ten_years_from_now = " << ten_years_from_now << std::endl;
  std::cout << "another_ten_years = " << another_ten_years << std::endl;

  /* be aware that for printing and arithmethics, a month has 30 days, thus half an year
   * is actually 6 months, 2 days and 12 hours. asap::years(0.5) != asap::months(6) */
  std::cout << "half_year = " << half_year << std::endl;
}
