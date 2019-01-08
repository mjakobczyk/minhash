#ifndef MINHASHER_H_
#define MINHASHER_H_
#include <iostream>

namespace minhash
{
    /**
     * MinHasher is an abstract class which decribes the way that MinHash
     * should be count.
     **/
    class MinHasher
    {
    public:
        MinHasher();
        // Constructor that takesa as parameters k parameter used to describing
        // k-mer inside the algorithm and amount of elements that should be passed
        // in a single method call.
        MinHasher(int, int);
        virtual ~MinHasher();
        
        // Method used for counting MinHash values. Parameters are: pointer to the
        // input array (containing values), pointer to the output values (where
        // resulting values should be stored) and size of both arrays (that has
        // to be the same).
        virtual void minHash(uint64_t*&, uint64_t*&, int) = 0;

        // Gets amount of elements that can be count in a single iteration of the loop.
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