#ifndef ASAP_TYPES_H
#define ASAP_TYPES_H

#include "duration.h"

namespace asap {
  inline static duration years(uint32_t amount) { return duration(amount * SECONDS_IN_YEAR); }
  inline static duration year(uint32_t amount) { return years(amount); }

  inline static duration months(uint32_t amount) { return duration(amount * SECONDS_IN_MONTH); }
  inline static duration month(uint32_t amount) { return months(amount); }

  inline static duration weeks(uint32_t amount) { return duration(amount * SECONDS_IN_WEEK); }
  inline static duration week(uint32_t amount) { return weeks(amount); }

  inline static duration days(uint32_t amount) { return duration(amount * SECONDS_IN_DAY); }
  inline static duration day(uint32_t amount) { return days(amount); }

  inline static duration hours(uint32_t amount) { return duration(amount * SECONDS_IN_HOUR); }
  inline static duration hour(uint32_t amount) { return hours(amount); }

  inline static duration minutes(uint32_t amount) { return duration(amount * SECONDS_IN_MINUTE); }
  inline static duration minute(uint32_t amount) { return minutes(amount); }

  inline static duration seconds(uint32_t amount) { return duration(amount); }
  inline static duration second(uint32_t amount) { return seconds(amount); }
}

#endif //ASAP_TYPES_H
