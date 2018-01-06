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

        friend class accessor::iterator;
        friend class asap::period;
    };
  }

  class period {
    public:
      explicit period(const asap::datetime & a = asap::datetime(), const asap::datetime & b = asap::datetime());
      const asap::datetime & from() const;
      void from(const asap::datetime & begin);

      const asap::datetime & to() const;
      void to(const asap::datetime & end);

      template<typename T> T difference() const;
      asap::seconds difference() const;

      template<uint64_t stepconv>
      asap::detail::accessor<stepconv> every(const asap::duration<stepconv> & d) const;

    private:
      asap::datetime begin_;
      asap::datetime end_;
  };
}

#endif //ASAP_RANGE_H
