#ifndef ASAP_DURATION_H
#define ASAP_DURATION_H

#include <string>

namespace asap {
  class duration {
    public:
      explicit duration(uint64_t seconds);
      duration & operator+=(const duration & other);
      duration & operator-=(const duration & other);

      std::string str() const;

      uint64_t seconds() const { return seconds_; }

    private:
      uint64_t seconds_;
  };

  duration::duration(uint64_t seconds) : seconds_(seconds) { }


  duration & duration::operator+=(const duration & other) {
    seconds_ += other.seconds_;
    return *this;
  }

  duration & duration::operator-=(const duration & other) {
    if (other.seconds_ > seconds_) seconds_ = 0;
    else seconds_ -= other.seconds_;
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
    static constexpr uint64_t YEAR = (60 * 60 * 24 * 365);
    static constexpr uint64_t MONTH = (60 * 60 * 24 * 365/12);
    static constexpr uint64_t WEEK = (60 * 60 * 24 * 365/12/4);
    static constexpr uint64_t DAY = (60 * 60 * 24);
    static constexpr uint64_t HOUR = (60 * 60);
    static constexpr uint64_t MINUTE = (60);
    uint64_t seconds = seconds_;
    std::string str; str.reserve(100);

    // TODO: l10n i18n?
    seconds = append(str, seconds, YEAR, "year");
    seconds = append(str, seconds, MONTH, "month");
    seconds = append(str, seconds, WEEK, "week");
    seconds = append(str, seconds, DAY, "day");
    seconds = append(str, seconds, HOUR, "hour");
    seconds = append(str, seconds, MINUTE, "minute");
    append(str, seconds, 1, "second");

    return str;
  }
}

#endif //ASAP_DURATION_H
