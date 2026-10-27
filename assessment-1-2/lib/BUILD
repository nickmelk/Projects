load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_library(
    name = "vehicle_data",
    srcs = [
        "vehicle_data.cpp",
    ],
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
