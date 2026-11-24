load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
        "speed_data.cpp",
        "constants.hpp",
        "speed_data.hpp",
    ],
    copts = [
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-std=c++17",
    ],
)
