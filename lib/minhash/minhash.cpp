#include <iostream>

MinHash::MinHash(MinHasher* minHasher_)
{
    this.minHasher = minHasher_;
}

bool MinHash::count(uint64_t* input,uint64_t* output, int size)
{
    this.minHasher.minHash(input, output, size);
}