## Description

A generic signal processing library that provides the following functionality:

- `in_range(value, min, max)` - checks whether `value` is within the range `[min, max]`
- `clamp(value, min, max)` - clamps `value` to the range `[min, max]`
- `min(first, last)` - returns the minumum value for the range `[first, last)`
- `max(first, last)` - returns the maximum value for the range `[first, last)`
- `avg(first, last)` - returns the average value for the range `[first, last)`
- `count_matching(first, last, pred)` - returns number of elements within the range `[first, last)` that fullfill `pred`

## Tests

To build the project run the following commands from within the project's root directory:

```
cmake -S . -B build
cmake --build build
```

Then you can launch the tests by running:

```
ctest
```
