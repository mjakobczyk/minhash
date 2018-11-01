// #include "avx.h"
// #include <cmath>

// minhash::AVX::AVX() : minhash::MinHasher() {}

// minhash::AVX::~AVX() {}

// uint64_t minhash::AVX::fmix64(uint64_t k)
// {
//     k ^= k >> 33;
//     k *= 0xff51afd7ed558ccdull;
//     k ^= k >> 33;
//     k *= 0xc4ceb9fe1a85ec53ull;
//     k ^= k >> 33;

//     return k;
// }

// uint64_t minhash::AVX::rotl64(uint64_t x, int32_t offset)
// {
//     return (x << offset) | (x >> (64 - offset));
// }

// uint64_t minhash::AVX::minHash(uint64_t x)
// {
//     // Hashes in between the process to calculate
//     uint64_t h, h1, h2;

//     // Perform calculations
//     h = x;
//     h *= 0x87c37b91114253d5ull;
//     h = rotl64(h, 31);
//     h *= 0x4cf5ad432745937full;
//     h1 = 42 ^ h;
//     h1 ^= k_div_4; //ceil(k / 4);
//     h2 = c42_xor_k_div_4; // 42 ^ ceil(k / 4);
//     h1 += h2;
//     h2 += h1;
//     h1 = fmix64(h1);
//     h2 = fmix64(h2);
//     h1 += h2;
//     h2 += h1;

//     // Return XOR as a final hash
//     return h1 ^ h2;
// }