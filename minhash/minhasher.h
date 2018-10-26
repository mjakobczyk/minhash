#ifndef MINHASHER_H_
#define MINHASHER_H_
#include <iostream>

namespace minhash
{
    class MinHasher
    {
    public:
        virtual ~MinHasher() {}
        
        virtual uint64_t minHash(uint64_t);
        virtual uint64_t fmix64(uint64_t);
        virtual uint64_t rotl64(uint64_t, int32_t);
    };
};

#endif