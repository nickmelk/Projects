load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
        "handler.cpp",
        "handler.hpp",
    ],
    copts = [
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-std=c++17",
    ],
)
