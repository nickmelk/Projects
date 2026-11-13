load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "udp_client",
    srcs = glob([
        "src/udp_client/*.cpp",
        "src/udp_client/*.h",
        "src/udp_client/gen/*.cpp",
        "src/udp_client/gen/*.h",
    ]),
    copts = [
        "-fdiagnostics-color=always",
        "-std=c++17",
    ],
    deps = [
        "@protobuf//:protobuf",
    ],
)
