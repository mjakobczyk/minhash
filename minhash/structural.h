#ifndef STRUCTURAL_H_
#define STRUCTURAL_H_
#include <iostream>
#include "minhasher.h"

namespace minhash
{
    class Structural : public minhash::MinHasher
    {
    public:
        Structural();
        virtual ~Structural();

        virtual inline uint64_t minHash(uint64_t);
        virtual inline uint64_t fmix64(uint64_t);
        virtual inline uint64_t rotl64(uint64_t, int32_t);
    };
};


#endif