#ifndef STRUCTURAL_H_
#define STRUCTURAL_H_
#include <iostream>
#include "minhasher.h"
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#define DEBUG 0

namespace minhash
{
    class Structural : public minhash::MinHasher
    {
    public:
        Structural();
        virtual ~Structural();

        virtual inline void minHash(uint64_t*, uint64_t*, int);

    private:
        uint64_t fmix64(uint64_t);
        uint64_t rotl64(uint64_t, int32_t);
        void printValue(uint64_t);
    };
};


#endif