#include "testingmanager.h"

TestingManager::TestingManager()
{
    this->extensionManager = new ExtensionManager();
}

TestingManager::~TestingManager()
{
    delete this->extensionManager;
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
    // this->arrayManager = new ArrayManager(test.getArraySize());
    this->arrayManager = new ArrayManager(test.getArraySize() - (test.getArraySize() % 4));
    this->minHash = this->extensionManager->getMinHashInstance(test.getExtension());

    auto start = std::chrono::steady_clock::now();
	minHash->count
    (
        this->arrayManager->getInputArray(),
        this->arrayManager->getOutputArray(),
        this->arrayManager->getSize()
    );
    auto finish = std::chrono::steady_clock::now();
    auto elapsed = finish - start;

    TestingResult testingResult = TestingResult(test, elapsed);

    delete this->arrayManager;
    this->arrayManager = nullptr;

    delete this->minHash;
    this->minHash = nullptr;

    return testingResult;
}

std::vector<TestingResult> & TestingManager::getTestingResults()
{
    return this->testingResults;
}