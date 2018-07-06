workspace(name = "prototest")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "protobuf_archive",
    sha256 = "135d1105838932d04be79c06f429250531a73e699bd95aed83489aab9caa8622",
    strip_prefix = "protobuf-2efcec95b6d42e66ada2a14f3fbf38762c52641c",
    urls = [
        # TODO(thomaswc): Restore this URL when it is up on the mirror.
        # "https://mirror.bazel.build/github.com/google/protobuf/archive/a0e82dbe569552ac848d088391b63aaa1108d1a3.tar.gz",
        "https://github.com/cmclean/protobuf/archive/2efcec95b6d42e66ada2a14f3fbf38762c52641c.tar.gz",
    ],
)

http_archive(
      name = "com_google_protobuf",
        sha256 = "135d1105838932d04be79c06f429250531a73e699bd95aed83489aab9caa8622",
        strip_prefix = "protobuf-2efcec95b6d42e66ada2a14f3fbf38762c52641c",
        urls = [
          # TODO(thomaswc): Restore this URL when it is up on the mirror.
          "https://mirror.bazel.build/github.com/google/protobuf/archive/2efcec95b6d42e66ada2a14f3fbf38762c52641c.tar.gz",
          "https://github.com/cmclean/protobuf/archive/2efcec95b6d42e66ada2a14f3fbf38762c52641c.tar.gz",
        ],
  )

http_archive(
      name = "six_archive",
      urls = [
          "https://mirror.bazel.build/pypi.python.org/packages/source/s/six/six-1.10.0.tar.gz",
          "https://pypi.python.org/packages/source/s/six/six-1.10.0.tar.gz",
      ],
      sha256 = "105f8d68616f8248e24bf0e9372ef04d3cc10104f1980f54d57b2ce73a5ad56a",
      strip_prefix = "six-1.10.0",
      build_file = "//third_party:six.BUILD",
  )

bind(
    name = "python_headers",
    actual = "//util/python:python_headers",
)

bind(
    name = "six",
    actual = "@six_archive//:six",
)

