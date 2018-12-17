#include "testingmanager.h"

TestingManager::TestingManager()
{
    this->extensionManager = new ExtensionManager();
}

void TestingManager::runAllTests(std::vector<TestingCase> & testingCases)
{
    for (auto & test : testingCases)
    {
        TestingResult testingResult = this->runSingleTest(test);
        this->testingResults.push_back(testingResult);
    }
}

TestingResult TestingManager::runSingleTest(TestingCase test)
{
    this->arrayManager = new ArrayManager(test.getArraySize());
    this->minHash = this->extensionManager->getMinHashInstance(test.getExtension());

    auto start = std::chrono::high_resolution_clock::now();
	minHash->count
    (
        this->arrayManager->getInputArray(),
        this->arrayManager->getOutputArray(),
        this->arrayManager->getSize()
    );
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    delete this->arrayManager;
    this->arrayManager = nullptr;

    delete this->minHash;
    this->minHash = nullptr;
}

std::vector<TestingResult> & TestingManager::getTestingResults()
{
    return this->testingResults;
}