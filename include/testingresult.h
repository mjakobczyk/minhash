#ifndef TESTINGRESULT_H_
#define TESTINGRESULT_H_
#include "testingcase.h"

class TestingResult
{
public:
    TestingResult(TestingCase, std::chrono::duration<double>);
    TestingCase getTestingCase();
    void setTestingCase(const TestingCase);
    std::chrono::duration<double> getExecutionTime();
    void setExecutionTime(const std::chrono::duration<double> &);

private:
    TestingCase testingCase;
    std::chrono::duration<double> executionTime;
};

#endif