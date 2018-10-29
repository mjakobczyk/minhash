#include "structural.h"
#include "minhasher.h"
#include <cmath>

minhash::Structural::Structural() : minhash::MinHasher()
{
    std::cout << this->k << std::endl;
}

minhash::Structural::~Structural() {}

 uint64_t minhash::Structural::fmix64(uint64_t k)
{
    k ^= k >> 33;
    k *= 0xff51afd7ed558ccdull;
    k ^= k >> 33;
    k *= 0xc4ceb9fe1a85ec53ull;
    k ^= k >> 33;

    return k;
}

uint64_t minhash::Structural::rotl64(uint64_t x, int32_t offset)
{
    #ifdef WIN32
            return _rotl64(x, offset);
    #else
            return (x << offset) | (x >> (64 - offset));
    #endif
}

uint64_t minhash::Structural::minHash(uint64_t x)
{
    // Hardcoded constants required for the algorithm
    // uint64_t k = 20;
    // uint64_t k_div_4 = (uint64_t)ceil((double)k/ 4);
    // uint64_t c42_xor_k_div_4 = 42 ^ k_div_4;

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