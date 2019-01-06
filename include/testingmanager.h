#ifndef TESTINGMANAGER_H_
#define TESTINGMANAGER_H_
#include "testingcase.h"
#include "testingresult.h"
#include "arraymanager.h"
#include "extensionmanager.h"
#include "minhash.h"

class TestingManager
{
public:
    TestingManager();
    ~TestingManager();
    void runAllTests(std::vector<TestingCase>&);
    std::vector<TestingResult> & getTestingResults();

private:
    TestingResult runSingleTest(TestingCase);

private:
    ArrayManager * arrayManager;
    ExtensionManager * extensionManager;
    minhash::MinHash * minHash;
    std::vector<TestingResult> testingResults;
};

#endif