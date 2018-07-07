workspace(name = "prototest")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Recent release version; doens't have proto_api
# http_archive(
#   name = "com_google_protobuf",
#   sha256 = "56541023a5dfa05de7dd5b7856bfd370047d6b93718eba068b43d1a4092b6cb6",
#   strip_prefix = "protobuf-ab8edf1dbe2237b4717869eaab11a2998541ad8d",
#   urls = [
#     "https://github.com/google/protobuf/archive/ab8edf1dbe2237b4717869eaab11a2998541ad8d.tar.gz",
#   ],
# )

http_archive(
  name = "com_google_protobuf",
  sha256 = "91a1f9f0e2995e88751e9dba5703e293c25e26c653935b236ea721f7f1401d7d",
  strip_prefix = "protobuf-df9ff6b90ec31bf54d765bd49e47f13e96a6300d",
  urls = [
    "https://github.com/depristo/protobuf/archive/df9ff6b90ec31bf54d765bd49e47f13e96a6300d.tar.gz",
  ],
)


# local_config_python gets us a path to the Python.h for building the C++ protobuf backend for Python.
new_local_repository(
    name = "local_config_python",
    path = "/usr/include",
    build_file_content = """
cc_library(  
    name = "python_headers",
    hdrs = glob(["python2.7/*.h"]),
    includes = ["python2.7/"],
    visibility = ["//visibility:public"]
)
    """
)

bind(
    name = "python_headers",
    actual = "@local_config_python//:python_headers",
)

new_http_archive(
      name = "six_archive",
      urls = [
          "https://mirror.bazel.build/pypi.python.org/packages/source/s/six/six-1.10.0.tar.gz",
          "https://pypi.python.org/packages/source/s/six/six-1.10.0.tar.gz",
      ],
      sha256 = "105f8d68616f8248e24bf0e9372ef04d3cc10104f1980f54d57b2ce73a5ad56a",
      strip_prefix = "six-1.10.0",
      build_file_content = """
py_library(
    name = "six",
    srcs = ["six.py"],
    visibility = ["//visibility:public"],
)
    """
)

bind(
    name = "six",
    actual = "@six_archive//:six",
)

new_local_repository(
    name = "clif",
    build_file = "third_party/clif.BUILD",
    path = "/usr/local",
)
