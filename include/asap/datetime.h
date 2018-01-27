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

#ifndef ASAP_DATETIME_H
#define ASAP_DATETIME_H

#include "duration.h"

namespace asap {
  class period;

  class datetime {
    public:
      explicit datetime(time_t time = std::time(nullptr)) noexcept;
      explicit datetime(const std::string & datetime, const std::string & format = "%x %X", const std::string & locale = "");
      datetime(uint32_t year, uint32_t month, uint32_t day, uint32_t hours = 0, uint32_t minutes = 0, uint32_t seconds = 0);

      datetime & operator+=(const seconds & d);
      datetime & operator+=(const minutes & d);
      datetime & operator+=(const hours & d);
      datetime & operator+=(const days & d);
      datetime & operator+=(const weeks & d);
      datetime & operator+=(const months & d);
      datetime & operator+=(const years & d);
      asap::seconds operator-(const datetime & other) const;
      template<uint64_t convert> asap::datetime & operator-=(const asap::duration<convert> & c);
      asap::datetime & operator+=(time_t stamp);
      asap::datetime & operator-=(time_t stamp);

      asap::datetime morning();
      asap::datetime afternoon();
      asap::datetime midnight();

      time_t timestamp() const;
      std::string str(const std::string & fmt = "%x %X") const;
      asap::period until(const asap::datetime & dt) const;

      int second() const;
      asap::datetime & second(int value);

      int minute() const;
      asap::datetime & minute(int value);

      int hour() const;
      asap::datetime & hour(int value);

      int wday() const;
      asap::datetime & wday(int value);

      int mday() const;
      asap::datetime & mday(int value);

      int yday() const;
      asap::datetime & yday(int value);

      int month() const;
      asap::datetime & month(int value);

      int year() const;
      asap::datetime & year(int value);

    private:
      void add(long seconds);
      std::tm when;
  };
}

#endif // ASAP_DATETIME_H
