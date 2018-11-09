#include "avx2.h"

minhash::AVX2::AVX2() : minhash::MinHasher() 
{
    this->elementsInOneCall = 4;
}

minhash::AVX2::~AVX2() {}

void minhash::AVX2::printValue(__m256i var)
{
    uint64_t v[4];
    _mm256_store_si256((__m256i*)v, var);
    printf("%" PRIu64 "\t", v[3]);
    printf("%" PRIu64 "\t", v[2]);
    printf("%" PRIu64 "\t", v[1]);
    printf("%" PRIu64 "\n", v[0]);
}