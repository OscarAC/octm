// <octm/test/assert.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef UTIL_TEST_H
#define UTIL_TEST_H

#include <stdexcept>

#define ASSERT_THROW(condition)                                                                                                                                     \
    {                                                                                                                                                               \
        if (!(condition))                                                                                                                                           \
        {                                                                                                                                                           \
            throw std::runtime_error(std::string(__FILE__) + std::string(":") + std::to_string(__LINE__) + std::string(" in ") + std::string(__PRETTY_FUNCTION__)); \
        }                                                                                                                                                           \
    }

#define ASSERT_EQUAL(x, y)                                                                                                                                                                                                                                \
    {                                                                                                                                                                                                                                                     \
        if ((x) != (y))                                                                                                                                                                                                                                   \
        {                                                                                                                                                                                                                                                 \
            throw std::runtime_error(std::string(__FILE__) + std::string(":") + std::to_string(__LINE__) + std::string(" in ") + std::string(__PRETTY_FUNCTION__) + std::string(": ") + std::to_string((x)) + std::string(" != ") + std::to_string((y))); \
        }                                                                                                                                                                                                                                                 \
    }

#endif