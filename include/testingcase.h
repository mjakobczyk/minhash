#ifndef TESTINGCASE_H_
#define TESTINGCASE_H_
#include <string>
#include <vector>
#include <extensiondetector.h>

/**
 * TestingCase is a combination of extention type and array length which
 * represents a single test to run in the application.
 **/
class TestingCase
{
public:
    // Constructor that takes extension type and array length as parameters.
    TestingCase(Extension, unsigned int);

    // Gets extension type defined in testing case.
    Extension getExtension();

    // Gets array length defined in testing case.
    unsigned int getArraySize();
    
private:
    Extension extension;
    unsigned int arraySize;
};

#endif