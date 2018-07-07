# Copyright 2018 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""Profile the cost of calling C++ code from python with CLIF.

Including transferring protos and classes across the language barrier.
"""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import time

from absl import app
from absl import logging

import pandas as pd

from src import range_pb2

from py_cpp_proto.python import cpplib

def main(argv):
  del argv  # Unused.

  print('In main now')

  print('-' * 40)
  print('about to import api_implementation from protos to get version...')
  from google.protobuf.internal import api_implementation
  print('api_implementation.Type() says it uses the {} backend'.format(api_implementation.Type()))
  
  print('-' * 40)
  print('Creating our own range pb instance')
  range_ = range_pb2.Range(reference_name='chr1', start=10, end=20)
  print('range_ is:\n{}'.format(range_))
  
  print('-' * 40)
  print('Calling CLIF C++ wrapper functions')

  print('Calling JustReturnAnInt...')
  result = cpplib.JustReturnAnInt()
  print('Got {}'.format(result))

  print('Calling JustPassInAnInt...')
  result = cpplib.JustPassInAnInt(42)
  print('Got {}'.format(result))

  print('Calling JustPassInProtoPtr...')
  result = cpplib.JustPassInProtoPtr(range_)
  print('Got {}'.format(result))


if __name__ == '__main__':
  app.run(main)
