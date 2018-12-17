#ifndef TESTINGMANAGER_H_
#define TESTINGMANAGER_H_
#include "testingcase.h"
#include "arraymanager.h"
class TestingManager
{
public:
    void runTests(std::vector<TestingCase>&);

private:
    void performTest(const TestingCase &);

private:
    ArrayManager * arrayManager;
};

#endif