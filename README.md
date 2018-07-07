# prototest

## Getting bazel to build with python protocol buffer

```shell
gcloud beta compute instances create "${USER}-py-protobuf-bazel"  \
--scopes "compute-rw,storage-full,cloud-platform" \
--image-family "ubuntu-1604-lts" --image-project "ubuntu-os-cloud" \
--machine-type "n1-standard-16" \
--boot-disk-size "300" --boot-disk-type "pd-ssd" \
--zone "us-west1-b"

gcloud compute ssh ${USER}-py-protobuf-bazel

# Update our machine
sudo apt-get update
sudo apt-get install -y unzip gcc g++ python-dev

# Install bazel
BAZEL_VERSION=0.15.0
curl -L -O https://github.com/bazelbuild/bazel/releases/download/"${BAZEL_VERSION}"/bazel-"${BAZEL_VERSION}"-installer-linux-x86_64.sh
chmod +x bazel-*.sh
./bazel-"${BAZEL_VERSION}"-installer-linux-x86_64.sh --user
rm bazel-"${BAZEL_VERSION}"-installer-linux-x86_64.sh

git clone https://github.com/depristo/prototest.git

cd prototest

# Running this command will pass as we are using the python only version of protobufs.
bazel clean
bazel build -c opt src:run
./bazel-bin/src/run

# Now let's run with fast cpp protos, which should also pass and say it's using cpp backend.
bazel clean
bazel build -c opt --define=use_fast_cpp_protos=true src:run
./bazel-bin/src/run
```

## Getting it all working with CLIF

Note that I've already ./install.sh from nucleus here in order to get clif. TODO is to simplify the system further so we only have the bare-minimum todo.

```
$ bazel clean
$ bazel build -c opt --define=use_fast_cpp_protos=true py_cpp_proto:run_benchmark

$ ./bazel-bin/py_cpp_proto/run_benchmark
In main now
----------------------------------------
about to import api_implementation from protos to get version...
api_implementation.Type() says it uses the cpp backend
----------------------------------------
Creating our own range pb instance
range_ is:
reference_name: "chr1"
start: 10
end: 20

----------------------------------------
Calling CLIF C++ wrapper functions
Calling JustReturnAnInt...
Got 3
Calling JustPassInAnInt...
Got None
Calling JustPassInProtoPtr...
Traceback (most recent call last):
  File "/home/mdepristo/prototest/bazel-bin/py_cpp_proto/run_benchmark.runfiles/prototest/py_cpp_proto/run_benchmark.py", line 66, in <module>
      app.run(main)
  File "/home/mdepristo/.local/lib/python2.7/site-packages/absl/app.py", line 274, in run
      _run_main(main, args)
  File "/home/mdepristo/.local/lib/python2.7/site-packages/absl/app.py", line 238, in _run_main
       sys.exit(main(argv))
  File "/home/mdepristo/prototest/bazel-bin/py_cpp_proto/run_benchmark.runfiles/prototest/py_cpp_proto/run_benchmark.py", line 61, in main
       result = cpplib.JustPassInProtoPtr(range_)
RuntimeError: JustPassInProtoPtr() argument range is not valid: Dynamic cast to protobuf sub-type failed
```

So we can reproduce the dynamic cast failure without really any deps. We don't have multiple versions of protobufs any longer (only one is com_google_protobuf). This points to our most recently patched files. So we need to only figure this all out.