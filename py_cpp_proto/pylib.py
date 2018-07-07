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
"""TODO(mdepristo): DO NOT SUBMIT without one-line documentation for python.

TODO(mdepristo): DO NOT SUBMIT without a detailed description of python.
"""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

# from nucleus.protos import cigar_pb2


# REF_ADVANCING_OPS = frozenset([
#     cigar_pb2.CigarUnit.ALIGNMENT_MATCH, cigar_pb2.CigarUnit.SEQUENCE_MATCH,
#     cigar_pb2.CigarUnit.DELETE, cigar_pb2.CigarUnit.SKIP,
#     cigar_pb2.CigarUnit.SEQUENCE_MISMATCH
# ])


# def read_end(read):
#   return sum(unit.operation_length
#              for unit in read.alignment.cigar
#              if unit.operation in REF_ADVANCING_OPS)
