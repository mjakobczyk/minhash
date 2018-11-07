#include "arraymanager.h"

ArrayManager::ArrayManager(int size_) :
    size(size_)
{
    this->aligner = 256;
    this->input = this->arrayGenerator.generateRandomUint64Array(this->size);
    this->output = new uint64_t[this->size + this->aligner];
}

uint64_t * ArrayManager::getInputArray()
{
    // uint64_t * alignedInputArray = (this->input + this->aligner - 1) % aligner;
}

uint64_t * ArrayManager::getOutputArray()
{
    return this->output;
}