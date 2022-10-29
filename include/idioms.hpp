#ifndef OC_IDIOM_H
#define OC_IDIOM_H

#include "defs.hpp"

namespace oc
{

template <size_type Size>
struct with_const_size
{
    constexpr size_type size() const noexcept
    {
        return Size;
    }
};


template<class Type>
concept has_size = requires (Type t) {
    t.size();
};

template <size_type Size>
concept size_gt_zero = requires () {
    Size > 0;
};

}

#endif