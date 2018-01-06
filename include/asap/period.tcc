#ifndef ASAP_PERIOD_TCC
#define ASAP_PERIOD_TCC

#include "period.h"

namespace asap {
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
