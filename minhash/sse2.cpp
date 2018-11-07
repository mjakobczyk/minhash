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
    __m128i h, h1, h2, h3;

    h = _mm_set_epi64x(*(input + offset + 1), *(input + offset));

    __m128i t1 =_mm_set1_epi64x(0x87c37b91114253d5ull);

    h = this->multiply64Bit(h, t1);

    h = this->rotl64(h, 31);

    __m128i t2 =_mm_set1_epi64x(0x4cf5ad432745937full);
    h = this->multiply64Bit(h, t2);

    __m128i t3 = _mm_set1_epi16(42);
    h1 = _mm_xor_si128(h, t3);

    __m128i t4 = _mm_set1_epi32(this->k_div_4);
    h1 = _mm_xor_si128(h, t4);

    h2 = _mm_set1_epi64x(this->c42_xor_k_div_4);

    h1 = _mm_add_epi64(h1, h2);

    h2 = _mm_add_epi64(h2, h1);

    h1 = fmix64(h1);

    h2 = fmix64(h2);

    h1 = _mm_add_epi64(h1, h2);

    h2 = _mm_add_epi64(h2, h1);

    // Return XOR as a final hash
    h3 = _mm_xor_si128(h1, h2);

    // _mm_store_si128((__m128i*)out, h3);
    _mm_store_si128((__m128i*)&output[offset], h3);
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
    __m128i bswap   = _mm_shuffle_epi32(b,0xB1);           // b0H,b0L,b1H,b1L (swap H<->L)
    __m128i prodlh  = _mm_mullo_epi32(a,bswap);            // a0Lb0H,a0Hb0L,a1Lb1H,a1Hb1L, 32 bit L*H products
    __m128i zero    = _mm_setzero_si128();                 // 0
    __m128i prodlh2 = _mm_hadd_epi32(prodlh,zero);         // a0Lb0H+a0Hb0L,a1Lb1H+a1Hb1L,0,0
    __m128i prodlh3 = _mm_shuffle_epi32(prodlh2,0x73);     // 0, a0Lb0H+a0Hb0L, 0, a1Lb1H+a1Hb1L
    __m128i prodll  = _mm_mul_epu32(a,b);                  // a0Lb0L,a1Lb1L, 64 bit unsigned products
    __m128i prod    = _mm_add_epi64(prodll,prodlh3);       // a0Lb0L+(a0Lb0H+a0Hb0L)<<32, a1Lb1L+(a1Lb1H+a1Hb1L)<<32
    return  prod;
}

void minhash::SSE2::countPack(uint64_t* input, uint64_t* output, int size)
{
    // TODO: implement
}

void minhash::SSE2::printValue(__m128i var)
{
	uint64_t v[2];
    _mm_store_si128((__m128i*)v, var);
    // printf("% %" PRIu64 PRIu64 "\n", v[1], v[0]);
    printf("%" PRIu64 "\t", v[1]);
    printf("%" PRIu64 "\n", v[0]);
}