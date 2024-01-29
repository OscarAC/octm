// <octm/assert.hpp>
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
module;
#include <stdio.h>
#include <stdlib.h>

export module octm:assert;

static inline void test_assert_print_and_abort(const char * file, unsigned int line)
{
  fprintf(stderr, "test failed: %s:%d\n", file, line);
  abort();
}

export inline void test_assert(bool expr) {
  expr ? void(0) : test_assert_print_and_abort(__FILE__, __LINE__);
}

