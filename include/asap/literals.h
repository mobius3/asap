#ifndef ASAP_LITERALS_H
#define ASAP_LITERALS_H

#include "duration.h"

namespace asap {
  namespace literals {
    inline static asap::years operator"" _years(long double v) { return asap::years(static_cast<double>(v)); }
    inline static asap::year operator""  _year(long double v) { return asap::year(static_cast<double>(v)); }
    inline static asap::years operator"" _yrs(long double v) { return asap::years(static_cast<double>(v)); }
    inline static asap::years operator"" _Y(long double v) { return asap::years(static_cast<double>(v)); }
    inline static asap::years operator"" _years(unsigned long long v) { return asap::years(static_cast<double>(v)); }
    inline static asap::year operator""  _year(unsigned long long v) { return asap::year(static_cast<double>(v)); }
    inline static asap::years operator"" _yrs(unsigned long long v) { return asap::years(static_cast<double>(v)); }
    inline static asap::years operator"" _Y(unsigned long long v) { return asap::years(static_cast<double>(v)); }

    inline static asap::months operator"" _months(long double v) { return asap::months(static_cast<double>(v)); }
    inline static asap::month operator""  _month(long double v) { return asap::month(static_cast<double>(v)); }
    inline static asap::months operator"" _mon(long double v) { return asap::month(static_cast<double>(v)); }
    inline static asap::months operator"" _m(long double v) { return asap::month(static_cast<double>(v)); }
    inline static asap::months operator"" _months(unsigned long long v) { return asap::months(static_cast<double>(v)); }
    inline static asap::month operator""  _month(unsigned long long v) { return asap::month(static_cast<double>(v)); }
    inline static asap::months operator"" _mon(unsigned long long v) { return asap::month(static_cast<double>(v)); }
    inline static asap::months operator"" _m(unsigned long long v) { return asap::month(static_cast<double>(v)); }

    inline static asap::days operator"" _days(long double v) { return asap::days(static_cast<double>(v)); }
    inline static asap::day operator"" _day(long double v) { return asap::day(static_cast<double>(v)); }
    inline static asap::days operator"" _d(long double v) { return asap::day(static_cast<double>(v)); }
    inline static asap::days operator"" _days(unsigned long long v) { return asap::days(static_cast<double>(v)); }
    inline static asap::day operator"" _day(unsigned long long v) { return asap::day(static_cast<double>(v)); }
    inline static asap::days operator"" _d(unsigned long long v) { return asap::day(static_cast<double>(v)); }

    inline static asap::hours operator"" _hours(long double v) { return asap::hours(static_cast<double>(v)); }
    inline static asap::hour operator"" _hour(long double v) { return asap::hour(static_cast<double>(v)); }
    inline static asap::hours operator"" _hrs(long double v) { return asap::hours(static_cast<double>(v)); }
    inline static asap::hours operator"" _H(long double v) { return asap::hours(static_cast<double>(v)); }
    inline static asap::hours operator"" _hours(unsigned long long v) { return asap::hours(static_cast<double>(v)); }
    inline static asap::hour operator"" _hour(unsigned long long v) { return asap::hour(static_cast<double>(v)); }
    inline static asap::hours operator"" _hrs(unsigned long long v) { return asap::hours(static_cast<double>(v)); }
    inline static asap::hours operator"" _H(unsigned long long v) { return asap::hours(static_cast<double>(v)); }

    inline static asap::minutes operator"" _minutes(long double v) { return asap::minutes(static_cast<double>(v)); }
    inline static asap::minute operator"" _minute(long double v) { return asap::minute(static_cast<double>(v)); }
    inline static asap::minute operator"" _min(long double v) { return asap::minute(static_cast<double>(v)); }
    inline static asap::minutes operator"" _M(long double v) { return asap::minute(static_cast<double>(v)); }
    inline static asap::minutes operator"" _minutes(unsigned long long v) { return asap::minutes(static_cast<double>(v)); }
    inline static asap::minute operator"" _minute(unsigned long long v) { return asap::minute(static_cast<double>(v)); }
    inline static asap::minute operator"" _min(unsigned long long v) { return asap::minute(static_cast<double>(v)); }
    inline static asap::minutes operator"" _M(unsigned long long v) { return asap::minute(static_cast<double>(v)); }

    inline static asap::seconds operator"" _seconds(long double v) { return asap::seconds(static_cast<double>(v)); }
    inline static asap::second operator"" _second(long double v) { return asap::second(static_cast<double>(v)); }
    inline static asap::seconds operator"" _sec(long double v) { return asap::seconds(static_cast<double>(v)); }
    inline static asap::seconds operator"" _S(long double v) { return asap::seconds(static_cast<double>(v)); }
    inline static asap::seconds operator"" _seconds(unsigned long long v) { return asap::seconds(static_cast<double>(v)); }
    inline static asap::second operator"" _second(unsigned long long v) { return asap::second(static_cast<double>(v)); }
    inline static asap::seconds operator"" _sec(unsigned long long v) { return asap::seconds(static_cast<double>(v)); }
    inline static asap::seconds operator"" _S(unsigned long long v) { return asap::seconds(static_cast<double>(v)); }
  }
}

#endif //ASAP_LITERALS_H
