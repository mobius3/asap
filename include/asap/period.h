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

#ifndef ASAP_RANGE_H
#define ASAP_RANGE_H

#include "datetime.h"
#include "operators.h"

namespace asap {
  class period;
  namespace detail { template <uint64_t T> class accessor; }

  class period {
    public:
      explicit period(const asap::datetime & a = asap::datetime(), const asap::datetime & b = asap::datetime());
      const asap::datetime & from() const;
      void from(const asap::datetime & begin);

      const asap::datetime & to() const;
      void to(const asap::datetime & end);

      /**
       * @brief Calculates the difference between the start and the end
       * @tparam T the type to return (e.g, `asap::seconds`)
       * @return An T instance
       */
      template<typename T> T difference() const;

      /**
       * @brief Calculates the difference between the start and the end as seconds
       * @return An asap::seconds instance
       */
      asap::seconds difference() const;

      template<uint64_t stepconv>
      asap::detail::accessor<stepconv> every(const asap::duration<stepconv> & d) const;

    private:
      asap::datetime begin_;
      asap::datetime end_;
  };
}

#endif //ASAP_RANGE_H
