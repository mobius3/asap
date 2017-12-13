#ifndef ASAP_DURATION_H
#define ASAP_DURATION_H

#include <string>

namespace asap {
  class duration {
    public:
      duration(unsigned int seconds);
      duration & operator+=(const duration & other);
      duration & operator-=(const duration & other);

      std::string str(const std::string & fmt) const;

    private:
      unsigned seconds_;
  };
}

#include "duration.tcc"

#endif //ASAP_DURATION_H
