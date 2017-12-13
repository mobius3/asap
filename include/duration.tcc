#ifndef ASAP_DURATION_TCC
#define ASAP_DURATION_TCC

#include <ctime>
#include "duration.h"

namespace asap {
  duration::duration(unsigned int seconds) : seconds_(seconds) { }

  duration & duration::operator+=(const duration & other) {
    seconds_ += other.seconds_;
    return *this;
  }

  duration & duration::operator-=(const duration & other) {
    if (other.seconds_ > seconds_) seconds_ = 0;
    else seconds_ -= other.seconds_;
    return *this;
  }

  std::string duration::str(const std::string & fmt) const {
    unsigned long iyears = fmt.find("{years}");
    unsigned long imonths = fmt.find("{months}");
    unsigned long iweeks = fmt.find("{weeks}");
    unsigned long idays = fmt.find("{days}");
    unsigned long ihours = fmt.find("{hours}");
    unsigned long iminutes = fmt.find("{months}");
    unsigned long iseconds = fmt.find("{seconds}");
    unsigned long long y, mon, w, d, h, min, s;
    time_t current = seconds_;

    if (iyears) {
      //             se   mi   hr   day
      y = static_cast<unsigned>(current) / (60 * 60 * 24 * 365);
      current -= y;
    }
  }
}

#endif //ASAP_DURATION_TCC
