# The ASAP date/time library for beautiful C++ code

ASAP is a small, header-only date-time library for C++11 and beyond. It is heavily inspired by my great time using [momentjs](momentjs.com) to parse and display dates. ASAP has a lot of syntatic sugar to make your code look pretty both on the inside and outside :)

All ASAP examples available [online at _repl.it_](https://repl.it/@mobius3/asapexamples). (`main()` starts at line `533`)

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

## Index

- asap::datetime [class docs](http://mobius3.github.io/asap/api/classasap_1_1datetime.html) to learn about date/time
- asap::duration [class docs](http://mobius3.github.io/asap/api/classasap_1_1duration.html) will teach you about durations and their literals
- asap::period [class docs](http://mobius3.github.io/asap/api/classasap_1_1period.html) to learn about periods and date/time iterations
- literals.h [docs](http://mobius3.github.io/asap/api/literals_8h_source.html) has the asap::literals namespace with all ASAP literals

## Using

You can either:

- Drop the `include/asap` folder in your project and use it
- Make your compiler aware of the `include/asap` folder and include `"asap.h"` in your code
- If using CMake you can add the project subdirectory and link against it using `target_link_libraries`
- Use `find_package` if you installed ASAP using `make install` or any other method
- Download the latest release which is a single `asap.h` file bundled with all the classes.

## License

ASAP is MIT licensed.
