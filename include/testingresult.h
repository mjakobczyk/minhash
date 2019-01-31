#ifndef TESTINGRESULT_H_
#define TESTINGRESULT_H_
#include "testingcase.h"
#include <chrono>   

/**
 * TestingResult contains information about performed testing case and its results.
 **/
class TestingResult
{
public:
    // Constructor taking as parameters testing case and its execution time.
    TestingResult(TestingCase, std::chrono::duration<double>);

    // Returns testing case defined for testing result.
    TestingCase getTestingCase();

    // Returns execution time of the performed testing case.
    std::chrono::duration<double> getExecutionTime();

private:
    TestingCase testingCase;
    std::chrono::duration<double> executionTime;
};

#endif