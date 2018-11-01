#include "minhasher.h"
#include <math.h>

minhash::MinHasher::MinHasher()
{
    this->k = 20;
    this->k_div_4 = (uint64_t)ceil((double)this->k/ 4);
    this->c42_xor_k_div_4 = 42 ^ this->k_div_4;
    this->elementsInOneCall = 1;
}

minhash::MinHasher::MinHasher(int k_, int elementsInOneCall_)
{
    this->k = k_;
    this->k_div_4 = (uint64_t)ceil((double)this->k/ 4);
    this->c42_xor_k_div_4 = 42 ^ this->k_div_4;
    this->elementsInOneCall = elementsInOneCall_;
}

int minhash::MinHasher::getElementsInOneCall()
{
    return this->elementsInOneCall;
}


minhash::MinHasher::~MinHasher() {}