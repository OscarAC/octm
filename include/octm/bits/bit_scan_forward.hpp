// <octm/bits/bit_scan_forward.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef OCTM_BIT_SCAN_FORWARD_H
#define OCTM_BIT_SCAN_FORWARD_H

#include "../types.hpp"

namespace oc::fn {

constexpr int32_t debruijn_seq[32] = {
    0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
    31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9};

/**
 * @brief Bit scan forward for 32 bit words
 * @param target - the value on which to perform the scan
 * @return the result of the scan
 */
constexpr int32_t bit_scan_forward(uint32_t value)
{
    if (!value) {
        return -1;
    }
    return debruijn_seq[(( (value & (-static_cast<uint32_t>(value))) * 0x077CB531ULL) & 0xFFFFFFFF) >> 27];
}

/**
 * @brief Bit scan forward for 64 bit words
 * @param target - the value on which to perform the scan
 * @return the result of the scan
 */
inline constexpr int64_t bit_scan_forward(uint64_t target)
{
    if (!target) {
        return -1;
    }
    uint32_t h = (uint32_t)(target >> 32);
    uint32_t bits = 0;

    if (h && !((uint32_t)target)) {
        bits = 32 + bit_scan_forward(h);
    }
    else {
        bits = bit_scan_forward((uint32_t)target & 0xFFFFFFFF);
    }

    return bits;
}

namespace x64 {

/**
 * @brief Bit scan forward for 32 bit words using x86 BSF instruction
 * @param target - the value on which to perform the scan
 * @return the result of the scan
 */
inline int32_t bit_scan_forward(uint32_t target)
{
    int32_t result;
    __asm__ __volatile__("bsf %0, %1"
                         : "=r"(result)
                         : "r"(target));
    return result;
}

/**
 * @brief Bit scan forward for 64 bit words using x64 BSF instruction
 * @param target - the value on which to perform the scan
 * @return the result of the scan
 */
inline int64_t bit_scan_forward(uint64_t target)
{
    int64_t result;
    __asm__ __volatile__("bsf %0, %1"
                         : "=r"(result)
                         : "r"(target));
    return result;
}

}

}

#endif