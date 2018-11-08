#include "sse2.h"
#include <cmath>
#include <emmintrin.h>

minhash::SSE2::SSE2() : minhash::MinHasher() 
{
    this->elementsInOneCall = 2;
}

minhash::SSE2::~SSE2() {}

void minhash::SSE2::printValue(__m128i var)
{
    uint64_t v[2];
    _mm_store_si128((__m128i*)v, var);
    // printf("% %" PRIu64 PRIu64 "\n", v[1], v[0]);
    printf("%" PRIu64 "\t", v[1]);
    printf("%" PRIu64 "\n", v[0]);
}