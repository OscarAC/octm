// <octm/assert.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef OCTM_TEST_ASSERT_H
#define OCTM_TEST_ASSERT_H

#include <stdio.h>
#include <stdlib.h>

#define TEST_ASSERT(expr) (static_cast<bool>(expr) ? void(0) : oc::ts::test_assert_print_and_abort(__FILE__, __LINE__))

namespace oc::ts
{
    static inline void test_assert_print_and_abort(const char * file, unsigned int line)
    {
        fprintf(stderr, "test failed: %s:%d\n", file, line);
        abort();
    }
}


#endif