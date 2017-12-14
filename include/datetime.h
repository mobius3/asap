#ifndef ASAP_DATETIME_H
#define ASAP_DATETIME_H

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

#include "duration.h"

namespace asap {
  class datetime {
    public:
      explicit datetime(time_t time = std::time(nullptr)) noexcept;
      datetime(const std::string & datetime, const std::string & format);
      datetime(uint32_t year, uint32_t month, uint32_t day, uint32_t hours = 0, uint32_t minutes = 0, uint32_t seconds = 0);
      datetime & operator+=(const duration & duration);
      datetime & operator-=(const duration & duration);
      datetime & operator+=(time_t stamp);
      datetime & operator-=(time_t stamp);

      time_t timestamp() const;
      std::string str(const std::string & fmt = "%c") const;

    private:
      void add(long seconds);
      std::tm when;
  };


  inline datetime::datetime(time_t time) noexcept : when{} {
    when = *(std::localtime(&time));
  }

  inline datetime::datetime(const std::string & datetime, const std::string & format) : when{} {
    std::istringstream ss(datetime);
    ss >> std::get_time(&when, format.c_str());
  }

  inline time_t datetime::timestamp() const {
    std::tm temp = when;
    return mktime(&temp);
  }

  inline std::string datetime::str(const std::string & fmt) const {
    char data[256];
    std::strftime(data, sizeof(data), fmt.c_str(), &when);
    return std::string(data);
  }

  datetime & datetime::operator+=(const duration & duration) {
    add(duration.seconds());
    return *this;
  }

  datetime & datetime::operator-=(const duration & duration) {
    add(-duration.seconds());
    return *this;
  }

  datetime & datetime::operator+=(time_t stamp) {
    add(static_cast<long>(stamp));
    return *this;
  }

  datetime & datetime::operator-=(time_t stamp) {
    add(-static_cast<long>(stamp));
    return *this;
  }

  void datetime::add(long seconds) {
    std::time_t time = std::mktime(&when);
    time += seconds;
    when = *(std::localtime(&time));
  }

  datetime::datetime(uint32_t year, uint32_t month, uint32_t day, uint32_t hours, uint32_t minutes, uint32_t seconds)
      : datetime() {
    when.tm_year = year - 1900;
    when.tm_mon = month;
    when.tm_mday = day;
    when.tm_hour = hours;
    when.tm_min = minutes;
    when.tm_sec = seconds;
    mktime(&when);
  }
}

#include "operators.h"

#endif // ASAP_DATETIME_H
