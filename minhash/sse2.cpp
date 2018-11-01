#include "sse2.h"
#include <cmath>
#include <immintrin.h>

minhash::SSE2::SSE2() : minhash::MinHasher() 
{
    this->elementsInOneCall = 2;
}

minhash::SSE2::~SSE2() {}

void minhash::SSE2::minHash(uint64_t* input, uint64_t* output, int offset)
{
    int size = this->elementsInOneCall;
    uint64_t in[size], out[size];

    // Version 1: Loop
    // Fill array with values from input array
    // for (int i = 0; i < size; ++i)
    // {
    //     in[i] = *(input + offset + i);
    // }

    // Version 2: straight-forward
    in[0] = *(input + offset);
    in[1] = *(input + offset + 1);

    //  Hashes in between the process to calculate
    // uint64_t h, h1, h2;
    __m128i h, h1, h2, h3;

    // // Perform calculations
    // h = x;
    h = _mm_set_epi64x(in[0], in[1]);
    h3 = h;

    // h *= 0x87c37b91114253d5ull;
    __m128i t1 =_mm_set1_epi64x(0x87c37b91114253d5ull);
    h = _mm_mul_epu32(h, t1);
    
    h = rotl64(h, 31);

    // h *= 0x4cf5ad432745937full;
    __m128i t2 =_mm_set1_epi64x(0x4cf5ad432745937full);
    h = _mm_mul_epu32(h, t2);

    // h1 = 42 ^ h;
    __m128i t3 = _mm_set1_epi16(42);
    h1 = _mm_xor_si128(h, t3);

    // h1 ^= k_div_4; //ceil(k / 4);
    __m128i t4 = _mm_set1_epi32(this->k_div_4);
    h1 = _mm_xor_si128(h, t4);

    // h2 = c42_xor_k_div_4; // 42 ^ ceil(k / 4);
    h2 = _mm_set1_epi64x(this->c42_xor_k_div_4);

    // h1 += h2;
    h1 = _mm_add_epi64(h1, h2);

    // h2 += h1;
    h2 = _mm_add_epi64(h2, h1);

    //h1 = fmix64(h1);
    //h2 = fmix64(h2);

    // h1 += h2;
    h1 = _mm_add_epi64(h1, h2);

    // h2 += h1;
    h2 = _mm_add_epi64(h2, h1);

    // Return XOR as a final hash
    // h3 = h1 ^ h2;
    h3 = _mm_xor_si128(h1, h2);

    _mm_store_si128((__m128i*)out, h3);

    // Version 1: Loop
    // Fill output array with values count in the algorithm
    for (int i = 0; i < size; ++i)
    {
        *(output + offset + i) = out[size - 1 - i];
    }

    // Version 2: straight-forward
    *(output + offset) = out[size - 1];
    *(output + offset + 1) = out[size - 2];
}

__m128i minhash::SSE2::fmix64(__m128i x)
{
    // k = k >> 33
    x = _mm_srli_epi64(x, 33);
    // k ^= k
    x = _mm_xor_si128(x, x);
    // k = k >> 33
    x = _mm_srli_epi64(x, 33);
    // k ^= k
    x = _mm_xor_si128(x, x);
    // k *= 0xff51afd7ed558ccdull;
    __m128i t1 =_mm_set1_epi64x(0xff51afd7ed558ccdull);
    x = _mm_mul_epu32(x, t1);
    // k = k >> 33
    x = _mm_srli_epi64(x, 33);
    // k ^= k
    x = _mm_xor_si128(x, x);
    // k *= 0xc4ceb9fe1a85ec53ull;
    __m128i t2 =_mm_set1_epi64x(0xc4ceb9fe1a85ec53ull);
    x = _mm_mul_epu32(x, t2);
    // k = k >> 33
    x = _mm_srli_epi64(x, 33);
    // k ^= k
    x = _mm_xor_si128(x, x);

    return x;
}

__m128i minhash::SSE2::rotl64(__m128i x, int32_t offset)
{
    // return (x << offset) | (x >> (64 - offset));
    __m128i h1 = _mm_slli_epi64(x, offset);
    __m128i h2 = _mm_srli_epi64(x, 64 - offset);
    return _mm_or_si128(h1, h2);
}