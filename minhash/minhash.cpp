#include "minhash.h"

minhash::MinHash::MinHash(MinHasher* minHasher_)
{
    this->minHasher = minHasher_;
}

void minhash::MinHash::count(uint64_t* input,uint64_t* output, int size)
{
    int increment = this->minHasher->getElementsInOneCall();
    int lastCall = 0;
    
    for (unsigned int i = 0; i < size; i += increment)
    {
        // TODO
        // Move this loop to extension implementation
        // In this place simply call polymorphic
        // function just once

        this->minHasher->minHash(input, output, i);
        // std::cout << i << " ";
        // if (i % 10 == 0) std::cout << std::endl;
    }
}