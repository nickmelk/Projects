## Description

TODO

## Build

Generate source code from the protobuf file:

```
mkdir gen
protoc --cpp_out=gen/ --python_out=gen/ schema.proto
```
