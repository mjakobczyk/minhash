#ifndef MINHASH_H_
#define MINHASH_H_
#include <iostream>
#include "minhasher.h"

namespace minhash
{
    class MinHash
    {
    public:
        MinHash(MinHasher*);
        void count(uint64_t*, uint64_t*, int);

    private:
        MinHasher* minHasher;
    };
};

#endif