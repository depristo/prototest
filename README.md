# prototest
Protocol buffers in python

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
