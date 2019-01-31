#ifndef ARRAYMANAGER_H_
#define ARRAYMANAGER_H_
#include "arraygenerator.h"
#include <random>

#define ALIGN_VALUE 256

class ArrayManager
{
public:
    // Constructor with an argument as array length.
    ArrayManager(int);

    // Constructor with an argument as another ArrayManager.
    ArrayManager(ArrayManager&);
    ~ArrayManager();
    
    // Returns input array filled with random uint64_t values.
    uint64_t *& getInputArray();

    // Returns empty output array.
    uint64_t *& getOutputArray();

    // Gets size of the arrays which are always the same.
    unsigned int getSize();

private:
    ArrayGenerator arrayGenerator;
    uint64_t *input, *output;
    unsigned int size;
    const unsigned int aligner;
};

#endif