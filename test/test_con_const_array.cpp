#include <octm/con/const_array.hpp>
#include <octm/test/assert.hpp>

using namespace oc::cn;
using namespace oc::ts;

void test_constexpr_initializer()
{
    constexpr const_array<int, 0> a1 = {};
    constexpr const_array a3 = {1, 2, 3};
    constexpr const_array a4{1, 2, 3, 4};

    static_assert(a1.size() == 0);
    static_assert(a3.size() == 3);
    static_assert(a4.size() == 4);
}

void test_constexpr_get()
{
    constexpr const_array a1{'a', 'b', 'c', 'd'};
    static_assert(a1.get<0>() == 'a');
    static_assert(a1.get<1>() == 'b');
    static_assert(a1.get<2>() == 'c');
    static_assert(a1.get<3>() == 'd');
    static_assert(a1[0] == 'a');
    static_assert(a1[1] == 'b');
    static_assert(a1[2] == 'c');
    static_assert(a1[3] == 'd');

    constexpr const_array a2{1, 2, 3, 4};
    static_assert(a2.get<0>() == 1);
    static_assert(a2.get<1>() == 2);
    static_assert(a2.get<2>() == 3);
    static_assert(a2.get<3>() == 4);
    static_assert(a2[0] == 1);
    static_assert(a2[1] == 2);
    static_assert(a2[2] == 3);
    static_assert(a2[3] == 4);
}

void test_constexpr_sizeof()
{
    constexpr const_array<char, 4> a1{'a', 'b', 'c', 'd'};
    constexpr const_array<short, 5> a2{1, 2, 3, 4, 5};
    constexpr const_array<int, 6> a3 = {1, 2, 3, 4, 5, 6};
    constexpr const_array<long int, 7> a4 = {1, 2, 3, 4, 5, 6, 7};

    static_assert(sizeof(a1) == (sizeof(char) * 4));
    static_assert(sizeof(a2) == (sizeof(short) * 5));
    static_assert(sizeof(a3) == (sizeof(int) * 6));
    static_assert(sizeof(a4) == (sizeof(long int) * 7));
}

void test_pass_around()
{
    // TODO currently failing
}

void test_structured_binding()
{
    // TODO currently failing
}

int main()
{
    test_pass_around();
    test_structured_binding();

    return 0;
}