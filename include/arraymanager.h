#ifndef ARRAYMANAGER_H_
#define ARRAYMANAGER_H_
#include "arraygenerator.h"
#include <random>

#define ALIGN_VALUE 256

class ArrayManager
{
public:
    ArrayManager(int);
    ArrayManager(ArrayManager&);
    ~ArrayManager();
    
    uint64_t *& getInputArray();
    uint64_t *& getOutputArray();
    unsigned int getSize();

private:
    uint64_t *& getAlignedInputArray();
    uint64_t *& getAlignedOutputArray();

private:
    ArrayGenerator arrayGenerator;
    uint64_t *input, *output;
    unsigned int size;
    const unsigned int aligner;
};

#endif