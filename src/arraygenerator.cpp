#include "arraygenerator.h"

ArrayGenerator::ArrayGenerator() : seed(time(0)), engine(seed), distribution(0, 33333333)
{

}

uint64_t * ArrayGenerator::generateRandomUint64Array(int amount)
{
    uint64_t * array = new uint64_t[amount];

    for (unsigned int i = 0; i < amount; ++i)
    {
        array[i] = this->generateRandomUint64();
    }

    return array;
}

uint64_t ArrayGenerator::generateRandomUint64()
{
    return this->distribution(this->engine);
}
