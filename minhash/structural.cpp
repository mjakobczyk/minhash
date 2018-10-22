#include "structural.h"
#include <cmath>

inline uint64_t fmix64(uint64_t k)
{
    k ^= k >> 33;
    k *= 0xff51afd7ed558ccdull;
    k ^= k >> 33;
    k *= 0xc4ceb9fe1a85ec53ull;
    k ^= k >> 33;

    return k;
}

inline uint64_t rotl64(uint64_t x, int32_t offset)
{
    #ifdef WIN32
            return _rotl64(x, offset);
    #else
            return (x << offset) | (x >> (64 - offset));
    #endif
}

void minhash::Structural::minHash(uint64_t *input, uint64_t *output, const int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        uint64_t temp = input[i];

        output[i] = this->processElement(temp);
    }
}

uint64_t minhash::Structural::processElement(uint64_t x)
{
    // Hardcoded constants required for the algorithm
    uint64_t k = 20;
    uint64_t k_div_4 = (uint64_t)ceil((double)k/ 4);
    uint64_t c42_xor_k_div_4 = 42 ^ k_div_4;

    // Hashes in between the process to calculate
    uint64_t h, h1, h2;

    // Perform calculations
    h = x;
    h *= 0x87c37b91114253d5ull;
    h = rotl64(h, 31);
    h *= 0x4cf5ad432745937full;
    h1 = 42 ^ h;
    h1 ^= k_div_4; //ceil(k / 4);
    h2 = c42_xor_k_div_4; // 42 ^ ceil(k / 4);
    h1 += h2;
    h2 += h1;
    h1 = fmix64(h1);
    h2 = fmix64(h2);
    h1 += h2;
    h2 += h1;

    // Return XOR as a final hash
    return h1 ^ h2;
}