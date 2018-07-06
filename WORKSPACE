workspace(name = "nucleus")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Abseil libraries
# git_repository(
#     name = "io_abseil_py",
#     tag = "pypi-v0.2.2",
#     remote = "https://github.com/abseil/abseil-py.git",
# )
# Note: com_google_absl (the C++ abseil library) is provided by TensorFlow.

# We need a protobuf version at this hash or later because we need the API
# introduced in
# https://github.com/google/protobuf/pull/4698 with bug fix at
# https://github.com/google/protobuf/pull/4725
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

# http_archive(
#     name = "six_archive",
#     build_file = "//third_party:six.BUILD",
#     sha256 = "105f8d68616f8248e24bf0e9372ef04d3cc10104f1980f54d57b2ce73a5ad56a",
#     urls = ["https://pypi.python.org/packages/source/s/six/six-1.10.0.tar.gz#md5=34eed507548117b2ab523ab14b2f8b55"],
# )

http_archive(
    name = "bazel_skylib",
        sha256 = "bbccf674aa441c266df9894182d80de104cabd19be98be002f6d478aaa31574d",
	    strip_prefix = "bazel-skylib-2169ae1c374aab4a09aa90e65efe1a3aad4e279b",
	        urls = ["https://github.com/bazelbuild/bazel-skylib/archive/2169ae1c374aab4a09aa90e65efe1a3aad4e279b.tar.gz"],
		)

bind(
    name = "python_headers",
        actual = "//util/python:python_headers",
	)

bind(
    name = "gtest",
        actual = "@submodule_gmock//:gtest",
	)

bind(
    name = "gtest_main",
        actual = "@submodule_gmock//:gtest_main",
	)

bind(
    name = "six",
        actual = "@six_archive//:six",
	)

maven_jar(
    name = "guava_maven",
        artifact = "com.google.guava:guava:18.0",
	)

bind(
    name = "guava",
        actual = "@guava_maven//jar",
	)

maven_jar(
    name = "gson_maven",
        artifact = "com.google.code.gson:gson:2.7",
	)

bind(
    name = "gson",
        actual = "@gson_maven//jar",
	)



# # Import all of the tensorflow dependencies.
# load("@org_tensorflow//tensorflow:workspace.bzl", "tf_workspace")

# tf_workspace(tf_repo_name = "org_tensorflow")

# new_local_repository(
#     name = "clif",
#     build_file = "third_party/clif.BUILD",
#     path = "/usr/local",
# )
