#ifndef ASAP_DATETIME_H
#define ASAP_DATETIME_H

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

namespace asap {
  class duration;
  class datetime {
    public:
      explicit datetime(time_t time = std::time(nullptr)) noexcept;
      datetime(const std::string & datetime, const std::string & format);
      datetime & operator+=(const duration & duration);
      datetime & operator-=(const duration & duration);

      time_t timestamp() const;
      std::string str(const std::string & fmt = "%c") const;

    private:
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
}

#include "operators.h"

#endif // ASAP_DATETIME_H
