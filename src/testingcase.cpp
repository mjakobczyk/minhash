#include "testingcase.h"

TestingCase::TestingCase(Extension extension, unsigned int size)
{
    this->extension = extension;
    this->arraySize = size;
}

Extension TestingCase::getExtension()
{
    return this->extension;
}
unsigned int TestingCase::getArraySize()
{
    return this->arraySize;
}