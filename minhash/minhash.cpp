#include "minhash.h"

minhash::MinHash::MinHash(MinHasher* minHasher_)
{
    this->minHasher = minHasher_;
}

void minhash::MinHash::count(uint64_t* input,uint64_t* output, int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        uint64_t temp = input[i];

        output[i] = this->minHasher->minHash(temp);
    }
}