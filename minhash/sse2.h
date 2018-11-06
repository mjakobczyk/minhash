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

        virtual inline void minHash(uint64_t*, uint64_t*, int);

    private:
        __m128i inline fmix64(__m128i);
        __m128i inline rotl64( __m128i, int32_t);
        __m128i inline multiply64Bit(__m128i a, __m128i b);
        void printValue(__m128i var);
    };
};

#endif