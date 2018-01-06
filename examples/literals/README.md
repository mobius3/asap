# `asap::literals`

The namespace `asap::literals` provides user-defined literals to aid in construction of `asap::duration` classes.

- `_seconds` is equivalent to `asap::seconds`
- `_minutes` is equivalent to `asap::minutes`
- `_hours` is equivalent to `asap::hours`
- `_days` is equivalent to `asap::days`
- `_weeks` is equivalent to `asap::weeks`
- `_months` is equivalent to `asap::months`
- `_years` is equivalent to `asap::years`

You have to explicitly include these literals by adding the following in your code that is using ASAP:

```cpp
using namespace asap::literals
```

These literals can be used as a shorthand for their class counterpart:

```cpp
// instead of
std::cout << asap::now() + asap::days(2) - asap::hours(1) << std::endl;

// you can write
std::cout << asap::now() + 2_days - 1_hour << std::endl;
```
