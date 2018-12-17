#include "testingcase.h"

TestingCase::TestingCase(Extension extension, unsigned int size)
{
    this->extension = extension;
    this->arraySize = size;
}

// TestingCase::TestingCase(TestingCase & testingCase)
// {
//     this->arraySize = testingCase.getArraySize();
//     this->extension = testingCase.getExtension();
// }

Extension TestingCase::getExtension()
{
    return this->extension;
}
unsigned int TestingCase::getArraySize()
{
    return this->arraySize;
}