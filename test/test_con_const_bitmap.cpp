#include <octm/con/const_bitmap.hpp>
#include <octm/test/assert.hpp>

#include <iostream>

using namespace oc::cn;

int main()
{
    constexpr const_bitmap<10> map;
    map[0] = 1;

    STATIC_ASSERT(map.size() == 10);

    // std::cout << map[0] << std::endl;

    return 0;
}