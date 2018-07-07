# Nucleus is a python library for reading and writing common genomics
# file formats.
load("//:third_party/clif.bzl", "py_clif_cc", "pyclif_proto_library")
load("@com_google_protobuf//:protobuf.bzl", "py_proto_library")
load("@com_google_protobuf//:protobuf.bzl", "cc_proto_library")

package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # Apache License 2.0

exports_files(["LICENSE"])

py_proto_library(
    name = "range_py_pb2",
    srcs = ["range.proto"],
)

cc_proto_library(
    name = "range_cc_pb2",
    srcs = ["range.proto"],
    # default_runtime = "@protobuf_archive//:protobuf",
    # protoc = "@protobuf_archive//:protoc",
)

proto_library(
    name = "range_proto",
    srcs = ["range.proto"],
)

pyclif_proto_library(
    name = "range_pyclif",
    proto_lib = ":range_proto",  # NO COPYBARA
)

py_binary(
    name = "run",
    srcs = ["run.py"],
    deps = [
    	 ":range_py_pb2",
    ],
)

