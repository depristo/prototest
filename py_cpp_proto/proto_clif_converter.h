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
 *
 */
#ifndef THIRD_PARTY_NUCLEUS_UTIL_PROTO_CLIF_CONVERTER_H_
#define THIRD_PARTY_NUCLEUS_UTIL_PROTO_CLIF_CONVERTER_H_

#include <typeinfo>

#include "clif/python/types.h"
#include "google/protobuf/message.h"
#include "python/google/protobuf/proto_api.h"
#include "py_cpp_proto/proto_ptr.h"
// #include "tensorflow/core/platform/logging.h"

namespace clif {

// Note: the comments below are instructions to CLIF.
// CLIF use `nucleus::EmptyProtoPtr` as EmptyProtoPtr
// CLIF use `nucleus::ConstProtoPtr` as ConstProtoPtr

const proto2::python::PyProto_API* GetPyProtoApi(PyObject* py);

// Convert from Python protocol buffer object py to a C++ pointer.
// Unlike the conversions that CLIF automatically generates for protocol
// buffers, this one does no copying if the Python protocol buffer uses
// the C++ memory layout.
template <typename T>
bool Clif_PyObjAs(PyObject* py, nucleus::EmptyProtoPtr<T>* c) {
  // CHECK(c != nullptr);

  auto* py_proto_api = GetPyProtoApi(py);
  if (py_proto_api == nullptr) {
    PyErr_SetString(PyExc_RuntimeError, "Could not load PyProto API");
    return false;
  }

  ::proto2::Message* cpb = py_proto_api->GetMutableMessagePointer(py);
  if (cpb == nullptr) {
    // Clients might depend on our non-copying semantics, so we can't fall
    // back on CLIF here but instead must fail loudly.
    PyErr_SetString(PyExc_RuntimeError,
                    "Python protobuf did not contain a mutable C++ protobuf");
    return false;
  } else {
    c->p_ = dynamic_cast<T*>(cpb);
    return true;
  }
}

// Convert from Python protocol buffer object py to a C++ pointer.
// Unlike the conversions that CLIF automatically generates for protocol
// buffers, this one does no copying if the Python protocol buffer uses
// the C++ memory layout.
template <typename T>
bool Clif_PyObjAs(PyObject* py, nucleus::ConstProtoPtr<T>* c) {
  // CHECK(c != nullptr);

  auto* py_proto_api = GetPyProtoApi(py);
  if (py_proto_api == nullptr) {
    PyErr_SetString(PyExc_RuntimeError, "Could not load PyProto API");
    return false;
  }

  const ::proto2::Message* cpb = py_proto_api->GetMessagePointer(py);
  if (cpb == nullptr) {
    // Clients might depend on our non-copying semantics, so we can't fall
    // back on CLIF here but instead must fail loudly.
    PyErr_SetString(PyExc_RuntimeError,
                    "Python protobuf did not contain a C++ protobuf");
    return false;
  } else {
    // LOG(INFO) << "Type of *cpb = " << typeid(*cpb).name();
    c->p_ = dynamic_cast<T*>(cpb);
    // LOG(INFO) << "dynamic_cast<T*>(cpb) = " << c->p_;
    if (c->p_ == nullptr) {
      PyErr_SetString(PyExc_RuntimeError,
                      "Dynamic cast to protobuf sub-type failed");
      return false;
    }
    return true;
  }
}

}  // namespace clif
#endif  // THIRD_PARTY_NUCLEUS_UTIL_PROTO_CLIF_CONVERTER_H_
