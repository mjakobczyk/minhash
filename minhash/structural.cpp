#include "structural.h"
#include "minhasher.h"
#include <cmath>

minhash::Structural::Structural() : minhash::MinHasher() 
{
    this->elementsInOneCall = 1;
}

minhash::Structural::~Structural() {}

void minhash::Structural::printValue(uint64_t x)
{
    printf("%" PRIu64 "\n", x);
}