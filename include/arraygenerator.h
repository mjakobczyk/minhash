#ifndef ARRAYGENERATOR_H_
#define ARRAYGENERATOR_H_
#include <iostream>
#include <random>
#include <ctime>

class ArrayGenerator
{
    unsigned int seed;
    std::mt19937_64 engine;
    std::uniform_int_distribution<uint64_t> distribution;

public:
    ArrayGenerator();
    uint64_t * generateRandomUint64Array(int amount);

private:
    uint64_t generateRandomUint64();
};

#endif