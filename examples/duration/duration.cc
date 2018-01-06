/* * Copyright (C) 2018 Leonardo Guilherme Lucena de Freitas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

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

  std::cout << "ten_years            ->   " << ten_years << std::endl;
  std::cout << "one_year_and_quarter ->   " << one_year_and_quarter << std::endl;
  std::cout << "ten_years_from_now   ->   " << ten_years_from_now << std::endl;
  std::cout << "another_ten_years    ->   " << another_ten_years << std::endl;

  /* be aware that for printing and arithmethics, a month has 30 days, thus half an year
   * is actually 6 months, 2 days and 12 hours. asap::years(0.5) != asap::months(6) */
  std::cout << "half_year            ->   " << half_year << std::endl;

  std::cout << "now          ->  " << asap::now() << std::endl;
  std::cout << "now + 1 day  ->  " << asap::now() + asap::days(1) << std::endl;

  return 0;
}
