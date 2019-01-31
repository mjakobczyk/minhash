#ifndef TESTINGMANAGER_H_
#define TESTINGMANAGER_H_
#include "testingcase.h"
#include "testingresult.h"
#include "arraymanager.h"
#include "extensionmanager.h"
#include "minhash.h"

/**
 * TestingManager performs tests in application.
 **/
class TestingManager
{
public:
    // Default constructor of the application.
    TestingManager();
    ~TestingManager();

    // Runs all tests defined in passed vector of testing cases. 
    void runAllTests(std::vector<TestingCase>&);

    // Returns vector containg results of defined testing cases.
    std::vector<TestingResult> & getTestingResults();

private:
    // Run single testing case and returns its results.
    TestingResult runSingleTest(TestingCase);

private:
    ArrayManager * arrayManager;
    ExtensionManager * extensionManager;
    minhash::MinHash * minHash;
    std::vector<TestingResult> testingResults;
};

#endif