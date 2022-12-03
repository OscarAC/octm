// <octm/types.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef OCTM_TYPES_H
#define OCTM_TYPES_H

#include <memory>
#include <stdint.h>

namespace oc
{
using ::int16_t;
using ::int32_t;
using ::int64_t;
using ::int8_t;
using ::uint16_t;
using ::uint32_t;
using ::uint64_t;
using ::uint8_t;
using std::size_t;
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
}

#endif