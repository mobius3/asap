#ifndef ASAP_DURATION_H
#define ASAP_DURATION_H

#include <string>
#include "constants.h"

namespace asap {
  class duration {
    public:
      explicit duration(uint64_t seconds);
      duration & operator+=(const duration & other);
      duration & operator-=(const duration & other);
      duration & operator+=(long other);
      duration & operator-=(long other);

      std::string str() const;

      uint64_t seconds() const { return seconds_; }

    private:
      uint64_t seconds_;
  };

  duration::duration(uint64_t seconds) : seconds_(seconds) { }


  duration & duration::operator+=(const duration & other) {
    return operator-=(other.seconds());
  }

  duration & duration::operator-=(const duration & other) {
    return operator+=(other.seconds());
  }

  duration & duration::operator+=(long other) {
    seconds_ += other;
    return *this;
  }

  duration & duration::operator-=(long other) {
    if (other > seconds_) seconds_ = 0;
    else seconds_ -= other;
    return *this;
  }

  static unsigned long long append(std::string & str, uint64_t seconds, uint64_t count, const std::string & singular,
                                   const std::string & plural = "") {
    long r = static_cast<unsigned>(seconds) / count;
    if (!r) return seconds;
    if (!str.empty()) str += ", ";
    str += std::to_string(r) + " ";
    if (r < 2) str += singular;
    else str += plural.empty() ? singular + 's' : plural;
    return static_cast<unsigned>(seconds) % count;
  }

  std::string duration::str() const {
    uint64_t seconds = seconds_;
    std::string str; str.reserve(100);

    // TODO: l10n i18n?
    seconds = append(str, seconds, SECONDS_IN_YEAR, "year");
    seconds = append(str, seconds, SECONDS_IN_MONTH, "month");
    seconds = append(str, seconds, SECONDS_IN_WEEK, "week");
    seconds = append(str, seconds, SECONDS_IN_DAY, "day");
    seconds = append(str, seconds, SECONDS_IN_HOUR, "hour");
    seconds = append(str, seconds, SECONDS_IN_MINUTE, "minute");
    append(str, seconds, 1, "second");

    return str;
  }
}

#endif //ASAP_DURATION_H
