#ifndef ASAP_DURATION_H
#define ASAP_DURATION_H

#include <string>
#include <cmath>
#include "constants.h"

namespace asap {
  namespace detail {
    inline static uint64_t append(std::string & str, uint64_t seconds, uint64_t count, const std::string & singular,
           const std::string & plural = "") {
      long r = static_cast<unsigned>(seconds) / count;
      if (!r) return seconds;
      if (!str.empty()) str += ", ";
      str += std::to_string(r) + " ";
      if (r < 2) str += singular;
      else str += plural.empty() ? singular + 's' : plural;
      return static_cast<unsigned>(seconds) % count;
    }
  }

  class duration {
    public:
      explicit duration(uint64_t seconds);
      duration & operator+=(const duration & other);
      duration & operator-=(const duration & other);
      duration & operator+=(long other);
      duration & operator-=(long other);

      std::string str() const;

      float years() const { return transform(SECONDS_IN_YEAR); }
      float months() const { return transform(SECONDS_IN_MONTH); }
      float weeks() const { return transform(SECONDS_IN_WEEK); }
      float days() const { return transform(SECONDS_IN_DAY); }
      float hours() const { return transform(SECONDS_IN_HOUR); }
      float minutes() const { return transform(SECONDS_IN_MINUTE); }
      uint64_t seconds() const { return seconds_; }
      uint64_t milliseconds() const { return seconds_ * 1000; }

    private:
      uint64_t seconds_;
      float transform(uint64_t count) const {
        return static_cast<float>(seconds_) / count;
      }
  };

  inline duration::duration(uint64_t seconds)
      : seconds_(seconds) { }


  inline duration & duration::operator+=(const duration & other) {
    return operator+=(other.seconds());
  }

  inline duration & duration::operator-=(const duration & other) {
    return operator-=(other.seconds());
  }

  inline duration & duration::operator+=(long other) {
    seconds_ += other;
    return *this;
  }

  inline duration & duration::operator-=(long other) {
    if (other > seconds_) seconds_ = 0;
    else seconds_ -= other;
    return *this;
  }

  std::string duration::str() const {
    uint64_t seconds = seconds_;
    std::string str;
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
}

#endif //ASAP_DURATION_H
