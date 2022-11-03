#include <octm/bits/bit_scan_forward.hpp>
#include <octm/test/assert.hpp>

using namespace oc::fn;

void test_bsf_32_constexpr()
{
    static_assert(bit_scan_forward((uint32_t)0b00000000000000000000000000000000) == -1);
    static_assert(bit_scan_forward((uint32_t)0b00001100000000000000000000000001) == 0);
    static_assert(bit_scan_forward((uint32_t)0b00000000000111000000000111100010) == 1);
    static_assert(bit_scan_forward((uint32_t)0b00010000000000000000000000000100) == 2);
    static_assert(bit_scan_forward((uint32_t)0b00110000000000000000000010001000) == 3);
    static_assert(bit_scan_forward((uint32_t)0b11111111111111111111111111110000) == 4);
    static_assert(bit_scan_forward((uint32_t)0b10000000000000000000000000100000) == 5);
    static_assert(bit_scan_forward((uint32_t)0b00000000000000000000000001000000) == 6);
    static_assert(bit_scan_forward((uint32_t)0b00010000000000000000000010000000) == 7);
    static_assert(bit_scan_forward((uint32_t)0b00100100000000000000000100000000) == 8);
    static_assert(bit_scan_forward((uint32_t)0b00000000000000000000001000000000) == 9);
    static_assert(bit_scan_forward((uint32_t)0b00000000000000000000010000000000) == 10);
    static_assert(bit_scan_forward((uint32_t)0b00000110000000000000100000000000) == 11);
    static_assert(bit_scan_forward((uint32_t)0b00000000000000000001000000000000) == 12);
    static_assert(bit_scan_forward((uint32_t)0b00000000000000000010000000000000) == 13);
    static_assert(bit_scan_forward((uint32_t)0b0000110000000000100000000000000) == 14);
    static_assert(bit_scan_forward((uint32_t)0b00000000000000001000000000000000) == 15);
    static_assert(bit_scan_forward((uint32_t)0b00000000000000010000000000000000) == 16);
    static_assert(bit_scan_forward((uint32_t)0b00011000000000100000000000000000) == 17);
    static_assert(bit_scan_forward((uint32_t)0b00000000000001000000000000000000) == 18);
    static_assert(bit_scan_forward((uint32_t)0b00001000000010000000000000000000) == 19);
    static_assert(bit_scan_forward((uint32_t)0b00111000000100000000000000000000) == 20);
    static_assert(bit_scan_forward((uint32_t)0b00000000001000000000000000000000) == 21);
    static_assert(bit_scan_forward((uint32_t)0b01100000010000000000000000000000) == 22);
    static_assert(bit_scan_forward((uint32_t)0b00000000100000000000000000000000) == 23);
    static_assert(bit_scan_forward((uint32_t)0b00000001000000000000000000000000) == 24);
    static_assert(bit_scan_forward((uint32_t)0b01000010000000000000000000000000) == 25);
    static_assert(bit_scan_forward((uint32_t)0b00000100000000000000000000000000) == 26);
    static_assert(bit_scan_forward((uint32_t)0b00001000000000000000000000000000) == 27);
    static_assert(bit_scan_forward((uint32_t)0b00010000000000000000000000000000) == 28);
    static_assert(bit_scan_forward((uint32_t)0b00100000000000000000000000000000) == 29);
    static_assert(bit_scan_forward((uint32_t)0b01000000000000000000000000000000) == 30);
    static_assert(bit_scan_forward((uint32_t)0b10000000000000000000000000000000) == 31);
}

void test_bsf_64_constexpr()
{
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000000000000000000000000000000000000000000000000000) == -1);
    static_assert(bit_scan_forward((uint64_t)0b0000000000011100000000000000000100000000000000000000000000000000) == 32);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000000000000000001000000000000000000000000000000000) == 33);
    static_assert(bit_scan_forward((uint64_t)0b0000001100000000000011000000010000000000000000000000000000000000) == 34);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000000000000000100000000000000000000000000000000000) == 35);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000000000000001000000000000000000000000000000000000) == 36);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000000110000010000000000000000000000000000000000000) == 37);
    static_assert(bit_scan_forward((uint64_t)0b0000000000100000000000000100000000000000000000000000000000000000) == 38);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000000100001000000000000000000000000000000000000000) == 39);
    static_assert(bit_scan_forward((uint64_t)0b0000000000110000000000010000000000000000000000000000000000000000) == 40);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000100000100000000000000000000000000000000000000000) == 41);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000000001000000000000000000000000000000000000000000) == 42);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000000000010000000000000000000000000000000000000000000) == 43);
    static_assert(bit_scan_forward((uint64_t)0b0000001000110000000100000000000000000000000000000000000000000000) == 44);
    static_assert(bit_scan_forward((uint64_t)0b0000000000010000001000000000000000000000000000000000000000000000) == 45);
    static_assert(bit_scan_forward((uint64_t)0b0000001000000000010000000000000000000000000000000000000000000000) == 46);
    static_assert(bit_scan_forward((uint64_t)0b0001000000000000100000000000000000000000000000000000000000000000) == 47);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000001000000000000000000000000000000000000000000000000) == 48);
    static_assert(bit_scan_forward((uint64_t)0b0000000000010010000000000000000000000000000000000000000000000000) == 49);
    static_assert(bit_scan_forward((uint64_t)0b0000000000000100000000000000000000000000000000000000000000000000) == 50);
    static_assert(bit_scan_forward((uint64_t)0b0000000000001000000000000000000000000000000000000000000000000000) == 51);
    static_assert(bit_scan_forward((uint64_t)0b0000000000010000000000000000000000000000000000000000000000000000) == 52);
    static_assert(bit_scan_forward((uint64_t)0b0000000000100000000000000000000000000000000000000000000000000000) == 53);
    static_assert(bit_scan_forward((uint64_t)0b0000000001000000000000000000000000000000000000000000000000000000) == 54);
    static_assert(bit_scan_forward((uint64_t)0b0000000010000000000000000000000000000000000000000000000000000000) == 55);
    static_assert(bit_scan_forward((uint64_t)0b0000000100000000000000000000000000000000000000000000000000000000) == 56);
    static_assert(bit_scan_forward((uint64_t)0b0000001000000000000000000000000000000000000000000000000000000000) == 57);
    static_assert(bit_scan_forward((uint64_t)0b0000010000000000000000000000000000000000000000000000000000000000) == 58);
    static_assert(bit_scan_forward((uint64_t)0b0000100000000000000000000000000000000000000000000000000000000000) == 59);
    static_assert(bit_scan_forward((uint64_t)0b0001000000000000000000000000000000000000000000000000000000000000) == 60);
    static_assert(bit_scan_forward((uint64_t)0b0010000000000000000000000000000000000000000000000000000000000000) == 61);
    static_assert(bit_scan_forward((uint64_t)0b0100000000000000000000000000000000000000000000000000000000000000) == 62);
    static_assert(bit_scan_forward((uint64_t)0b1000000000000000000000000000000000000000000000000000000000000000) == 63);
}

