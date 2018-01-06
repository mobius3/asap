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
  template <uint64_t convert> inline duration<convert> & duration<convert>::operator=(int v) { value = v; return *this; }
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
