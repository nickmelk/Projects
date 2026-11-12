load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "udp_client",
    srcs = [
        "main.cpp",
        "src/udp_client.cpp",
        "src/socket_handler.cpp",
        "gen/schema.pb.cpp",
        "src/constants.h",
        "src/packet.h",
        "src/socket_handler.h",
        "src/udp_client.h",
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
