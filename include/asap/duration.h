#ifndef ASAP_DURATION_H
#define ASAP_DURATION_H

#include <string>
#include <type_traits>
#include <cmath>
#include "constants.h"

namespace asap {
   template<uint64_t convert = 1>
    class duration {
      public:
        explicit duration(double v = 0);
        explicit operator double() const;
        duration<convert> & operator=(int v);
        double operator*() const;;
        duration<convert> operator-();
        template<uint64_t other> explicit operator duration<other>() const;
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
