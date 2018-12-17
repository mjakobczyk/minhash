#include "testingmanager.h"

void TestingManager::runTests(std::vector<TestingCase> & testingCases)
{
    for (auto & test : testingCases)
    {
        this->performTest(test);
    }
}

void TestingManager::performTest(const TestingCase & test)
{
    if (this->arrayManager != nullptr)
    {
        delete arrayManager;
    }

    this->arrayManager = new ArrayManager(test.getArraySize);

    delete this->arrayManager;
    this->arrayManager = nullptr;
}