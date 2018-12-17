#include "testingcase.h"

TestingCase::TestingCase(const Extension extension , const unsigned int & size)
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