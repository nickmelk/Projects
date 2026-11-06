## Description

A generic signal validator that provides the following functionality:

- `SignalValidator<T, Min, Max>` - a generic signal validator used to validate values of type `T`
- `SignalValidator<T, Min, Max>::validate(value)` - checks whether `value` is within the range `[Min, Max]`

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
