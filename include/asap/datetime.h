#ifndef ASAP_DATETIME_H
#define ASAP_DATETIME_H

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

#include "duration.h"

namespace asap {
  class datetime {
    public:
      explicit datetime(time_t time = std::time(nullptr)) noexcept;
      explicit datetime(const std::string & datetime, const std::string & format = "%x %X", const std::string & locale = "");
      datetime(uint32_t year, uint32_t month, uint32_t day, uint32_t hours = 0, uint32_t minutes = 0, uint32_t seconds = 0);

      datetime & operator+=(const seconds & d);
      datetime & operator+=(const minutes & d);
      datetime & operator+=(const hours & d);
      datetime & operator+=(const days & d);
      datetime & operator+=(const weeks & d);
      datetime & operator+=(const months & d);
      datetime & operator+=(const years & d);
      asap::seconds operator-(const datetime & other) const;

      template<int convert>
      asap::datetime & operator-=(const asap::duration<convert> & c);

      asap::datetime & operator+=(time_t stamp);
      asap::datetime & operator-=(time_t stamp);

      time_t timestamp() const;
      std::string str(const std::string & fmt = "%x %X") const;

    private:
      void add(long seconds);
      std::tm when;
  };


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

  asap::datetime & asap::datetime::operator+=(time_t stamp) {
    add(static_cast<long>(stamp));
    return *this;
  }

  asap::datetime & asap::datetime::operator-=(time_t stamp) {
    add(-static_cast<long>(stamp));
    return *this;
  }

  void asap::datetime::add(long seconds) {
    std::time_t time = std::mktime(&when);
    time += seconds;
    when = *(std::localtime(&time));
  }

  asap::datetime::datetime(uint32_t year, uint32_t month, uint32_t day, uint32_t hours, uint32_t minutes, uint32_t seconds)
      : datetime() {
    when.tm_year = year - 1900;
    when.tm_mon = month;
    when.tm_mday = day;
    when.tm_hour = hours;
    when.tm_min = minutes;
    when.tm_sec = seconds;
  }

  asap::datetime & asap::datetime::operator+=(const asap::seconds & d) {
    when.tm_sec += *d;
    mktime(&when);
    return *this;
  }

  asap::seconds datetime::operator-(const datetime & other) const {
    const std::tm & a = when, b = other.when;
    uint64_t r = (a.tm_year - b.tm_year) * SECONDS_IN_YEAR +
                 (a.tm_mon  - b.tm_mon) * SECONDS_IN_MONTH +
                 (a.tm_mday - b.tm_mday) * SECONDS_IN_DAY +
                 (a.tm_hour - b.tm_hour) * SECONDS_IN_HOUR +
                 (a.tm_min  - b.tm_min) * SECONDS_IN_MINUTE +
                 (a.tm_sec  - b.tm_sec);
    return asap::seconds(r);
  }

  asap::datetime & asap::datetime::operator+=(const asap::minutes & d) {
    when.tm_min += *d;
    return *this += asap::seconds((*d - std::floor(*d)) * SECONDS_IN_MINUTE);
  }

  asap::datetime & asap::datetime::operator+=(const hours & d) {
    when.tm_hour += *d;
    return *this += asap::minutes((*d - std::floor(*d)) * (SECONDS_IN_HOUR / SECONDS_IN_MINUTE));
  }

  asap::datetime & asap::datetime::operator+=(const asap::days & d) {
    when.tm_mday += *d;
    return *this += asap::hours((*d - std::floor(*d)) * (SECONDS_IN_DAY / SECONDS_IN_HOUR));
  }

  asap::datetime & asap::datetime::operator+=(const asap::weeks & d) {
    return *this += asap::days(*d * 7);
  }

  asap::datetime & asap::datetime::operator+=(const asap::months & d) {
    when.tm_mon += *d;
    return *this += asap::days((*d - std::floor(*d)) * (SECONDS_IN_MONTH / SECONDS_IN_DAY));
  }

  asap::datetime & asap::datetime::operator+=(const asap::years & d) {
    when.tm_year += *d;
    return *this += asap::months((*d - std::floor(*d)) * (SECONDS_IN_YEAR / SECONDS_IN_MONTH));
  }

  template<int convert>
  asap::datetime & asap::datetime::operator-=(const asap::duration<convert> & c) {
    return *this += -c;
  }
}

#endif // ASAP_DATETIME_H
