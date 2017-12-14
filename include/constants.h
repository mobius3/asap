#ifndef ASAP_CONSTANTS_H
#define ASAP_CONSTANTS_H

#include <cstdint>

namespace asap {
  static constexpr uint64_t SECONDS_IN_MINUTE = 60;
  static constexpr uint64_t SECONDS_IN_HOUR = SECONDS_IN_MINUTE * 60;
  static constexpr uint64_t SECONDS_IN_DAY = SECONDS_IN_HOUR * 24;
  static constexpr uint64_t SECONDS_IN_MONTH = SECONDS_IN_DAY * 30;
  static constexpr uint64_t SECONDS_IN_YEAR = SECONDS_IN_DAY * 365;
  static constexpr uint64_t SECONDS_IN_WEEK = SECONDS_IN_DAY * 7;
}

#endif //ASAP_CONSTANTS_H
