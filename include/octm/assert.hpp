// <octm/assert.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef OCTM_ASSERT_H
#define OCTM_ASSERT_H

#include <stdio.h>
#include <stdlib.h>

#define test_assert(expr) (static_cast<bool>(expr) ? void(0) : oc::tm::test_assert_print_and_abort(__FILE__, __LINE__))

namespace oc::tm
{
    static inline void test_assert_print_and_abort(const char * file, unsigned int line)
    {
        fprintf(stderr, "test failed: %s:%d\n", file, line);
        abort();
    }
}


#endif