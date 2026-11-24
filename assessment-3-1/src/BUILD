load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
        "dengine/file_handler.cpp",
        "dengine/logger_interface.cpp",
        "dengine/constants.hpp",
        "dengine/diagnostic_engine.hpp",
        "dengine/diagnostic_rule.hpp",
        "dengine/file_handler.hpp",
        "dengine/logger_interface.hpp",
        "dengine/sensor_reading.hpp",
    ],
    copts = [
        "-fdiagnostics-color=always",
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-std=c++17",
    ],
)
