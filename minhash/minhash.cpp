#include "minhash.h"

minhash::MinHash::MinHash(MinHasher* minHasher_)
{
    this->minHasher = minHasher_;
}

void minhash::MinHash::count(uint64_t* input,uint64_t* output, int size)
{
    this->minHasher->minHash(input, output, size);
}