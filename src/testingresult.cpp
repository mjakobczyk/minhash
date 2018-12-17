#include "testingresult.h"

TestingResult::TestingResult(TestingCase testingCase_, std::chrono::duration<double> executionTime_) :
    testingCase(testingCase_)
{
    // this->testingCase = TestingCase(testingCase_);
    this->executionTime = executionTime_;
}

TestingCase TestingResult::getTestingCase()
{
    return this->testingCase;
}

void TestingResult::setTestingCase(const TestingCase testingCase_)
{
    this->testingCase = testingCase_;
}

std::chrono::duration<double> TestingResult::getExecutionTime()
{
    return this->executionTime;
}

void TestingResult::setExecutionTime(const std::chrono::duration<double> & executionTime_)
{
    this->executionTime = executionTime_;
}