// <octm/arrays.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef OCTM_ARRAY_H
#define OCTM_ARRAY_H

#include "idioms.hpp"
#include "types.hpp"
#include <initializer_list>
#include <utility>

namespace oc::cn {

template <class T, size_t N>
struct const_array final : with_const_size<N> {
    using value_type = T;

    template <size_t TN, size_t... I>
    constexpr const_array(T const (&arr)[N], std::index_sequence<I...>) : mem_{arr[I]...}
    {
    }

    template <class It, size_t... I>
    constexpr const_array(It iterator, std::index_sequence<I...>) : mem_{((void)I, *iterator++)...}
    {
    }

    constexpr const_array(std::initializer_list<T> list)
        : const_array(list.begin(), std::make_index_sequence<N>())
    {
    }

    constexpr const_array(T const (&arr)[N])
        : const_array(arr, std::make_index_sequence<N>())
    {
    }

    constexpr const T &
    operator[](const size_t I) const noexcept
    {
        return mem_[I];
    }

    constexpr operator const T &() const noexcept
    {
        return mem_;
    }

    template <size_t I>
    constexpr const T &
    get() const
    {
        static_assert(I < N);
        return mem_[I];
    }

  private:
    T mem_[N] = {};
};

template <class... T>
const_array(T... type) -> const_array<variadic_reduce_t<T...>,
                                      sizeof...(T)>;
}

#endif
