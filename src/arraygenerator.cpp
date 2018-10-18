#include "arraygenerator.h"

ArrayGenerator::ArrayGenerator() : seed(time(0)), engine(seed), distribution(0, 33333333)
{
    // this->seed = time(0);
    // this->engine(this->seed);
    // this->distribution(0, UINT64_MAX);
}

uint64_t * ArrayGenerator::generateRandomUint64Array(int amount)
{
    // https://gist.github.com/PhDP/5289449
    uint64_t * array = new uint64_t[2];
    return array;
}

uint64_t ArrayGenerator::generateRandomUint64()
{
    std::cout << "Generating... ";
    std::cout << this->distribution(this->engine);
    return 1;
}
