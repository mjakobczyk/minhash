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

        virtual void minHash(uint64_t* input, uint64_t* output, int size) override
        {
            for (unsigned int i = 0; i < size; i += this->getElementsInOneCall())
            {
                this->countPack(input, output, i);
            }
        }

    private:
        void inline countPack(uint64_t* input, uint64_t* output, int offset)
        {
            __m256i h, h1, h2, h3;

            h = _mm256_set_epi64x(
                *(input + offset + 3),
                *(input + offset + 2),
                *(input + offset + 1), 
                *(input + offset)
            );

            __m256i t1 =_mm256_set1_epi64x(0x87c37b91114253d5ull);
            h = this->multiply64Bit(h, t1);

            h = this->rotl64(h, 31);

            __m256i t2 =_mm256_set1_epi64x(0x4cf5ad432745937full);
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

            // Return XOR as a final hash
            h3 = _mm256_xor_si256(h1, h2);

            _mm256_store_si256((__m256i*)&output[offset], h3);            

            std::cout << "Final: ";
            this->printValue(h3);
            std::cout << std::endl << std::endl;
        }

        __m256i inline fmix64(__m256i x)
        {
            // k ^= k >> 33
            x = _mm256_xor_si256(x, _mm256_srli_epi64(x, 33));

            // k *= 0xff51afd7ed558ccdull;
            x = this->multiply64Bit(x, _mm256_set1_epi64x(0xff51afd7ed558ccdull));
            
            // k ^= k >> 33
            x = _mm256_xor_si256(x,  _mm256_srli_epi64(x, 33));

            // k *= 0xc4ceb9fe1a85ec53ull;
            x = this->multiply64Bit(x, _mm256_set1_epi64x(0xc4ceb9fe1a85ec53ull));

            // k ^= k >> 33
            x = _mm256_xor_si256(x, _mm256_srli_epi64(x, 33));

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