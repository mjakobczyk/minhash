#ifndef TESTINGCASE_H_
#define TESTINGCASE_H_
#include <string>
#include <vector>
#include <extensiondetector.h>

class TestingCase
{
public:
    TestingCase(const Extension, const unsigned int &);
    Extension getExtension();
    unsigned int getArraySize();
    
private:
    Extension extension;
    unsigned int arraySize;
};

#endif