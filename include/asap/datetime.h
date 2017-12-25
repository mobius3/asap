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
      explicit datetime(const std::string & datetime, std::string format = "");
      datetime(uint32_t year, uint32_t month, uint32_t day, uint32_t hours = 0, uint32_t minutes = 0, uint32_t seconds = 0);

      datetime & operator+=(const seconds & d);
      datetime & operator+=(const minutes & d);
      datetime & operator+=(const hours & d);
      datetime & operator+=(const days & d);
      datetime & operator+=(const weeks & d);
      datetime & operator+=(const months & d);
      datetime & operator+=(const years & d);

      template<int convert>
      datetime & operator-=(const duration<convert> & c) {
        return *this += -c;
      }

      //datetime & operator-=(const duration & duration);
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

  inline datetime::datetime(const std::string & datetime, std::string format) : when{} {
    std::stringstream ss;

    static std::array<std::string, 10> fmts = {
      "%Y-%m-%d %H:%M:%S",
      "%m/%d/%Y %H:%M:%S",
    };
    if (format.empty()) format = fmts[0];

    do {
      ;
      ss << datetime;
      ss >> std::get_time(&when, format.c_str());
      format = *(fmts++)
    } while(ss.fail() || ss.bad());

    format = "%Y-%m-%d %H:%M:%S";
    ss << datetime;
    ss >> std::get_time(&when, format.c_str());
    if (ss.good()) return;

    std::cout << "gfb: " << ss.good() << ss.fail() << ss.bad() << std::endl;
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

  datetime & datetime::operator+=(const seconds & d) {
    when.tm_sec += *d;
    mktime(&when);
    return *this;
  }

  datetime & datetime::operator+=(const minutes & d) {
    when.tm_min += *d;
    return *this += asap::seconds((*d - std::floor(*d)) * SECONDS_IN_MINUTE);
  }

  datetime & datetime::operator+=(const hours & d) {
    when.tm_hour += *d;
    return *this += asap::minutes((*d - std::floor(*d)) * (SECONDS_IN_HOUR / SECONDS_IN_MINUTE));
  }

  datetime & datetime::operator+=(const days & d) {
    when.tm_mday += *d;
    return *this += asap::hours((*d - std::floor(*d)) * (SECONDS_IN_DAY / SECONDS_IN_HOUR));
  }

  datetime & datetime::operator+=(const weeks & d) {
    return *this += asap::days(*d * 7);
  }

  datetime & datetime::operator+=(const months & d) {
    when.tm_mon += *d;
    return *this += asap::days((*d - std::floor(*d)) * (SECONDS_IN_MONTH / SECONDS_IN_DAY));
  }

  datetime & datetime::operator+=(const years & d) {
    when.tm_year += *d;
    return *this += asap::months((*d - std::floor(*d)) * (SECONDS_IN_YEAR / SECONDS_IN_MONTH));
  }
}

#endif // ASAP_DATETIME_H
