#include "structural.h"
#include "minhasher.h"
#include <cmath>

minhash::Structural::Structural() : minhash::MinHasher() 
{
    this->elementsInOneCall = 1;
}

minhash::Structural::~Structural() {}

void minhash::Structural::minHash(uint64_t* input, uint64_t* output, int offset)
{
    uint64_t x = input[offset];

    // Hashes in between the process to calculate
    uint64_t h, h1, h2;

    // Perform calculations
    h = x;
    if(DEBUG) std::cout << "Structural debug in...." << std::endl;
    if(DEBUG) this->printValue(h);

    h *= 0x87c37b91114253d5ull;
    if(DEBUG) this->printValue(h);

    // h = this->rotl64(h, 31);
    // if(DEBUG) this->printValue(h);

    // h *= 0x4cf5ad432745937full;
    // if(DEBUG) this->printValue(h);

    // h1 = 42 ^ h;
    // if(DEBUG) this->printValue(h1);

    // h1 ^= this->k_div_4; //ceil(k / 4);
    // if(DEBUG) this->printValue(h1);

    // h2 = this->c42_xor_k_div_4; // 42 ^ ceil(k / 4);
    // if(DEBUG) this->printValue(h2);

    // h1 += h2;
    // if(DEBUG) this->printValue(h1);

    // h2 += h1;
    // if(DEBUG) this->printValue(h2);

    // h1 = fmix64(h1);
    // if(DEBUG) this->printValue(h1);

    // h2 = fmix64(h2);
    // if(DEBUG) this->printValue(h2);

    // h1 += h2;
    // if(DEBUG) this->printValue(h1);

    // h2 += h1;
    // if(DEBUG) this->printValue(h2);

    // // Return XOR as a final hash
    // output[offset] = h1 ^ h2;
    // if(DEBUG) this->printValue(output[offset]);
    output[offset] = h;

    if(DEBUG) std::cout << "Structural debug out..." << std::endl << std::endl;
}

uint64_t minhash::Structural::fmix64(uint64_t element)
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
    return (x << offset) | (x >> (64 - offset));
}

void minhash::Structural::printValue(uint64_t x)
{
    printf("%" PRIu64 "\n", x);
}