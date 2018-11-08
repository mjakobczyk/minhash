#include "avx2.h"

minhash::AVX2::AVX2() : minhash::MinHasher() 
{
    this->elementsInOneCall = 4;
}

minhash::AVX2::~AVX2() {}
