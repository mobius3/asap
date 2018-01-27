/* * Copyright (C) 2018 Leonardo Guilherme Lucena de Freitas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef ASAP_H
#define ASAP_H

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <type_traits>
#include <cstdint>

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
