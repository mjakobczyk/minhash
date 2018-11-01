#ifndef SSE2_H_
#define SSE2_H_

#include "minhasher.h"

namespace minhash
{
    class SSE2 : public minhash::MinHasher
    {
    public:
        SSE2();
        virtual ~SSE2();

        virtual inline void minHash(uint64_t*, uint64_t*, int);

    private:
        uint64_t fmix64(uint64_t);
        uint64_t rotl64(uint64_t, int32_t);
    };

};

#endif