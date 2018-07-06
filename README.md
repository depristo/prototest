# prototest
Protocol buffers in python

```shell
$ bazel clean
$ bazel run -c opt src:run
INFO: Analysed target //src:run (0 packages loaded).
INFO: Found 1 target...
Target //src:run up-to-date:
  bazel-bin/src/run
INFO: Elapsed time: 0.254s, Critical Path: 0.00s
INFO: Build completed successfully, 1 total action

INFO: Running command line: bazel-bin/src/run
----------------------------------------
----------------------------------------
----------------------------------------
hello, this is the first line of run.py
About to import range_pb...
Traceback (most recent call last):
  File "/home/mdepristo/.cache/bazel/_bazel_mdepristo/0f8f0bfaed356643dac218dc395f610b/execroot/prototest/bazel-out/k8-opt/bin/src/run.runfiles/prototest/src/run.py", line 12, in <module>
    from src import range_pb2
  File "/home/mdepristo/.cache/bazel/_bazel_mdepristo/0f8f0bfaed356643dac218dc395f610b/execroot/prototest/bazel-out/k8-opt/bin/src/run.runfiles/prototest/src/range_pb2.py", line 6, in <module>
    from google.protobuf import descriptor as _descriptor
ImportError: No module named protobuf
ERROR: Non-zero return code '1' from command: Process exited with status 1
```
