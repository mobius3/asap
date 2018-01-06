# ASAP C++ time library

ASAP is a library for C++ designed to provide date and time manipulation facilities in the most straightforward way. It strives for an (mostly) intuitive and simple API.

ASAP is MIT licensed.

## Index
- [Features]()
- [Dependencies]()
- [Usage]()
- [Documentation]()

## Features

- Date/time construction from `string`s, `time_t` and `struct tm`
- Date/time printing and formating
- Date/time manipulation via `asap::duration` type
- Duration manipulation (e.g: `asap::days(10) + asap::months(0.5)`)
- Broken down duration printing (e.g, `asap::days(10)` prints `"1 week, 3 days"`)
- Period creation and iteration:
     ```cpp
     asap::datetime x, y = x + asap::years(1);
     for (auto dt : asap::period(x, y).every(asap::weeks(1)) {
        std::cout << dt << std::endl;
     }
     ```
     prints every sunday between now and next year.
- Literals for seconds, minutes, hours, days, weeks, months and years. Example:
  - `1_day` constructs an `asap::days(1)`
    
## Dependencies

 - ASAP requires a compiler modern enough to support C++11
 - If adding to a CMake project, CMake 3.1.0 is required

## Usage

 ASAP is a header-only library. It means you should be able to:

 - Copy and paste the include/asap folder to your project
 - Add the `include/` directory to your project search path
 - Include it as a CMake subdirectory:
    ```cmake
    add_subdirectory(third-party/asap)
    target_link_library(your-executable PRIVATE asap)
    ```

All types are under the `asap` namespace. You can make them visible by
including the "asap.h" header:

```cpp
#include "asap.h"

using namespace asap; //if that's your thing
```

## Documentation

See [the examples]() folder for docs and examples.
