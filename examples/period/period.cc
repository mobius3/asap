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
