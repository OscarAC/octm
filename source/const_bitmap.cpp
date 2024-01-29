// <octm/con/const_bitmap.hpp>
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
// module;
#include <stddef.h>
#include <stdint.h>
#include <bitset>

// export module octm:const_bitmap;

import :idioms;
import :const_array;

template <size_t N>
struct const_bitmap_limits 
{
    constexpr static size_t bits = (CHAR_BIT * sizeof(size_t));
    constexpr static size_t levels = N / bits + (N % bits == 0 ? 0 : 1);
};

template <size_t L>
struct const_bitmap_mem 
{
  using value_t = size_t;
  using mem_t = const_array<value_t, L>;

  constexpr value_t& get(const size_t i) { return mem_[i]; }

  constexpr void set(size_t i, value_t value) { mem_[i] = value; }

  private:
    value_t mem_[L] = {};
};

struct const_bitmap_value 
{
  using value_t = size_t;    
  using position_t = size_t;

  constexpr const_bitmap_value(value_t* value, position_t position) : mem_(value), pos_(position) {}

  constexpr const_bitmap_value& operator = (bool value) {
    if(value) {
      *mem_ = 1;
    }
    return *this;
  }

  constexpr operator bool() const { return ((*mem_) & pos_); }

  private:
    value_t* mem_;
    position_t pos_;
};

export template <size_t N>
struct const_bitmap : with_const_size<N> 
{
  using array_t = size_t;
  using value_t = uint8_t;
  using limits_t = const_bitmap_limits<N>;
  using mem_t = const_bitmap_mem<limits_t::levels>;

// constexpr const value_type operator[](const size_t i) const noexcept
// {
//     if (i >= N) { return -1; }
//     return mem_.get(i % limits_type::bits) & (1 << i);
// }

  constexpr const_bitmap_value operator[](const size_t i) noexcept {
    return const_bitmap_value(&mem_.get(i % limits_t::bits), i);
  }

  private:
    mem_t mem_;
};
