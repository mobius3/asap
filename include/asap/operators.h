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

#ifndef ASAP_OPERATORS_H
#define ASAP_OPERATORS_H

#include "datetime.h"
#include "duration.h"

namespace asap {
  /**
   * @brief Adds a duration to a datetime
   * @tparam convert the converting factor for the duration (automatically deduced)
   * @param a the datetime
   * @param b the duration
   * @return a new datetime equivalent to a + b
   */
  template<uint64_t convert>
  inline static asap::datetime operator+(const asap::datetime & a, const duration<convert> & b) {
    asap::datetime r = a;
    r += b;
    return r;
  }

  /**
   * @brief Subtracts a duration from a datetime
   * @tparam convert the converting factor for the duration (automatically deduced)
   * @param a the datetime
   * @param b the duration
   * @return a new datetime equivalent to a - b
   */
  template<uint64_t convert>
  inline static asap::datetime operator-(const asap::datetime & a, const duration<convert> & b) {
    asap::datetime r = a;
    r -= b;
    return r;
  }


  /**
   * @brief Adds a duration specified in a time_t to a datetime
   * @param a the datetime
   * @param b the duration in seconds since epoch (time_t)
   * @return a new datetime equivalent to a + b
   */
  inline static asap::datetime operator+(const asap::datetime & a, std::time_t b) {
    asap::datetime r = a;
    r += b;
    return r;
  }

  /**
   * @brief Subtracts a duration specified in a time_t from a datetime
   * @param a the datetime
   * @param b the duration in seconds since epoch (time_t)
   * @return a new datetime equivalent to a - b
   */
  inline static asap::datetime operator-(const asap::datetime & a, std::time_t b) {
    asap::datetime r = a;
    r -= b;
    return r;
  }

  /**
   * @brief Adds two durations
   * @tparam c1 the converting factor for the first duration (automatically deduced)
   * @tparam c2 the converting factor for the second duration (automatically deduced)
   * @param a The first duration
   * @param b The second duration
   * @return A new asap::duration equivalent to a + b converted to the factor of the first operand
   */
  template<uint64_t c1, uint64_t c2>
  inline static duration<c1> operator+(const duration<c1> & a, const duration<c2> & b) {
    duration<c1> r = a;
    r += b;
    return r;
  };

  /**
   * @brief Adds two durations of the same converting factor
   * @tparam conv the converting factor for the second duration (automatically deduced)
   * @param a The first duration
   * @param b The second duration
   * @return A new asap::duration equivalent to a + b
   */
  template<uint64_t conv>
  inline static duration<conv> operator+(const duration<conv> & a, const duration<conv> & b) {
    duration<conv> r = a;
    r += b;
    return r;
  };

  /**
 * @brief Subtracts two durations
 * @tparam c1 the converting factor for the first duration (automatically deduced)
 * @tparam c2 the converting factor for the second duration (automatically deduced)
 * @param a The first duration
 * @param b The second duration
 * @return A new asap::duration equivalent to a - b converted to the factor of the first operand
 */
  template<uint64_t c1, uint64_t c2>
  inline static duration<c1> operator-(const duration<c1> & a, const duration<c2> & b) {
    duration<c1> r = a;
    r -= b;
    return r;
  };

  /**
   * @brief Inverts the sign of the duration
   * @tparam c1 the convert factor of the duration (automatically deduced)
   * @param a The duration
   * @return a duration equivalent to `-a` (e.g, `1 day -> minus 1 day`)
   */
  template<uint64_t c1>
  inline static duration<c1> operator-(const duration<c1> & a) {
    duration<c1> r;
    r -= a;
    return r;
  };

  /**
   * @brief Compares if `a < b` is true for two asap::datetime instances
   * @param a The first operand
   * @param b The second operand
   * @return true if a < b, false otherwise
   */
  inline static bool operator<(const asap::datetime & a, const asap::datetime & b) {
    return a.timestamp() < b.timestamp();
  }

  /**
   * @brief Compares if `a > b` is true for two asap::datetime instances
   * @param a The first operand
   * @param b The second operand
   * @return true if a > b, false otherwise
   */
  inline static bool operator>(const asap::datetime & a, const asap::datetime & b) {
    return a.timestamp() > b.timestamp();
  }

  /**
   * @brief Compares if `a == b` is true for two asap::datetime instances
   * @param a The first operand
   * @param b The second operand
   * @return true if a == b, false otherwise
   */
  inline static bool operator==(const asap::datetime & a, const asap::datetime & b) {
    return a.timestamp() == b.timestamp();
  }

  /**
   * @brief Inserts a datetime into an standard output stream
   * @tparam ostream The output stream type
   * @param os The output stream instance
   * @param dt The datetime to insert
   * @return the ostream instance passed in
   * @details this allows you to write `std::cout << asap::now() << std::endl`
   */
  template<typename ostream>
  inline static ostream & operator<<(ostream & os, const asap::datetime & dt) {
    return os << dt.str(), os;
  }

  /**
   * @brief Inserts a duration into an standard output stream
   * @tparam ostream The output stream type
   * @tparam convert The converting factor for the duration (automatically deduced)
   * @param os The output stream instance
   * @param du The duration to insert
   * @return the ostream instance passed in
   * @details this allows you to write `std::cout << asap::now() << std::endl`
   */
  template<typename ostream, uint64_t convert>
  inline static ostream & operator<<(ostream & os, const duration<convert> & du) {
    return os << du.str(), os;
  }
}

#endif //ASAP_OPERATORS_H
