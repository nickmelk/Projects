## Description

A simple console application that analyzes the current state of a vehicle based its speed and engine temperature.

Input parameters:
- vehicle speed in km/h (acceptable range from 0 to 200)
- engine temperature in degrees Celsius (acceptable range from -40 to 150)

Outputs vehicle status and warnings if present. Warns when speed is greater than 130, and when engine temperature is greater than 105.

## Build

Build the application using Bazel:

```
bazel build //src:main
```

Then you can launch it by running:

```
./bazel-bin/src/main
```
