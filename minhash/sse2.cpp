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

    h1 = _mm_set_epi64x(in[0], in[1]);
    h2 = h1;
    h3 = h2;

    // // Perform calculations
    // h = x;


    // h *= 0x87c37b91114253d5ull;
    // h = rotl64(h, 31);
    // h *= 0x4cf5ad432745937full;
    // h1 = 42 ^ h;
    // h1 ^= k_div_4; //ceil(k / 4);
    // h2 = c42_xor_k_div_4; // 42 ^ ceil(k / 4);
    // h1 += h2;
    // h2 += h1;
    // h1 = fmix64(h1);
    // h2 = fmix64(h2);
    // h1 += h2;
    // h2 += h1;

    // Return XOR as a final hash
    // h3 = h1 ^ h2;

    _mm_store_si128((__m128i*)out, h3);
    std::cout << "out =" << out[0] << std::endl;
    std::cout << "out =" << out[1] << std::endl;

    // Fill output array with values count in the algorithm
    for (int i = 0; i < size; ++i)
    {
        *(output + offset + i) = out[size - 1 - i];
    }
}

uint64_t minhash::SSE2::fmix64(uint64_t k)
{
    // k ^= k >> 33;
    // k *= 0xff51afd7ed558ccdull;
    // k ^= k >> 33;
    // k *= 0xc4ceb9fe1a85ec53ull;
    // k ^= k >> 33;

    return k;
}

uint64_t minhash::SSE2::rotl64(uint64_t x, int32_t offset)
{
    // return (x << offset) | (x >> (64 - offset));
    return x;
}