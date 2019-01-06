#ifndef AVX2_H_
#define AVX2_H_
#include "minhasher.h"
#include <immintrin.h> 
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <cmath>

namespace minhash
{
    class AVX2 : public minhash::MinHasher
    {
    public:
        AVX2();
        virtual ~AVX2();

        virtual inline void minHash(uint64_t*& input, uint64_t*& output, int size) override
        {
            for (unsigned int i = 0; i < size; i += this->getElementsInOneCall())
            {
                this->countPack(input, output, i);
            }
        }

    private:
        void inline countPack(uint64_t*& input, uint64_t*& output, int offset)
        {
            __m256i h, h1, h2, h3;

            // Alternative way of loading data
            // h = _mm256_set_epi64x(
            //     *(input + offset + 3),
            //     *(input + offset + 2),
            //     *(input + offset + 1), 
            //     *(input + offset)
            // );

            h = _mm256_loadu_si256((__m256i*)&input[offset]);

            __m256i t1 =_mm256_set1_epi64x(this->firstConstValue);
            h = this->multiply64Bit(h, t1);
            h = this->rotl64(h, 31);

            __m256i t2 =_mm256_set1_epi64x(this->secondConstValue);
            h = this->multiply64Bit(h, t2);

            __m256i t3 = _mm256_set1_epi64x(42);
            h1 = _mm256_xor_si256(t3, h);

            __m256i t4 = _mm256_set1_epi64x(this->k_div_4);
            h1 = _mm256_xor_si256(h1, t4);
        
            h2 = _mm256_set1_epi64x(this->c42_xor_k_div_4);
            h1 = _mm256_add_epi64(h1, h2);
            h2 = _mm256_add_epi64(h2, h1);

            h1 = fmix64(h1);
            h2 = fmix64(h2);
            
            h1 = _mm256_add_epi64(h1, h2);
            h2 = _mm256_add_epi64(h2, h1);
            h3 = _mm256_xor_si256(h1, h2);

            _mm256_store_si256((__m256i*)&output[offset], h3);            
        }

        __m256i inline fmix64(__m256i x)
        {
            __m256i t1;
            // k >> 33
            t1 = _mm256_srli_epi64(x, 33);
            // k ^= k
            x = _mm256_xor_si256(x, t1);
            // k >> 33
            t1 = _mm256_srli_epi64(x, 33);
            // k ^= k
            x = _mm256_xor_si256(x, t1);
            // k *= 0xff51afd7ed558ccdull;
            __m256i t2 =_mm256_set1_epi64x(this->thirdConstValue);
            this->multiply64Bit(x, t2);
            // k >> 33
            t1 = _mm256_srli_epi64(x, 33);
            // k ^= k
            x = _mm256_xor_si256(x, t1);
            // k *= 0xc4ceb9fe1a85ec53ull;
            __m256i t3 =_mm256_set1_epi64x(this->fourthConstValue);
            this->multiply64Bit(x, t3);
            // k >> 33
            t1 = _mm256_srli_epi64(x, 33);
            // k ^= k
            x = _mm256_xor_si256(x, t1);

            return x;
        }

        __m256i inline rotl64(__m256i x, int32_t offset)
        {
            return _mm256_or_si256( _mm256_slli_epi64(x, offset), _mm256_srli_epi64(x, 64 - offset));
        }

        __m256i inline multiply64Bit(__m256i a, __m256i b)
        {
            __m256i bswap   = _mm256_shuffle_epi32(b,0xB1);           // swap H<->L
            __m256i prodlh  = _mm256_mullo_epi32(a,bswap);            // 32 bit L*H products
            __m256i zero    = _mm256_setzero_si256();                 // 0
            __m256i prodlh2 = _mm256_hadd_epi32(prodlh,zero);         // a0Lb0H+a0Hb0L,a1Lb1H+a1Hb1L,0,0
            __m256i prodlh3 = _mm256_shuffle_epi32(prodlh2,0x73);     // 0, a0Lb0H+a0Hb0L, 0, a1Lb1H+a1Hb1L
            __m256i prodll  = _mm256_mul_epu32(a,b);                  // a0Lb0L,a1Lb1L, 64 bit unsigned products
            __m256i prod    = _mm256_add_epi64(prodll,prodlh3);       // a0Lb0L+(a0Lb0H+a0Hb0L)<<32, a1Lb1L+(a1Lb1H+a1Hb1L)<<32
            return  prod;
        }

        void printValue(__m256i var);

    };
};

#endif