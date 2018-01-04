#ifndef ASAP_DATETIME_TCC
#define ASAP_DATETIME_TCC

#include "datetime.h"
#include "period.h"

namespace asap {
  inline asap::datetime::datetime(time_t time) noexcept : when{} {
    when = *(std::localtime(&time));
  }

  inline asap::datetime::datetime(const std::string & datetime, const std::string & format, const std::string & locale) : when{} {
    static std::array<std::string, 7> fmts = {
        format,
        "%x %X",
        "%Y-%m-%dT%H:%M:%S",
        "%d/%m/%Y %H:%M:%S",
        "%H:%M:%S",
        "%d/%m/%Y",
        "%c"
    };

    for (std::string & fmt : fmts) {
      when = {0};
      std::stringstream ss(datetime);
      ss.imbue(std::locale(""));
      ss >> std::get_time(&when, fmt.c_str());
      if (str(fmt) == datetime) break;
    }
  }

  inline time_t asap::datetime::timestamp() const {
    std::tm temp = when;
    return mktime(&temp);
  }

  inline std::string asap::datetime::str(const std::string & fmt) const {
    char data[256];
    std::strftime(data, sizeof(data), fmt.c_str(), &when);
    return std::string(data);
  }

  inline asap::datetime & asap::datetime::operator+=(time_t stamp) {
    add(static_cast<long>(stamp));
    return *this;
  }

  inline asap::datetime & asap::datetime::operator-=(time_t stamp) {
    add(-static_cast<long>(stamp));
    return *this;
  }

  inline void asap::datetime::add(long seconds) {
    std::time_t time = std::mktime(&when);
    time += seconds;
    when = *(std::localtime(&time));
  }

  inline asap::datetime::datetime(uint32_t year, uint32_t month, uint32_t day, uint32_t hours, uint32_t minutes, uint32_t seconds)
      : datetime() {
    when.tm_year = year - 1900;
    when.tm_mon = month;
    when.tm_mday = day;
    when.tm_hour = hours;
    when.tm_min = minutes;
    when.tm_sec = seconds;
  }

  inline asap::datetime & asap::datetime::operator+=(const asap::seconds & d) {
    when.tm_sec += *d;
    mktime(&when);
    return *this;
  }

  inline asap::seconds asap::datetime::operator-(const datetime & other) const {
    const std::tm & a = when, b = other.when;
    uint64_t r = (a.tm_year - b.tm_year) * SECONDS_IN_YEAR +
                 (a.tm_mon  - b.tm_mon) * SECONDS_IN_MONTH +
                 (a.tm_mday - b.tm_mday) * SECONDS_IN_DAY +
                 (a.tm_hour - b.tm_hour) * SECONDS_IN_HOUR +
                 (a.tm_min  - b.tm_min) * SECONDS_IN_MINUTE +
                 (a.tm_sec  - b.tm_sec);
    return asap::seconds(r);
  }

  inline asap::datetime & asap::datetime::operator+=(const asap::minutes & d) {
    when.tm_min += *d;
    return *this += asap::seconds((*d - std::floor(*d)) * SECONDS_IN_MINUTE);
  }

  inline asap::datetime & asap::datetime::operator+=(const hours & d) {
    when.tm_hour += *d;
    return *this += asap::minutes((*d - std::floor(*d)) * (SECONDS_IN_HOUR / SECONDS_IN_MINUTE));
  }

  inline asap::datetime & asap::datetime::operator+=(const asap::days & d) {
    when.tm_mday += *d;
    return *this += asap::hours((*d - std::floor(*d)) * (SECONDS_IN_DAY / SECONDS_IN_HOUR));
  }

  inline asap::datetime & asap::datetime::operator+=(const asap::weeks & d) {
    return *this += asap::days(*d * 7);
  }

  inline asap::datetime & asap::datetime::operator+=(const asap::months & d) {
    when.tm_mon += *d;
    return *this += asap::days((*d - std::floor(*d)) * (SECONDS_IN_MONTH / SECONDS_IN_DAY));
  }

  inline asap::datetime & asap::datetime::operator+=(const asap::years & d) {
    when.tm_year += *d;
    return *this += asap::months((*d - std::floor(*d)) * (SECONDS_IN_YEAR / SECONDS_IN_MONTH));
  }

  template<uint64_t convert>
  inline asap::datetime & asap::datetime::operator-=(const asap::duration<convert> & c) {
    return *this += -c;
  }

