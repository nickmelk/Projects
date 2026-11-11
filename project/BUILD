load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "udp_client",
    srcs = [
        "udp_client.cpp",
        "src/socket_handler.cpp",
        "gen/schema.pb.cpp",
        "src/constants.h",
        "src/socket_handler.h",
        "gen/schema.pb.h",
    ],
    copts = [
        "-fdiagnostics-color=always",
        "-std=c++17",
    ],
    deps = [
        "@protobuf//:protobuf",
    ],
)
