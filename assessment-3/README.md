## Description

A simple console application that calculates statistics for a sequence of recorded vehicle speeds.

Input parameters:
- a sequence of numbers representing vehicle speed (acceptable range from 0 to 200)

Output:
- minimum, maximum, and average speed of all valid data that was entered
- overspeed measurements, number and average speed of overspeed measurements

## Build

Build the application using Bazel:

```
bazel build //src:main
```

Then you can launch it by running:

```
./bazel-bin/src/main
```
