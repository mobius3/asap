#ifndef ASAP_DURATION_H
#define ASAP_DURATION_H

#include <string>
#include <type_traits>
#include <cmath>
#include "constants.h"

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

  template<uint64_t convert = 1>
    class duration {
      public:
        explicit duration(double v = 0) : value(v) { }
        explicit operator double() const { return value; }
        duration<convert> & operator=(int v) { value = v; return *this; }
        double operator*() const { return value; };
        duration<convert> operator-() { return duration<convert>(-value); }

        template<uint64_t other>
        explicit operator duration<other>() const {
            double asseconds = value * convert;
            return duration<other>(asseconds / other);
        }

        template<uint64_t convert2>
        duration<convert> & operator+=(const duration<convert2> & other) {
            value = ((value * convert) + (*other * convert2)) / convert;
            return *this;
        }

        duration<convert> & operator+=(const duration<convert> & other) {
          value = (value + *other);
          return *this;
        }

        template<uint64_t convert2>
        duration<convert> & operator-=(const duration<convert2> & other) {
            value = ((value * convert) - (*other * convert2)) / convert;
            return *this;
        }

        template<uint64_t convert2>
        duration<convert> & operator=(const duration<convert2> & other) {
            value = (*other * convert2) / convert;
            return *this;
        }

        std::string str() const {
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
