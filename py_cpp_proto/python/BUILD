load("//:third_party/clif.bzl", "py_clif_cc")

package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # Apache License 2.0

py_clif_cc(
    name = "cpplib",
    srcs = ["cpplib.clif"],
    pyclif_deps = [
        "//src:range_pyclif",
    ],
    deps = [
        "//py_cpp_proto:cpplib",
        "//py_cpp_proto:proto_clif_converter",
    ],
)
