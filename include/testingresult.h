#ifndef TESTINGRESULT_H_
#define TESTINGRESULT_H_
#include "testingcase.h"
#include <chrono>   

class TestingResult
{
public:
    TestingResult(TestingCase, std::chrono::duration<double>);
    TestingCase getTestingCase();
    std::chrono::duration<double> getExecutionTime();

private:
    TestingCase testingCase;
    std::chrono::duration<double> executionTime;
};

#endif