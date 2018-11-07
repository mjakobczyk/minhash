#include "arraymanager.h"

ArrayManager::ArrayManager(int size_) :
    size(size_), aligner(ALIGN_VALUE)
{
    this->input = this->arrayGenerator.generateRandomUint64Array(this->size);
    this->output = this->arrayGenerator.generateUint64Array(this->size);
}

ArrayManager::ArrayManager(ArrayManager & second) :
    aligner(ALIGN_VALUE)
{
    this->size = (&second)->size;
    this->input = this->arrayGenerator.generateRandomUint64Array(this->size);
    for (unsigned int i = 0; i < this->size; ++i)
    {
        this->input[i] = second.input[i];
    }
    this->output = this->arrayGenerator.generateUint64Array(this->size);
    for (unsigned int i = 0; i < this->size; ++i)
    {
        this->output[i] = second.output[i];
    }
}

ArrayManager::~ArrayManager()
{
    delete [] this->input;
    delete [] this->output;
}

uint64_t *& ArrayManager::getInputArray()
{
    return this->getAlignedInputArray();
}

uint64_t *& ArrayManager::getOutputArray()
{
    return this->getAlignedOutputArray();
}

unsigned int ArrayManager::getSize()
{
    return this->size;
}


uint64_t *& ArrayManager::getAlignedInputArray()
{
    uint64_t * alignedInputArray = this->input;
    // TODO:
    // Add data aligning to the nearest 256 bits
    // alignedInputArray = (*alignedInputArray + 1023) % 1024;
    return this->input;
}

uint64_t *& ArrayManager::getAlignedOutputArray()
{
    uint64_t * alignedOutputArray = this->output;
    // TODO:
    // Add data aligning to the nearest 256 bits
    // alignedOutputArray = (alignedOutputArray + 1023) % 1024;
    return this->output;
}
