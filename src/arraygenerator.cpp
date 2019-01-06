#include "arraygenerator.h"

ArrayGenerator::ArrayGenerator() : seed(time(0)), engine(seed), distribution(0, ULLONG_MAX)
{

}
uint64_t * ArrayGenerator::generateUint64Array(int size_)
{   
    uint64_t * array = new uint64_t[size_]();
    return array;
}

uint64_t * ArrayGenerator::generateRandomUint64Array(int size_)
{
    uint64_t * array = this->generateUint64Array(size_);
    
    for (unsigned int i = 0; i < size_; ++i)
    {
        array[i] = this->generateRandomUint64();
    }

    return array;
}

uint64_t ArrayGenerator::generateRandomUint64()
{
    return this->distribution(this->engine);
}
