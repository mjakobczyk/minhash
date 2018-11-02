#ifndef SSE2_H_
#define SSE2_H_
#include "minhasher.h"
#include <immintrin.h>

#define DEBUG true

namespace minhash
{
    class SSE2 : public minhash::MinHasher
    {
    public:
        SSE2();
        virtual ~SSE2();

        virtual inline void minHash(uint64_t*, uint64_t*, int);

    private:
        __m128i fmix64(__m128i);
        __m128i rotl64( __m128i, int32_t);
        void printValue(__m128i var);
    };
};

#endif