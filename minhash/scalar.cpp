#include "scalar.h"
#include "minhasher.h"
#include <cmath>

minhash::Scalar::Scalar() : minhash::MinHasher() 
{
    this->elementsInOneCall = 1;
}

minhash::Scalar::~Scalar() {}

void minhash::Scalar::printValue(uint64_t x)
{
    printf("%" PRIu64 "\n", x);
}