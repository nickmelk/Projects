load("@rules_cc//cc:cc_test.bzl", "cc_test")

cc_test(
    name = "test",
    size = "small",
    srcs = ["test.cpp"],
    deps = [
        "//assessment-2/src:vehicle_data",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
