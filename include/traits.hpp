#ifndef OC_TRAITS_H
#define OC_TRAITS_H

namespace oc
{

template <class Type, class... Types>
struct variadic_reduce
{
    using type = Type;
};

template <class... Types>
using variadic_reduce_t = variadic_reduce<Types...>::type;

}

#endif