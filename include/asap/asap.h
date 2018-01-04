#ifndef ASAP_H
#define ASAP_H

#include "datetime.h"
#include "duration.h"
#include "period.h"
#include "operators.h"
#include "literals.h"

namespace asap {
  static inline asap::datetime now() { return datetime{}; }

  static inline asap::datetime tomorrow() {
    auto n = asap::now();
    n += asap::days(1);
    n.hour(0);
    n.minute(0);
    n.second(0);
    return n;
  }

  static inline asap::datetime yesterday() {
      auto n = asap::now();
      n -= asap::days(1);
      n.hour(0);
      n.minute(0);
      n.second(0);
      return n;
  }
}

#include "datetime.tcc"
#include "duration.tcc"
#include "period.tcc"

#endif //ASAP_H
