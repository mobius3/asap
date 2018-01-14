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

#ifndef ASAP_DURATION_TCC
#define ASAP_DURATION_TCC

#include "duration.h"

namespace asap {
  namespace detail {
    inline static int append(std::string & str, int seconds, int count, const std::string & singular,
                             const std::string & plural = "") {
      long r = static_cast<unsigned>(seconds) / count;
      if (!r) return seconds;
      if (!str.empty() && str[str.length() -1] != '-') str += ", ";
      str += std::to_string(r) + " ";
      if (r < 2) str += singular;
      else str += plural.empty() ? singular + 's' : plural;
      return static_cast<unsigned>(seconds) % count;
    }
  }


  template <uint64_t convert> inline duration<convert>::duration(double v) : value(v) { }
  template <uint64_t convert> inline duration<convert>::operator double() const { return value; }
  template <uint64_t convert> inline duration<convert> & duration<convert>::operator=(double v) { value = v; return *this; }
  template <uint64_t convert> inline double duration<convert>::operator*() const { return value; }
  template <uint64_t convert> inline duration<convert> duration<convert>::operator-() { return duration<convert>(-value); }

  template <uint64_t convert> template <uint64_t other> inline duration<convert>::operator duration<other>() const {
    double asseconds = value * convert;
    return duration<other>(asseconds / other);
  }

  template <uint64_t convert> inline duration<convert> & duration<convert>::operator+=(const duration<convert> & other) {
    value = (value + *other);
    return *this;
  }

  template <uint64_t convert> template <uint64_t convert2> inline duration<convert> & duration<convert>::operator-=(const duration<convert2> & other) {
    value = ((value * convert) - (*other * convert2)) / convert;
    return *this;
  }

  template <uint64_t convert> template <uint64_t convert2> inline duration<convert> & duration<convert>::operator=(const duration<convert2> & other) {
    value = (*other * convert2) / convert;
    return *this;
  }

  template <uint64_t convert> inline std::string duration<convert>::str() const {
    auto seconds = static_cast<int>(std::fabs(value) * convert);
    std::string str;
    if (value < 0) str = "-";
    str.reserve(100);

    // TODO: l10n i18n?
    seconds = detail::append(str, seconds, SECONDS_IN_YEAR, "year");
    seconds = detail::append(str, seconds, SECONDS_IN_MONTH, "month");
    seconds = detail::append(str, seconds, SECONDS_IN_WEEK, "week");
    seconds = detail::append(str, seconds, SECONDS_IN_DAY, "day");
    seconds = detail::append(str, seconds, SECONDS_IN_HOUR, "hour");
    seconds = detail::append(str, seconds, SECONDS_IN_MINUTE, "minute");
    detail::append(str, seconds, 1, "second");

    return str;
  }

  template <uint64_t convert>
  template <uint64_t convertfrom>
  duration<convert>::duration(const asap::duration<convertfrom> & other)
    : value{(*other * convertfrom) / convert}
  { }

  template <uint64_t convert> template <uint64_t convert2> inline duration<convert> & duration<convert>::operator+=(const duration<convert2> & other) {
    value = ((value * convert) + (*other * convert2)) / convert;
    return *this;
  }
}

#endif //ASAP_DURATION_TCC
