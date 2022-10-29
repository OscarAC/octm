#ifndef OC_CN_PAIR_H
#define OC_CN_PAIR_H

#include "../idioms.hpp"

namespace oc::cn
{

/**
 * Pair is an aggregate type of two objects.
 * 
 * 
 * @brief  Pair of objects.
 */
template <class LType, class RType>
struct pair
{
    using left_type = LType;
    using right_type = RType;
    
    left_type left;
    right_type right;
};

}

#endif