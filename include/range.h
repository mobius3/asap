#ifndef ASAP_RANGE_H
#define ASAP_RANGE_H

#include "datetime.h"
#include "types.h"

namespace asap {
  class range;

  namespace detail {
    class accessor {
      public:
        struct iterator {
          asap::datetime now;
          asap::datetime begin;
          asap::datetime end;
          asap::duration step;

          iterator( const asap::datetime & now,
                    const asap::datetime & begin,
                    const asap::datetime & end,
                    const asap::duration & step)
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
        accessor(const asap::range & range, asap::duration step)
            : range(range)
            , step(step) { }

        const asap::datetime & from() const;
        const asap::datetime & to() const;

      private:
        const asap::range & range;
        asap::duration step;

        friend class accessor::iterator;
        friend class asap::range;
    };
  }

  class range {
    public:
      explicit range(const asap::datetime & a = asap::datetime(), const asap::datetime & b = asap::datetime());
      const asap::datetime & from() const { return begin_; }
      void from(const asap::datetime & begin) { begin_ = begin; }

      const asap::datetime & to() const { return end_; }
      void to(const asap::datetime & end) { end_ = end; }

      //asap::duration difference() const { return end_ - begin_; }

      asap::detail::accessor each(const asap::duration & d) const;

    private:
      asap::datetime begin_;
      asap::datetime end_;
  };

  const asap::datetime & detail::accessor::from() const { return range.from(); }
  const asap::datetime & detail::accessor::to() const { return range.to(); }

  range::range(const datetime & a, const datetime & b)
      : begin_(a)
      , end_(b)
  {

  }

  asap::detail::accessor range::each(const asap::duration & d) const {
    return {*this, d};
  }
}

#endif //ASAP_RANGE_H
