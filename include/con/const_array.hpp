#ifndef OC_CN_STATIC_ARRAY_H
#define OC_CN_STATIC_ARRAY_H

#include "../idioms.hpp"
#include "../traits.hpp"

namespace oc::cn
{

namespace _
{
template <class Type, size_type Size>
struct const_array_helper
{
    using value_type = Type;
    using array_type = Type[Size];

    static constexpr value_type &Get(const array_type &array, size_type index)
    {
        return const_cast<value_type &>(array[index]);
    }
};

template <class Type>
struct const_array_helper<Type, 0>
{
    using value_type = Type;
    using array_type = no_type;

    static constexpr value_type &Get(const array_type &array, size_type index)
    {
        return *static_cast<value_type*>(nullptr);
    }
};
}

template <class Type, size_type Size>
struct const_array final
{
    using _helper = _::const_array_helper<Type, Size>;
    using value_type = _helper::value_type;
    using array_type = _helper::array_type;

    constexpr const value_type &operator[](const size_type index) const noexcept    
    {
        return _helper::Get(mem_, index);
    }

    constexpr operator const array_type&() const noexcept
    {
        return mem_;
    }

    template <size_type Index>
    constexpr const value_type& get() const
    {
        return _helper::Get(mem_, Index);
    }

    constexpr size_type size() const noexcept
    {
        return Size;
    }

    array_type mem_;
};

template <class... Type>
const_array(Type... type) -> const_array<variadic_reduce_t<Type...>,
                                         sizeof...(Type)>;
}

#endif
