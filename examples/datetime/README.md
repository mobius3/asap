# `asap::datetime`

The `datetime` example shows different ways of obtaining and printing an `asap::datetime` object. It can be constructed from:

- another `asap::datetime`
- a string in a known format
- a string with a specified format.
- seconds from unix epoch
- broken-down time (ie., `asap::datetime(2007, 6, 1, 0, 0, 0))` for July 1 2007

`asap::datetime` has overloads for printing to an `std::iostream` so you can directly print to `std::cout`:

```cpp
std::cout << asap::now() << std::endl;
```

You can also format it via the `asap::datetime::str` method

```cpp
std::cout << asap::now().str("%c") << std::endl;
``` 
