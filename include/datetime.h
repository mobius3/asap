#ifndef ASAP_DATETIME_H
#define ASAP_DATETIME_H

#include <ctime>
#include <string>

namespace asap {
  class duration;
  class datetime {
    public:
      datetime() noexcept;
      explicit datetime(time_t time) noexcept;
      datetime(const std::string & datetime, const std::string & format);
      //datetime & operator+=(const duration & duration);
      //datetime & operator-=(const duration & duration);

      time_t timestamp() const;
      std::string str(const std::string & fmt = "%c") const;

    private:
      std::tm when;
  };
}

#include "datetime.tcc"

#endif // ASAP_DATETIME_H
