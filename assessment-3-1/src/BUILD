load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
        "dengine/file_handler.cpp",
        "dengine/logger_interface.cpp",
        "dengine/constants.h",
        "dengine/diagnostic_engine.h",
        "dengine/diagnostic_rule.h",
        "dengine/file_handler.h",
        "dengine/logger_interface.h",
        "dengine/sensor_reading.h",
    ],
    copts = [
        "-fdiagnostics-color=always",
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-std=c++17",
    ],
)
