#ifndef MINHASHER_H_
#define MINHASHER_H_
#include <iostream>

namespace minhash
{
    class MinHasher
    {
    public:
        MinHasher();
        MinHasher(int);
        virtual ~MinHasher();
        
        virtual inline uint64_t minHash(uint64_t) = 0;
        virtual inline uint64_t fmix64(uint64_t) = 0;
        virtual inline uint64_t rotl64(uint64_t, int32_t) = 0;

    protected:
        uint64_t k;
        uint64_t k_div_4;
        uint64_t c42_xor_k_div_4;

    };
};

#endif