void test_bsf_32()
{
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000000000000000000000) == -1);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000100000000000000001) == 0);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000100000000000000010) == 1);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000001000000000000000100) == 2);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000000000000000001000) == 3);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000001000000000000010000) == 4);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00001000000000000000000000100000) == 5);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000000000000001000000) == 6);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000010000000000000000010000000) == 7);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000010000000000000100000000) == 8);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000000000001000000000) == 9);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000100000000000000010000000000) == 10);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000000000100000000000) == 11);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000000001000000000000) == 12);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000100010000000010000000000000) == 13);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000000100000000000000) == 14);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000100000000001000000000000000) == 15);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000010000000000000000) == 16);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000000100000000000000000) == 17);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000001000000000000000000) == 18);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000010000000000000000000) == 19);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000000100000000000000000000) == 20);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000001000000000000000000000) == 21);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000010000000000000000000000) == 22);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000000100000000000000000000000) == 23);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000001000000000000000000000000) == 24);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000010000000000000000000000000) == 25);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00000100000000000000000000000000) == 26);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00001000000000000000000000000000) == 27);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00010000000000000000000000000000) == 28);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b00100000000000000000000000000000) == 29);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b01000000000000000000000000000000) == 30);
    TEST_ASSERT(bit_scan_forward((uint32_t)0b10000000000000000000000000000000) == 31);
}

void test_bsf_64()
{
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000000000000000000000000000000000000000000000000000) == -1);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000000000011000000100000000000000000000000000000000) == 32);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000011110000000001000000000000000000000000000000000) == 33);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000110000000000000000000000010000000000000000000000000000000000) == 34);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000100000000000000100000000000000000000000000000000000) == 35);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000110000000000000000000001000000000000000000000000000000000000) == 36);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000000000000010000000000000000000000000000000000000) == 37);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000111111111000100000000100000000000000000000000000000000000000) == 38);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000000000001000000000000000000000000000000000000000) == 39);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000000000010000000000000000000000000000000000000000) == 40);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000001111110010100000100000000000000000000000000000000000000000) == 41);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000000001000000000000000000000000000000000000000000) == 42);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000001100000010000000000000000000000000000000000000000000) == 43);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b1110000000000000000100000000000000000000000000000000000000000000) == 44);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000001000000000000000000000000000000000000000000000) == 45);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000000010000000000000000000000000000000000000000000000) == 46);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000111000000100000000000000000000000000000000000000000000000) == 47);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0011110000000001000000000000000000000000000000000000000000000000) == 48);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000000010000000000000000000000000000000000000000000000000) == 49);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0011100000000100000000000000000000000000000000000000000000000000) == 50);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000001000000000000000000000000000000000000000000000000000) == 51);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000000010000000000000000000000000000000000000000000000000000) == 52);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b1111111111100000000000000000000000000000000000000000000000000000) == 53);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0010010001000000000000000000000000000000000000000000000000000000) == 54);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000010010000000000000000000000000000000000000000000000000000000) == 55);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000000100000000000000000000000000000000000000000000000000000000) == 56);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0010001000000000000000000000000000000000000000000000000000000000) == 57);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000010000000000000000000000000000000000000000000000000000000000) == 58);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0000100000000000000000000000000000000000000000000000000000000000) == 59);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0001000000000000000000000000000000000000000000000000000000000000) == 60);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0010000000000000000000000000000000000000000000000000000000000000) == 61);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b0100000000000000000000000000000000000000000000000000000000000000) == 62);
    TEST_ASSERT(bit_scan_forward((uint64_t)0b1000000000000000000000000000000000000000000000000000000000000000) == 63);
}

int main(int, char **)
{

    test_bsf_32();
    test_bsf_64();

    return 0;
}