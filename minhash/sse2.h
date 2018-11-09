#ifndef SSE2_H_
#define SSE2_H_
#include "minhasher.h"
#include <immintrin.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#define DEBUG 0

namespace minhash
{
    class SSE2 : public minhash::MinHasher
    {
    public:
        SSE2();
        virtual ~SSE2();

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
            __m128i h, h1, h2, h3;
            h = _mm_set_epi64x(
                *(input + offset + 1),
                *(input + offset)
            );

            __m128i t1 =_mm_set1_epi64x(0x87c37b91114253d5ull);
            h = this->multiply64Bit(h, t1);

            h = this->rotl64(h, 31);

            __m128i t2 =_mm_set1_epi64x(0x4cf5ad432745937full);
            h = this->multiply64Bit(h, t2);

            __m128i t3 = _mm_set1_epi64x(42);
            h1 = _mm_xor_si128(t3, h);

            __m128i t4 = _mm_set1_epi64x(this->k_div_4);
            h1 = _mm_xor_si128(h1, t4);

            h2 = _mm_set1_epi64x(this->c42_xor_k_div_4);
            h1 = _mm_add_epi64(h1, h2);

            h2 = _mm_add_epi64(h2, h1);

            h1 = fmix64(h1);

            h2 = fmix64(h2);

            h1 = _mm_add_epi64(h1, h2);

            h2 = _mm_add_epi64(h2, h1);

            // Return XOR as a final hash
            h3 = _mm_xor_si128(h1, h2);

            _mm_store_si128((__m128i*)&output[offset], h3);

            std::cout << "Final: ";
            this->printValue(h3);
            std::cout << std::endl << std::endl;
        }

        __m128i inline fmix64(__m128i x)
        {
            // k ^= k >> 33
            x = _mm_xor_si128(x, _mm_srli_epi64(x, 33));
            
            // k *= 0xff51afd7ed558ccdull;
            x = this->multiply64Bit(x, _mm_set1_epi64x(0xff51afd7ed558ccdull));

            // k ^= k >> 33
            x = _mm_xor_si128(x, _mm_srli_epi64(x, 33));

            // k *= 0xc4ceb9fe1a85ec53ull;
            x = this->multiply64Bit(x, _mm_set1_epi64x(0xc4ceb9fe1a85ec53ull));

            // k ^= k >> 33
            x = _mm_xor_si128(x, _mm_srli_epi64(x, 33));

            return x;
        }

       __m128i inline rotl64(__m128i x, int32_t offset)
        {
            return _mm_or_si128( _mm_slli_epi64(x, offset), _mm_srli_epi64(x, 64 - offset));
        }

        __m128i inline multiply64Bit(__m128i a, __m128i b)
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

        void printValue(__m128i var);
    };
};

#endif