## Description

A simple project that consists of a client and a server communicating through the UDP protocol. The Python server generates random sensor readings and sends them in Protobuf format through a socket. The C++ client receives messages from the server, processes them, and logs results to the console. The client's work is divided between two threads: a receiver (main) and a processor. The receiver is responsible for receiving and storing messages from the server. The processor is responsible for processing messages and logging results to the console.

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

## Usage

Launch the server and the client:

```
python3 src/udp_server/udp_server.py
./bazel-bin/project/udp_client
```
