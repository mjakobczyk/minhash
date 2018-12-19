#ifndef MINHASHER_H_
#define MINHASHER_H_
#include <iostream>

namespace minhash
{
    class MinHasher
    {
    public:
        MinHasher();
        MinHasher(int, int);
        virtual ~MinHasher();
        
        virtual void minHash(uint64_t*, uint64_t*, int) = 0;
        int getElementsInOneCall();

    protected:
        uint64_t k;
        uint64_t k_div_4;
        uint64_t c42_xor_k_div_4;
        int elementsInOneCall;
    };
};

#endif