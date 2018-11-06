#include "sse2.h"
#include <cmath>
#include <emmintrin.h>

minhash::SSE2::SSE2() : minhash::MinHasher() 
{
    this->elementsInOneCall = 2;
}

minhash::SSE2::~SSE2() {}

void minhash::SSE2::minHash(uint64_t* input, uint64_t* output, int offset)
{
    // uint64_t out[2];

    __m128i h, h1, h2, h3;

    // Perform calculations
    h = _mm_set_epi64x(*(input + offset + 1), *(input + offset));

    __m128i t1 =_mm_set1_epi64x(0x87c37b91114253d5ull);

    // Old version - multiply 32bit value
    // h = _mm_mul_epu32(h, t1);
    // New version - own function
    // h = this->multiply64Bit(h, t1);

    h = this->rotl64(h, 31);

    __m128i t2 =_mm_set1_epi64x(0x4cf5ad432745937full);
    //   h = this->multiply64Bit(h, t2);

    __m128i t3 = _mm_set1_epi16(42);
    h1 = _mm_xor_si128(h, t3);

    __m128i t4 = _mm_set1_epi32(this->k_div_4);
    h1 = _mm_xor_si128(h, t4);

    h2 = _mm_set1_epi64x(this->c42_xor_k_div_4);

    h1 = _mm_add_epi64(h1, h2);

    h2 = _mm_add_epi64(h2, h1);

    // h1 = fmix64(h1);

    // h2 = fmix64(h2);

    h1 = _mm_add_epi64(h1, h2);

    h2 = _mm_add_epi64(h2, h1);

    // Return XOR as a final hash
    h3 = _mm_xor_si128(h1, h2);

    // _mm_store_si128((__m128i*)out, h3);
    _mm_store_si128((__m128i*)&output[offset], h3);

    // Version 1: Loop
    // Fill output array with values count in the algorithm
    // for (int i = 0; i < size; ++i)
    // {
    //     *(output + offset + i) = out[size - 1 - i];
    // }

    // // Version 2: straight-forward
    // *(output + offset) = out[1];
    // *(output + offset + 1) = out[0];
}

__m128i minhash::SSE2::fmix64(__m128i x)
{
    __m128i t1;
    // k >> 33
    t1 = _mm_srli_epi64(x, 33);
    // k ^= k
    x = _mm_xor_si128(x, t1);
    // k >> 33
    t1 = _mm_srli_epi64(x, 33);
    // k ^= k
    x = _mm_xor_si128(x, t1);
    // k *= 0xff51afd7ed558ccdull;
    __m128i t2 =_mm_set1_epi64x(0xff51afd7ed558ccdull);
    this->multiply64Bit(x, t2);
    // k >> 33
    t1 = _mm_srli_epi64(x, 33);
    // k ^= k
    x = _mm_xor_si128(x, t1);
    // k *= 0xc4ceb9fe1a85ec53ull;
    __m128i t3 =_mm_set1_epi64x(0xc4ceb9fe1a85ec53ull);
    this->multiply64Bit(x, t3);
    // k >> 33
    t1 = _mm_srli_epi64(x, 33);
    // k ^= k
    x = _mm_xor_si128(x, t1);

    return x;
}

__m128i minhash::SSE2::rotl64(__m128i x, int32_t offset)
{
    return _mm_or_si128( _mm_slli_epi64(x, offset), _mm_srli_epi64(x, 64 - offset));
}

__m128i minhash::SSE2::multiply64Bit(__m128i a, __m128i b)
{
    auto ax0_ax1_ay0_ay1 = a;
    auto bx0_bx1_by0_by1 = b;
    
    auto ax1_i_ay1_i = _mm_shuffle_epi32(ax0_ax1_ay0_ay1, _MM_SHUFFLE(3, 3, 1, 1));
    auto bx1_i_by1_i = _mm_shuffle_epi32(bx0_bx1_by0_by1, _MM_SHUFFLE(3, 3, 1, 1));

    auto ax0bx0_ay0by0 = _mm_mul_epi32(ax0_ax1_ay0_ay1, bx0_bx1_by0_by1);
    auto ax0bx1_ay0by1 = _mm_mul_epi32(ax0_ax1_ay0_ay1, bx1_i_by1_i);
    auto ax1bx0_ay1by0 = _mm_mul_epi32(ax1_i_ay1_i, bx0_bx1_by0_by1);

    auto ax0bx1_ay0by1_32 = _mm_slli_epi64(ax0bx1_ay0by1, 32);
    auto ax1bx0_ay1by0_32 = _mm_slli_epi64(ax1bx0_ay1by0, 32);

    return _mm_add_epi64(ax0bx0_ay0by0, _mm_add_epi64(ax0bx1_ay0by1_32, ax1bx0_ay1by0_32));
}

void minhash::SSE2::printValue(__m128i var)
{
	uint64_t v[2];
    _mm_store_si128((__m128i*)v, var);
    // printf("% %" PRIu64 PRIu64 "\n", v[1], v[0]);
    printf("%" PRIu64 "\t", v[1]);
    printf("%" PRIu64 "\n", v[0]);
}