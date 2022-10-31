#include <octm/array.hpp>
#include <octm/assert.hpp>

using namespace oc::tm;

void test_initializer()
{
    constexpr_ const_array<int, 0> a1 = {};
    static_assert_(a1.size() == 0);

    constexpr_ const_array a3 = {1, 2, 3};
    static_assert_(a3.size() == 3);

    constexpr_ const_array a4{1, 2, 3, 4};
    static_assert_(a4.size() == 4);
}

void test_get()
{
    constexpr_ const_array a1{'a', 'b', 'c', 'd'};
    static_assert_(a1.get<0>() == 'a');
    static_assert_(a1.get<1>() == 'b');
    static_assert_(a1.get<2>() == 'c');
    static_assert_(a1.get<3>() == 'd');
    static_assert_(a1[0] == 'a');
    static_assert_(a1[1] == 'b');
    static_assert_(a1[2] == 'c');
    static_assert_(a1[3] == 'd');

    constexpr_ const_array a2{1, 2, 3, 4};
    static_assert_(a2.get<0>() == 1);
    static_assert_(a2.get<1>() == 2);
    static_assert_(a2.get<2>() == 3);
    static_assert_(a2.get<3>() == 4);
    static_assert_(a2[0] == 1);
    static_assert_(a2[1] == 2);
    static_assert_(a2[2] == 3);
    static_assert_(a2[3] == 4);
}

void test_sizeof()
{
    constexpr_ const_array<char, 4> a1{'a', 'b', 'c', 'd'};
    static_assert_(sizeof(a1) == (sizeof(char) * 4));

    constexpr_ const_array<short, 5> a2{1, 2, 3, 4, 5};
    static_assert_(sizeof(a2) == (sizeof(short) * 5));

    constexpr_ const_array<int, 6> a3 = {1, 2, 3, 4, 5, 6};
    static_assert_(sizeof(a3) == (sizeof(int) * 6));

    constexpr_ const_array<long int, 7> a4 = {1, 2, 3, 4, 5, 6, 7};
    static_assert_(sizeof(a4) == (sizeof(long int) * 7));

}
void test_pass_around()
{
    // auto pptr = [](const int *) {};
    // auto pref = [](const int[2]) {};

    // const_array a1 = {1, 2};
    // pptr(a1);
    // pref(a1);

    test_assert(false); // PA is failing, todo fix
}

void test_structured_binding()
{
    test_assert(false); // SB is failing, todo fix
}

int main()
{
    test_initializer();
    test_get();
    test_sizeof();
    test_pass_around();
    test_structured_binding();

    return 0;
}