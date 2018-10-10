#include <iostream>
#include <immintrin.h>

void print128_num(__m128i var)
{
	uint32_t v[4];
    _mm_store_si128((__m128i*)v, var);
    printf("v4_u32: %x %x %x %x\n", v[3], v[2], v[1], v[0]);
}

void testSIMD()
{
    
	__m128i v1 = _mm_set_epi32(1, 2, 3, 4);
	__m128i v2 = _mm_set1_epi32(2);
	__m128i v3 = _mm_add_epi32(v1, v2);

	print128_num(v1);
	print128_num(v2);
	print128_num(v3);
}