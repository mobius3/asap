#ifndef ASAP_RANGE_H
#define ASAP_RANGE_H

#include "datetime.h"
#include "operators.h"

namespace asap {
  class period;

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

          iterator( const asap::datetime & now,
                    const asap::datetime & begin,
                    const asap::datetime & end,
                    const step_t & step)
              : now(now), begin(begin), end(end), step(step) { }

          const asap::datetime & operator++() {
            now += step;
            if (now > end) now = end;
            return now;
          }

          const asap::datetime & operator*() { return now; }

          bool operator==(const iterator & other) {
            return other.now == now;
          }

          bool operator!=(const iterator & other) {
            return !(other.now == now);
          }
        };

        accessor::iterator begin() const {
          if (from() > to()) return {to(), to(), from() - 1, step};
          else return {from(), from(), to() + 1, step};
        }

        accessor::iterator end() const {
          if (from() > to()) return {from() - 1, to(), from() - 1, step};
          else return {to() + 1, from(), to() + 1, step};
        }

      private:
        accessor(const asap::period & range, step_t step)
            : range(range)
            , step(step) { }

        const asap::datetime & from() const;
        const asap::datetime & to() const;

      private:
        const asap::period & range;
        step_t step;

        friend class accessor::iterator;
        friend class asap::period;
    };
  }

  class period {
    public:
      explicit period(const asap::datetime & a = asap::datetime(), const asap::datetime & b = asap::datetime());
      const asap::datetime & from() const { return begin_; }
      void from(const asap::datetime & begin) { begin_ = begin; }

      const asap::datetime & to() const { return end_; }
      void to(const asap::datetime & end) { end_ = end; }

      //asap::duration difference() const { return end_ - begin_; }

      template<uint64_t stepconv>
      asap::detail::accessor<stepconv> every(const asap::duration<stepconv> & d) const;

    private:
      asap::datetime begin_;
      asap::datetime end_;
  };

  template<uint64_t stepconv>
  const asap::datetime & detail::accessor<stepconv>::from() const { return range.from(); }

  template<uint64_t stepconv>
  const asap::datetime & detail::accessor<stepconv>::to() const { return range.to(); }

  period::period(const datetime & a, const datetime & b)
      : begin_(a)
      , end_(b)
  {

  }

  template<uint64_t stepconv>
  asap::detail::accessor<stepconv> period::every(const asap::duration<stepconv> & d) const {
    return {*this, d};
  }
}

#endif //ASAP_RANGE_H
