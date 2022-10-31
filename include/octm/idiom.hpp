// <octm/idiom.hpp>
// 10/15/2022 - File Creation
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef OCTM_IDIOM_H
#define OCTM_IDIOM_H

namespace oc
{

#define constexpr_ constexpr
#define inline_ inline
#define static_assert_ static_assert

using no_type = struct {};
using size_t = unsigned long int;

template <size_t N>
struct with_const_size
{
    inline_ constexpr_ size_t size() const noexcept
    {
        return N;
    }
};


template<class T>
concept has_size = requires (T t) {
    t.size();
};

template <size_t N>
concept size_gt_zero = requires () {
    N > 0;
};

template<class T>
concept is_pair = requires(T t) {
    t.left;
    t.right;
};


template <class Type, class... Types>
struct variadic_reduce
{
    // TODO assert Type == Types..
    using type = Type;
};

template <class... Types>
using variadic_reduce_t = variadic_reduce<Types...>::type;


}

#endif