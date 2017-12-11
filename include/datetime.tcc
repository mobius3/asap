#ifndef ASAP_DATETIME_TCC
#define ASAP_DATETIME_TCC

#include "datetime.h"
#include <ctime>
#include <iomanip>
#include <sstream>

namespace asap {
  inline datetime::datetime() noexcept : datetime(std::time(nullptr)) { }

  inline datetime::datetime(time_t time) noexcept {
    when = *(std::localtime(&time));
  }

  inline datetime::datetime(const std::string & datetime, const std::string & format) {
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

#endif // ASAP_DATETIME_TCC
