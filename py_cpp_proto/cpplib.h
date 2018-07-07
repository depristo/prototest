/*
 * Copyright 2018 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef EXPERIMENTAL_USERS_MDEPRISTO_PY_CPP_PROTO_CPPLIB_H_
#define EXPERIMENTAL_USERS_MDEPRISTO_PY_CPP_PROTO_CPPLIB_H_

#include "src/range.pb.h"
#include "py_cpp_proto/proto_ptr.h"

int JustReturnAnInt();
void JustPassInAnInt(int value);

void JustPassInProtoPtr(
   const nucleus::ConstProtoPtr<const ::src::Range>& range);

#endif  // EXPERIMENTAL_USERS_MDEPRISTO_PY_CPP_PROTO_CPPLIB_H_
