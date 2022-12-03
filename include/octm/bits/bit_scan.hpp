// <octm/bits/bit_scan.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef OCTM_BIT_SCAN_H
#define OCTM_BIT_SCAN_H

#include "../types.hpp"

namespace oc::fn {

constexpr uint8_t debruijn_seq[64] = {0, 1, 2, 53, 3, 7, 54, 27,
                                      4, 38, 41, 8, 34, 55, 48, 28,
                                      62, 5, 39, 46, 44, 42, 22, 9,
                                      24, 35, 59, 56, 49, 18, 29, 11,
                                      63, 52, 6, 26, 37, 40, 33, 47,
                                      61, 45, 43, 21, 23, 58, 17, 10,
                                      51, 25, 36, 32, 60, 20, 57, 16,
                                      50, 31, 19, 15, 30, 14, 13, 12};

/**
 * @brief Bit scan forward
 * @param target - the value on which to perform the scan
 * @return the result of the scan
 */
constexpr int8_t bit_scan_forward(uint64_t value)
{
    if (!value) {
        return -1;
    }
    return debruijn_seq[((value & -value) * 0x022fdd63cc95386dUL >> 58)];
}


/**
 * @brief Bit scan reverse
 * @param target - the value on which to perform the scan
 * @return the result of the scan
 */
constexpr int8_t bit_scan_reverse(uint64_t value)
{
    if (!value) {
        return -1;
    }
    if(value >= 0x8000000000000000UL) {
        return 63;
    }

    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value |= value >> 32;
    value++;
    return debruijn_seq[((value * 0x022fdd63cc95386dUL) >> 58)] - 1;
}

namespace x64 {

/**
 * @brief Bit scan forward for using the x64 BSF instruction
 * @param target - the value on which to perform the scan
 * @return the result of the scan
 */
inline int64_t bit_scan_forward(uint64_t target)
{
    if (!target) {
        return -1;
    }

    int64_t result;
    __asm__ __volatile__("bsf %0, %1"
                         : "=r"(result)
                         : "r"(target));
    return result;
}

/**
 * @brief Bit scan reverse for using the x64 BSR instruction
 * @param target - the value on which to perform the scan
 * @return the result of the scan
 */
inline int64_t bit_scan_reverse(uint64_t target)
{
    if (!target) {
        return -1;
    }

    int64_t result;
    __asm__ __volatile__("bsr %0, %1"
                         : "=r"(result)
                         : "r"(target));
    return result;
}

}
}

#endif