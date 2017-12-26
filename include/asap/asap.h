#ifndef ASAP_H
#define ASAP_H

#include "datetime.h"
#include "duration.h"
#include "period.h"
#include "operators.h"

namespace asap {
  static inline asap::datetime now() { return datetime{}; }
}

#endif //ASAP_H
