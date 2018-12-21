#include "testingresult.h"

TestingResult::TestingResult(TestingCase testingCase_, std::chrono::duration<double> executionTime_) :
    testingCase(testingCase_)
{
    this->executionTime = executionTime_;
}

TestingCase TestingResult::getTestingCase()
{
    return this->testingCase;
}

std::chrono::duration<double> TestingResult::getExecutionTime()
{
    return this->executionTime;
}