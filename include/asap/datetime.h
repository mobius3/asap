#ifndef ASAP_DATETIME_H
#define ASAP_DATETIME_H

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

#include "duration.h"

namespace asap {
  class period;

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
      template<uint64_t convert> asap::datetime & operator-=(const asap::duration<convert> & c);
      asap::datetime & operator+=(time_t stamp);
      asap::datetime & operator-=(time_t stamp);

      time_t timestamp() const;
      std::string str(const std::string & fmt = "%x %X") const;
      asap::period until(const asap::datetime & dt) const;

      int second() const;
      asap::datetime & second(int value);

      int minute() const;
      asap::datetime & minute(int value);

      int hour();
      asap::datetime & hour(int value);

      int wday();
      asap::datetime & wday(int value);

      int mday();
      asap::datetime & mday(int value);

      int yday();
      asap::datetime & yday(int value);

      int month();
      asap::datetime & month(int value);

      int year();
      asap::datetime & year(int value);

    private:
      void add(long seconds);
      std::tm when;
  };
}

#endif // ASAP_DATETIME_H
