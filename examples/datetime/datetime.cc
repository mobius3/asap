#include <iostream>
#include "asap.h"

int main(int argc, char * argv[]) {
  /* Setting locale helps with local time format. It is not required. */
  setlocale(LC_ALL, "");

  /* If no arguments passed, its the same as asap::now() */
  asap::datetime d1;

  /* You can pass a string as a date or time. It tries its best to detect the format,
   * it defaults to asap::datetime(0). */
  asap::datetime d2("08/07/1987");

  /* You can also pass a format specifier. They're the same used by strftime */
  asap::datetime d3("08/07/1987 23:45:12");

  /* A broken down time may be specified, in the order: year, month, day of month, hour, minute, second.
   * Be aware that months start at 0 for January (as most date/time APIs) */
  asap::datetime d4(1987, 6, 8);

  /* Default printing format is day-month-year hour:minute:second */
  std::cout << "d1: " << d1 << std::endl;

  /* You can also pass a format to str(). Consult strftime manual for the available formats. */
  std::cout << "d2: " << d2.str("%c") << std::endl;
  std::cout << "d3: " << d3.str("date: %d/%m/%Y time: %H:%M") << std::endl;
  std::cout << "d4: " << d4.str("%FT%T%z") << std::endl;
  std::cout << "now: " << asap::now() << std::endl;
  std::cout << "tomorrow: " << asap::tomorrow() << std::endl;
  std::cout << "yesterday: " << asap::yesterday() << std::endl;

  return 0;
}
