## Description

TODO

## Build

Generate source code from the protobuf file:

```
mkdir src/udp_client/gen/ && mkdir src/udp_server/gen/
protoc --cpp_out=src/udp_client/gen/ schema.proto
protoc --python_out=src/udp_server/gen/ schema.proto
```

Build the application using Bazel:

```
bazel build //project:udp_client
```

Launch the server and the client:

```
python3 src/udp_server/udp_server.py
./bazel-bin/project/udp_client
```
