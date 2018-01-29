# The ASAP date/time library

ASAP is a small, header-only date-time library for C++11 and beyond. It is heavily inspired by my great time using [momentjs](momentjs.com) to parse and display dates. ASAP has a lot of syntatic sugar to make your code look pretty both on the inside and outside :)

## Features

- A date/time class to handle dates and time (duh)
- A duration class to handle unbounded periods (e.g, `asap::day(1)` specifies a day)
- A period class to handle bounded periods (e.g, `asap::period(asap::now(), asap::tomorrow())`)
- Lots of syntatic sugar (e.g, `auto then = asap::now() + asap::week(1)`)
- Literals (e.g, `auto then = asap::now() + 1_year`) for seconds, minutes, hours, days, weeks, months and years
- Broken down duration printing (e.g, `asap::days(10)` prints `"1 week, 3 days"`)
- Range-based iteration for periods:
```
   for (auto x: asap::now().until(asap::tomorrow()).every(1_hour)) {
        std::cout << x << std::endl;
   }
```
