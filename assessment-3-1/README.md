## Description

A vehicle diagnostic engine capable of evaluating different sensor values using configurable diagnostic rules.

`DiagnosticEngine` is the core component of the application. It receives a reading from a specific vehicle sensor and evaluates it based on a provided `DiagnoticRule`. A rule can be generated with the help of `RuleGenerator`, which takes the rule itself as a function and a reference to logging interface (console by default). Based on the result from the rule the engine generates corresponding events with information being written to the specified logging interface.

## Build

Build the application using Bazel:

```
bazel build //assessment-3-1/src:main
```

Then you can launch it by running:

```
./bazel-bin/assessment-3-1/src/main
```

Alternatively, build and run by using the following command:

```
bazel run //assessment-3-1/src:main
```