  inline int datetime::second() const { return when.tm_sec; }
  inline asap::datetime & datetime::second(int value) { when.tm_sec = value; std::mktime(&when); return *this; }
  inline  int datetime::minute() const { return when.tm_min; }
  inline asap::datetime & datetime::minute(int value) { when.tm_min = value; std::mktime(&when); return *this; }
  inline int datetime::hour() { return when.tm_hour; }
  inline asap::datetime & datetime::hour(int value) { when.tm_hour = value; std::mktime(&when); return *this; }
  inline int datetime::wday() { return when.tm_wday; }
  inline asap::datetime & datetime::wday(int value) { when.tm_wday = value; std::mktime(&when); return *this; }
  inline int datetime::mday() { return when.tm_mday; }
  inline asap::datetime & datetime::mday(int value) { when.tm_mday = value; std::mktime(&when); return *this; }
  inline int datetime::yday() { return when.tm_yday; }
  inline asap::datetime & datetime::yday(int value) { when.tm_yday = value; std::mktime(&when); return *this; }
  inline int datetime::month() { return when.tm_mon; }
  inline asap::datetime & datetime::month(int value) { when.tm_mon = value; std::mktime(&when); return *this; }
  inline int datetime::year() { return when.tm_year + 1900; }
  inline asap::datetime & datetime::year(int value) { when.tm_year = value - 1900; std::mktime(&when); return *this; }

  inline asap::period datetime::until(const asap::datetime & dt) const {
    return asap::period(*this, dt);
  }

  inline asap::datetime asap::datetime::morning() {
    auto r = *this;
    r.hour(8); r.minute(0); r.second(0);
    return r;
  }

  inline asap::datetime datetime::afternoon() {
    auto r = *this;
    r.hour(12); r.minute(0); r.second(0);
    return r;
  }

  inline asap::datetime datetime::midnight() {
    auto r = *this;
    r.hour(0); r.minute(0); r.second(0);
    return r;
  }

  inline bool datetime::is(asap::periods kind) {
    bool result = true;

    if (kind & sunday)                  result = result && (when.tm_wday == 0);
    if (kind & monday)                  result = result && (when.tm_wday == 1);
    if (kind & tuesday)                 result = result && (when.tm_wday == 2);
    if (kind & wednesday)               result = result && (when.tm_wday == 3);
    if (kind & thursday)                result = result && (when.tm_wday == 4);
    if (kind & friday)                  result = result && (when.tm_wday == 5);
    if (kind & saturday)                result = result && (when.tm_wday == 6);
    if (kind & weekday)                 result = result && (when.tm_wday != 6 && when.tm_wday != 0);
    if (kind & businesstime)            result = result && is(weekday) && (when.tm_hour >= 8 && when.tm_hour <= 18);
    if (kind & daytime)                     result = result && (when.tm_hour >= 6 || when.tm_hour <= 18);
    if (kind & periods::morning)        result = result && (when.tm_hour >= 6 || when.tm_hour <= 12);
    if (kind & periods::afternoon)      result = result && (when.tm_hour >= 12 || when.tm_hour <= 18);
    if (kind & nighttime)                   result = result && (when.tm_hour >= 18 || when.tm_hour <= 6);
    if (kind & convenient)              result = result && (when.tm_hour >= 8 || when.tm_hour <= 20);

    return result;
  }

  inline bool datetime::any(asap::periods kind) {
    bool result = false;

    if (kind & sunday)                  result = result || (when.tm_wday == 0);
    if (kind & monday)                  result = result || (when.tm_wday == 1);
    if (kind & tuesday)                 result = result || (when.tm_wday == 2);
    if (kind & wednesday)               result = result || (when.tm_wday == 3);
    if (kind & thursday)                result = result || (when.tm_wday == 4);
    if (kind & friday)                  result = result || (when.tm_wday == 5);
    if (kind & saturday)                result = result || (when.tm_wday == 6);
    if (kind & weekday)                 result = result || when.tm_wday != 6 && when.tm_wday != 0;
    if (kind & businesstime)            result = result || is(weekday) && (when.tm_hour >= 8 && when.tm_hour <= 18);
    if (kind & daytime)                     result = result || (when.tm_hour >= 6 || when.tm_hour <= 18);
    if (kind & periods::morning)        result = result && (when.tm_hour >= 6 || when.tm_hour <= 12);
    if (kind & periods::afternoon)      result = result && (when.tm_hour >= 12 || when.tm_hour <= 18);
    if (kind & nighttime)                   result = result || (when.tm_hour >= 18 || when.tm_hour <= 6);
    if (kind & convenient)              result = result || (when.tm_hour >= 8 || when.tm_hour <= 20);

    return result;
  }
}

#endif //ASAP_DATETIME_TCC
