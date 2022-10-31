#ifndef OCTM_MAP_H
#define OCTM_MAP_H

#include "array.hpp"

namespace oc::tm
{
template <class K, class V, size_t N>
struct const_map : with_const_size<N>
{
};
}

#endif