#ifndef ASAP_CONSTANTS_H
#define ASAP_CONSTANTS_H

#include <cstdint>

namespace asap {
  static constexpr uint64_t SECONDS_IN_YEAR = (60 * 60 * 24 * 365);
  static constexpr uint64_t SECONDS_IN_MONTH = (60 * 60 * 24 * 365/12);
  static constexpr uint64_t SECONDS_IN_WEEK = (60 * 60 * 24 * 365/12/4);
  static constexpr uint64_t SECONDS_IN_DAY = (60 * 60 * 24);
  static constexpr uint64_t SECONDS_IN_HOUR = (60 * 60);
  static constexpr uint64_t SECONDS_IN_MINUTE = (60);
}

#endif //ASAP_CONSTANTS_H
