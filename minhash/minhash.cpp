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
        // If size % increment != 0 - consider this case
        // if (i + increment >= size)
        // {
        //   // ...
        // }

        this->minHasher->minHash(input, output, i);
    }
}