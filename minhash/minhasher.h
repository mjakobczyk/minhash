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
        
        virtual void minHash(uint64_t*&, uint64_t*&, int) = 0;
        int getElementsInOneCall();

    protected:
        uint64_t k;
        uint64_t k_div_4;
        uint64_t c42_xor_k_div_4;
        int elementsInOneCall;

        const uint64_t firstConstValue = 0x87c37b91114253d5ull;
        const uint64_t secondConstValue = 0x4cf5ad432745937full;
        const uint64_t thirdConstValue = 0xff51afd7ed558ccdull;
        const uint64_t fourthConstValue = 0xc4ceb9fe1a85ec53ull;
    };
};

#endif