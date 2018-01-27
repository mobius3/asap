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

#ifndef ASAP_DURATION_H
#define ASAP_DURATION_H

#include "constants.h"

namespace asap {
   template<uint64_t convert = 1>
    class duration {
      public:
        explicit duration(double v = 0);
        template<uint64_t convertfrom> duration(const asap::duration<convertfrom> & other);
        explicit operator double() const;
        duration<convert> & operator=(double v);
        double operator*() const;
        duration<convert> operator-();
        template<uint64_t other> operator duration<other>() const;
        template<uint64_t convert2> duration<convert> & operator+=(const duration<convert2> & other);
        duration<convert> & operator+=(const duration<convert> & other);
        template<uint64_t convert2> duration<convert> & operator-=(const duration<convert2> & other);
        template<uint64_t convert2> duration<convert> & operator=(const duration<convert2> & other);
        std::string str() const;

      private:
        double value;
    };

  using seconds = duration<1>; using second = seconds;
  using minutes = duration<SECONDS_IN_MINUTE>; using minute = minutes;
  using hours = duration<SECONDS_IN_HOUR>; using hour = hours;
  using days = duration<SECONDS_IN_DAY>; using day = days;
  using weeks = duration<SECONDS_IN_WEEK>; using week = weeks;
  using months = duration<SECONDS_IN_MONTH>; using month = months;
  using years = duration<SECONDS_IN_YEAR>; using year = years;
}

#endif
