load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
        "dengine/diagnostic_engine.cpp",
        "dengine/diagnostic_event.cpp",
        "dengine/diagnostic_rule.cpp",
        "dengine/logger.cpp",
        "dengine/sensor_reading.cpp",
        "dengine/constants.h",
        "dengine/diagnostic_engine.h",
        "dengine/diagnostic_event.h",
        "dengine/diagnostic_rule.h",
        "dengine/logger.h",
        "dengine/sensor_reading.h",
    ],
    copts = [
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-std=c++17",
    ],
)
