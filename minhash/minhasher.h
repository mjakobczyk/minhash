#ifndef MINHASHER_H_
#define MINHASHER_H_
#include <iostream>

namespace minhash
{
    class MinHasher
    {
    public:
        virtual ~MinHasher() {}
        virtual void minHash(uint64_t[], uint64_t[], const int) = 0;
    };
};

#endif