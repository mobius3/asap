# `asap::duration`

Durations can be obtained via the following classes

* `asap::seconds` for specifying a duration in *seconds*
* `asap::minutes` for specifying a duration in *minutes*
* `asap::hours` for specifying a duration in *hours*
* `asap::days` for specifying a duration in *days*
* `asap::weeks` for specifying a duration in *weeks*
* `asap::months` for specifying a duration in *months*
* `asap::years` for specifying a duration in *years*

All of them have singular equivalents (e.g, `asap::minute`) for convenience. They can also be constructed from
literals available in the `asap::literals` namespace. Consult the [literals]() documentation for more about
 ASAP literals.

Note that they all work with floating point values, so you can specify fractions of a duration:

```cpp
// specify half a day (which is equivalent to 12 hours):
auto halfday = asap::days(0.5f);

// note that half an year is not equivalent to 6 months, mainly because
// for duration, a month has 30 days.
bool equiv = asap::years(0.5f) == asap::months(6); //false
``` 

You can add and subtract durations from each other. The right-hand operand will be converted to the same "*base*" as the
left-hand operator (e.g, if you add `asap::seconds` to `asap::year`, the year will be converted to seconds and then
added). For this reason is not advisable to add periods with large different convertion factors between the left and the
right operands. It is ok to add a year to a second, but seconds added to a year can have rounding issues as it
will be converted to a fraction of a year.

```cpp
std::cout << asap::day(1) + asap::month(1) << std::endl
// "1 month, 1 day"

std::cout << asap::year(1) + asap::second(1) << std::endl
// "1 year", second is lost due to rounding
```

Subtracting an `asap::datetime` from another will give you an `asap::duration`:
```cpp
std::cout << asap::tomorrow() - asap::now() << std::endl;
// 9 hours, 27 minutes, 11 seconds
```

You can also add or subtract durations from `asap::datetime` objects:

```cpp
std::cout << asap::now() << std::endl;                 // -> 06-01-2018 14:35:39
std::cout << asap::now() + asap::days(1) << std::endl; // -> 07-01-2018 14:35:39
```

---

> - [Example for `asap::duration`]()
> - [Back to example docs]()
> - [Back to main docs]()
