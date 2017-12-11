#ifndef ASAP_DURATION_H
#define ASAP_DURATION_H

#include <string>

namespace asap {
  class duration {
    public:
      duration(unsigned int seconds);
      duration & operator+=(const duration & other);
      duration & operator-=(const duration & other);
      std::string format(const std::string & fmt);

      unsigned years() const;
      unsigned months() const;
      unsigned days() const;
      unsigned minutes() const;
      unsigned seconds() const;
  };
}

#endif //ASAP_DURATION_H
