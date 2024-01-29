// <octm/idioms.hpp>
// Copyright(c) 2022-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
module;
#include <stdint.h>
#include <stddef.h>

export module octm:idioms;

export template <size_t N>
struct with_const_size
{
    inline constexpr size_t size() const noexcept { return N; }
};

export template<class T>
concept has_size = requires (T t) { t.size(); };

export template <size_t N>
concept size_gt_zero = requires () { N > 0; };


// TODO assert Type == Types..
export template <class Type, class... Types>
struct variadic_reduce
{    
    using type = Type;
};

template <class... Types>
using variadic_reduce_t = variadic_reduce<Types...>::type;
