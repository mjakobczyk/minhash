#ifndef MINHASH_H_
#define MINHASH_H_
#include <iostream>

namespace minhash
{
    class MinHash
    {
     uint64_t* input, output;
        
    public:
        MinHash(uint64_t*, uint64_t*);
    };
};

#endif