# `asap::period`

The `asap::period` class provide functionality to iterate between two `asap::datetime` instances using a custom duration
as the stepping amount:

```cpp
for (auto d: asap::period(asap::now(), asap::tomorow()).every(1_hour)) {
  std::cout << d << std::endl;
}
```

You can also use the `asap::datetime::until` method to ease construction of `asap::period`:

```cpp
for (auto d: asap::now().until(asap::tomorrow()).every(1_hour)) {
  std::cout << d << std::endl;
}
```

You can specify a period and re-use it as many times as you want:

```cpp
auto period = asap::now().until(asap::tomorrow());
for (auto d: period.every(1_hour)) std::cout << d << std::endl;
for (auto d: period.every(1_minute)) std::cout << d << std::endl;
```

`period::difference()` returns the difference between the end `asap::datetime` minus the beginning. You can specify
the return type as a template parameter (or you can just crate an `asap::duration` from it):

```cpp
auto period = asap::now().until(asap::tomorrow());
auto diff1 = period.difference(); // as seconds;
auto diff2 = period.difference<asap::days>(); // as days;
asap::years diff3 = period.difference(); // as years;
```

You can also obtain the beginning and the end `asap::datetime` from a period using `from()` and `to()`. You can also use
`from(datetime)` and `to(datetime)` to set the beginning and the end of a period. Existing iterations won't be affected.
