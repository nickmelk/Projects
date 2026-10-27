load("@rules_cc//cc:cc_test.bzl", "cc_test")

cc_test(
    name = "vehicle_data_test",
    size = "small",
    srcs = [
        "vehicle_data_test.cpp",
    ],
    deps = [
        "//assessment-1-2/lib:vehicle_data",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
