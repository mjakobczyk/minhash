#ifndef ARRAYMANAGER_H_
#define ARRAYMANAGER_H_
#include "arraygenerator.h"
#include <random>

class ArrayManager
{
public:
    ArrayManager(int);
    uint64_t * getInputArray();
    uint64_t * getOutputArray();

private:
    ArrayGenerator arrayGenerator;
    uint64_t *input, *output;
    unsigned int size;
    unsigned int aligner;
};

#endif