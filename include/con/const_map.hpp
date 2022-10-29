#ifndef OC_CN_STATIC_MAP_H
#define OC_CN_STATIC_MAP_H

#include "../idioms.hpp"
#include "const_array.hpp"
#include "hash.hpp"

namespace oc::cn
{
template <class Value, class Key, size_type Size>
struct const_map : with_const_size<Size>
{
    using value_type = Value;

  private:
    const_array<value_type, Size> mem_;
};
}

#endif