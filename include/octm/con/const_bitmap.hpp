// <octm/con/const_bitmap.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef OCTM_CON_CONST_BITMAP_H
#define OCTM_CON_CONST_BITMAP_H

#include "../idioms.hpp"
#include "const_array.hpp"

#include <bitset>

namespace oc::cn {

namespace _ {
template <size_t N>
struct const_bitmap_limits {
    constexpr static size_t bits = (CHAR_BIT * sizeof(size_t));
    constexpr static size_t levels = N / bits + (N % bits == 0 ? 0 : 1);
};

template <size_t L>
struct const_bitmap_mem {

    using value_type = size_t;
    using mem_type = const_array<value_type, L>;

    constexpr value_type& get(const size_t i)
    {
        return mem_[i];
    }

    constexpr void set(size_t i, value_type value)
    {
        mem_[i] = value;
    }

  private:
    value_type mem_[L] = {};
};
}

struct const_bitmap_value {
    using value_type = size_t;    
    using position_type = size_t;

    const_bitmap_value(value_type* value, position_type position) : mem_(value), pos_(position) {}

    constexpr const_bitmap_value& operator = (bool value) {
        if(value) {
            *mem_ = 1;
        }
        return *this;
    }

    constexpr operator bool() const {
        return ((*mem_) & pos_);
    }

  private:
    value_type* mem_;
    position_type pos_;
};

template <size_t N>
struct const_bitmap : with_const_size<N> {

    using array_type = size_t;
    using value_type = uint8_t;
    using limits_type = _::const_bitmap_limits<N>;
    using mem_type = _::const_bitmap_mem<limits_type::levels>;

    // constexpr const value_type operator[](const size_t i) const noexcept
    // {
    //     if (i >= N) { return -1; }
    //     return mem_.get(i % limits_type::bits) & (1 << i);
    // }

    constexpr const_bitmap_value operator[](const size_t i) noexcept
    {
        return const_bitmap_value(&mem_.get(i % limits_type::bits), i);
    }

  private:
    mem_type mem_;
};
}

#endif