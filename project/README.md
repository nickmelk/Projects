## Description

TODO

## Build

Generate source code from the protobuf file:

```
mkdir gen
protoc --cpp_out=gen/ --python_out=gen/ schema.proto
```

Build the application using Bazel:

```
bazel build //project:udp_client
```

Launch the server and the client:

```
python3 udp_server.py
./bazel-bin/project/udp_client
```
