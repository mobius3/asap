#ifndef ASAP_OPERATORS_H
#define ASAP_OPERATORS_H

#include "datetime.h"
#include "duration.h"

namespace asap {
  template<uint64_t convert>
  inline static asap::datetime operator+(const asap::datetime & a, const duration<convert> & b) {
    asap::datetime r = a;
    r += b;
    return r;
  }

  template<uint64_t convert>
  inline static asap::datetime operator-(const asap::datetime & a, const duration<convert> & b) {
    asap::datetime r = a;
    r -= b;
    return r;
  }

  inline static asap::datetime operator+(const asap::datetime & a, std::time_t b) {
    asap::datetime r = a;
    r += b;
    return r;
  }

  inline static asap::datetime operator-(const asap::datetime & a, std::time_t b) {
    asap::datetime r = a;
    r -= b;
    return r;
  }


  template<uint64_t c1, uint64_t c2>
  inline static duration<c1> operator+(const duration<c1> & a, const duration<c2> & b) {
    duration<c1> r = a;
    r += b;
    return r;
  };

  template<uint64_t conv>
  inline static duration<conv> operator+(const duration<conv> & a, const duration<conv> & b) {
    duration<conv> r = a;
    r += b;
    return r;
  };

  template<uint64_t c1, uint64_t c2>
  inline static duration<c1> operator-(const duration<c1> & a, const duration<c2> & b) {
    duration<c1> r = a;
    r -= b;
    return r;
  };

  template<uint64_t c1>
  inline static duration<c1> operator-(const duration<c1> & a) {
    duration<c1> r;
    r -= a;
    return r;
  };

  inline static bool operator<(const asap::datetime & a, const asap::datetime & b) {
    return a.timestamp() < b.timestamp();
  }

  inline static bool operator>(const asap::datetime & a, const asap::datetime & b) {
    return a.timestamp() > b.timestamp();
  }

  inline static bool operator==(const asap::datetime & a, const asap::datetime & b) {
    return a.timestamp() == b.timestamp();
  }

  template<typename ostream>
  inline static ostream & operator<<(ostream & os, const asap::datetime & dt) {
    return os << dt.str(), os;
  }

  template<typename ostream, uint64_t convert>
  inline static ostream & operator<<(ostream & os, const duration<convert> & du) {
    return os << du.str(), os;
  }
}

#endif //ASAP_OPERATORS_H
