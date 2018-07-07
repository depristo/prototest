package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # Apache License 2.0

cc_library(
    name = "proto_ptr",
    hdrs = [
        "proto_ptr.h",
    ],
    deps = [
    ],
)

cc_library(
    name = "proto_clif_converter",
    srcs = ["proto_clif_converter.cc"],
    hdrs = ["proto_clif_converter.h"],
    deps = [
        ":proto_ptr",
        "@clif//:cpp_runtime",
        "@com_google_protobuf//:protobuf",
        "@com_google_protobuf//:proto_api",
    ],
)

cc_library(
    name = "cpplib",
    srcs = ["cpplib.cc"],
    hdrs = ["cpplib.h"],
    deps = [
        ":proto_ptr",
        "//src:range_cc_pb2",
    ],
)

py_binary(
    name = "run_benchmark",
    srcs = ["run_benchmark.py"],
    deps = [
        "//src:range_py_pb2",
        "//py_cpp_proto/python:cpplib",
    ],
)
