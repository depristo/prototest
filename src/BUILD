# Nucleus is a python library for reading and writing common genomics
# file formats.
load("@protobuf_archive//:protobuf.bzl", "py_proto_library")
load("@protobuf_archive//:protobuf.bzl", "cc_proto_library")

package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # Apache License 2.0

exports_files(["LICENSE"])

proto_library(
    name = "range_proto",
    srcs = ["range.proto"],
)

# TODO(mdepristo): everyone needs to use this style.
# TODO(mdepristo): use our own cc_proto_rule that adds this boilerplate.
cc_proto_library(
    name = "range_cc_pb2",
    srcs = ["range.proto"],
    default_runtime = "@protobuf_archive//:protobuf",
    protoc = "@protobuf_archive//:protoc",
)

py_proto_library(
    name = "range_py_pb2",
    srcs = ["range.proto"],
    default_runtime = "@protobuf_archive//:protobuf_python",
    protoc = "@protobuf_archive//:protoc",
)

py_binary(
    name = "run",
    srcs = ["run.py"],
    deps = [
    	 ":range_py_pb2",
    ],
)

