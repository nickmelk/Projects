load("@rules_cc//cc:cc_binary.bzl", "cc_binary")
load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
        "vehicle_data.cpp",
        "constants.h",
        "vehicle_data.h",
    ],
    copts = [
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-std=c++17",
    ],
)

cc_library(
    name = "vehicle_data",
    srcs = ["vehicle_data.cpp"],
    hdrs = [
        "constants.h",
        "vehicle_data.h",
    ],
    copts = [
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-std=c++17",
    ],
    visibility = ["//visibility:public"],
)
