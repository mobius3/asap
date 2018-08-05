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

#ifndef ASAP_PERIOD_TCC
#define ASAP_PERIOD_TCC

#include "period.h"

namespace asap {
  namespace detail {
    template<uint64_t stepconv>
    class accessor {
      private:
        using step_t = asap::duration<stepconv>;

      public:
        struct iterator {
          asap::datetime now;
          asap::datetime begin;
          asap::datetime end;
          step_t step;

          iterator(const asap::datetime & now,
                   const asap::datetime & begin,
                   const asap::datetime & end,
                   const step_t & step);

          const asap::datetime & operator++();
          asap::datetime operator++(int);
          const asap::datetime & operator*();
          bool operator==(const iterator & other);
          bool operator!=(const iterator & other);
        };

        accessor::iterator begin() const;
        accessor::iterator end() const;

      private:
        accessor(const asap::period & range, step_t step);

        const asap::datetime & from() const;
        const asap::datetime & to() const;

      private:
        const asap::period & range;
        step_t step;

        friend struct accessor::iterator;
        friend class asap::period;
    };
  }


  template <uint64_t stepconv>
  inline asap::detail::accessor<stepconv>::iterator::iterator(const asap::datetime & now, const asap::datetime & begin,
                                                       const asap::datetime & end,
                                                       const asap::detail::accessor<stepconv>::step_t & step)
      : now(now), begin(begin), end(end), step(step) { }

  template <uint64_t stepconv>
  inline const asap::datetime & detail::accessor<stepconv>::iterator::operator++() {
    now += step;
    if (now > end) now = end;
    return now;
  }

  template <uint64_t stepconv>
  inline asap::datetime detail::accessor<stepconv>::iterator::operator++(int) {
    datetime prev = now;
    now += step;
    if (now > end) now = end;
    return prev;
  }

  template <uint64_t stepconv>
  inline const asap::datetime & detail::accessor<stepconv>::iterator::operator*() { return now; }

  template <uint64_t stepconv>
  inline bool detail::accessor<stepconv>::iterator::operator==(const detail::accessor<stepconv>::iterator & other) {
    return other.now == now;
  }

  template <uint64_t stepconv>
  inline bool detail::accessor<stepconv>::iterator::operator!=(const detail::accessor<stepconv>::iterator & other) {
    return !(other.now == now);
  }


  template<uint64_t stepconv>
  inline const asap::datetime & detail::accessor<stepconv>::from() const { return range.from(); }

  template<uint64_t stepconv>
  inline const asap::datetime & detail::accessor<stepconv>::to() const { return range.to(); }

  template <uint64_t stepconv>
  inline typename detail::accessor<stepconv>::iterator detail::accessor<stepconv>::begin() const {
    if (from() > to()) return {to(), to(), from() - 1, step};
    else return {from(), from(), to() + 1, step};
  }

  template <uint64_t stepconv>
  inline typename detail::accessor<stepconv>::iterator detail::accessor<stepconv>::end() const {
    if (from() > to()) return {from() - 1, to(), from() - 1, step};
    else return {to() + 1, from(), to() + 1, step};
  }

  template <uint64_t stepconv>
  inline detail::accessor<stepconv>::accessor(const asap::period & range, detail::accessor<stepconv>::step_t step)
      : range(range)
      , step(step) { }

  inline period::period(const datetime & a, const datetime & b)
      : begin_(a)
      , end_(b) { }

  template<uint64_t stepconv>
  inline asap::detail::accessor<stepconv> period::every(const asap::duration<stepconv> & d) const {
    return {*this, d};
  }

  inline const asap::datetime & period::from() const { return begin_; }

  inline void period::from(const asap::datetime & begin) { begin_ = begin; }

  inline const asap::datetime & period::to() const { return end_; }

  inline void period::to(const asap::datetime & end) { end_ = end; }

  asap::seconds period::difference() const { return {end_ - begin_}; }
  template<typename T> T period::difference() const { return static_cast<T>(difference()); }
}

#endif //ASAP_PERIOD_TCC
