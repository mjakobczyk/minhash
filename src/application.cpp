#include "application.h"
#include "extension.h"
#include "minhasher.h"
#include "scalar.h"
#include "sse2.h"
#include "avx2.h"
#include "testingmanager.h"
#include "testingcase.h"
#include "testingresult.h"
#include <inttypes.h>
#include <string.h>
#include "test/addition.h"
#include "test/multiplication.h"
#include "test/xor.h"
#include "test/rotl.h"

Application::Application(int argc, char* argv[])
{
    this->argManager = new ArgManager(argc, argv);
    this->testingManager = new TestingManager();
    this->fileManager = nullptr;
    this->osDetector = new OSDetector();
    this->extensionDetector = new ExtensionDetector();
}

Application::~Application() 
{
    delete this->argManager;
    delete this->testingManager;
    delete this->osDetector;
    delete this->extensionDetector;
}

void Application::run()
{
    this->osDetector->checkOS();
    this->extensionDetector->checkAvailableExtensions();

    if (this->argManager->shouldRunPerformanceTests())
    {
        std::cout << "Running performance tests..." << std::endl;
        this->runPerformanceTests();
        std::cout << "Completed performance tests." << std::endl;
        return;
    }

    if (this->argManager->shouldRunUnitTests())
    {
        TestAllAddImpl();
        TestAllMulImpl();
        TestAllXorImpl();
        TestAllRotlImpl();
        return;
    }

    std::string inputFile = this->argManager->getInputFileName();

    if (inputFile == "")
    {
        std::cout << "Incorrect input file. Running default tests." << std::endl;
        this->runDefaultTests();
        return;
    }

    std::string outputFile = this->argManager->getOutputtFileName();

    if (outputFile == "")
    {
        std::cout << "Incorrect output file. Creating file: output.txt." << std::endl;
        outputFile = "output.txt";
    }

    this->fileManager = new FileManager(inputFile, outputFile);
    auto tests = this->fileManager->readDataFromInputFile();

    if (tests.empty())
    {
        std::cout << "No data was provided. Running default tests." << std::endl;
        this->runDefaultTests();
        return;
    }

    this->testingManager->runAllTests(tests);
    auto results = this->testingManager->getTestingResults();
    auto didWrite = this->fileManager->writeDataToOutputFile(results);
    if (!didWrite)
    {
        std::cout << "Failed writing results to output file." << std::endl;
    }

    std::cout << "Successfully wrote data to output file." << std::endl;
}

void Application::runDefaultTests()
{
    std::vector<TestingCase> tests;
    TestingCase case1 = TestingCase(Extension::NONE, DEFAULT_ARRAY_SIZE);
    TestingCase case2 = TestingCase(Extension::SSE2, DEFAULT_ARRAY_SIZE);
    TestingCase case3 = TestingCase(Extension::AVX2, DEFAULT_ARRAY_SIZE);
    tests.push_back(case1);
    tests.push_back(case2);
    tests.push_back(case3);
    this->testingManager->runAllTests(tests);
    auto results = testingManager->getTestingResults();
    for (auto & result : results)
    {
        this->showTestingResultSummary(result);
    }
}

void Application::runPerformanceTests()
{
    std::vector<TestingResult> results;
    std::cout << "Completed steps (out of 15): ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::NONE, 10000), 100, "scalar-10000arr-100t.txt")); std::cout << "1 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::SSE2, 10000), 100, "sse2-10000arr-100t.txt")); std::cout << "2 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::AVX2, 10000), 100, "avx2-10000arr-100t.txt")); std::cout << "3 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::NONE, 100000), 100, "scalar-100000arr-100t.txt")); std::cout << "4 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::SSE2, 100000), 100, "sse2-100000arr-100t.txt")); std::cout << "5 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::AVX2, 100000), 100, "avx2-100000arr-100t.txt")); std::cout << "6 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::NONE, 1000000), 100, "scalar-1000000arr-100t.txt"));  std::cout << "7 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::SSE2, 1000000), 100, "sse2-1000000arr-100t.txt")); std::cout << "8 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::AVX2, 1000000), 100, "avx2-1000000arr-100t.txt")); std::cout << "9 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::NONE, 10000000), 100, "scalar-10000000arr-100t.txt")); std::cout << "10 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::SSE2, 10000000), 100, "sse2-10000000arr-100t.txt")); std::cout << "11 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::AVX2, 10000000), 100, "avx2-10000000arr-100t.txt")); std::cout << "12 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::NONE, 100000000), 100, "scalar-100000000arr-100t.txt")); std::cout << "13 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::SSE2, 100000000), 100, "sse2-100000000arr-100t.txt")); std::cout << "14 ";
    results.push_back(this->runSpecificPerformanceTest(TestingCase(Extension::AVX2, 100000000), 100, "avx2-100000000arr-100t.txt")); std::cout << "15 ";
    std::cout << std::endl;
    this->showAllTestingResultsSummary(results);
}

TestingResult Application::runSpecificPerformanceTest(TestingCase testingCase, int iterations, const std::string & resultingFileName)
{
    std::vector<TestingCase> tests;
    for (unsigned int i = 0; i < iterations; ++i)
    {
        tests.push_back(testingCase);
    }

    TestingManager * performanceTestingManager = new TestingManager();
    performanceTestingManager->runAllTests(tests);
    auto results = performanceTestingManager->getTestingResults();
    delete performanceTestingManager;

    std::vector<std::chrono::duration<double>> executions;
    std::chrono::duration<double> sumOfExecutions;
    for (auto & result : results)
    {
        sumOfExecutions += result.getExecutionTime();
        executions.push_back(result.getExecutionTime());
    }

    std::chrono::duration<double> averageExecution = (std::chrono::duration<double>) sumOfExecutions / executions.size();
    TestingResult testingResult = TestingResult(testingCase, averageExecution);

    FileManager * performanceFileManager = new FileManager("", resultingFileName);
    performanceFileManager->writeDataToOutputFile(executions);
    delete performanceFileManager;

    tests.clear();
    executions.clear();
    sumOfExecutions.zero();
    averageExecution.zero();
    
    return testingResult;
}

std::string Application::getStringFromExtension(Extension extension)
{
    std::string ext;
    switch (extension)
    {
        case Extension::SSE2:
            ext = "SSE2";
            break;
        case Extension::AVX:
        case Extension::AVX2:
            ext = "AVX2";
            break;
        case Extension::NONE:
        default:
            ext = "Scalar";
            break;
    }

    return ext;
}

void Application::showTestingResultSummary(TestingResult testingResult)
{
    std::cout << this->getStringFromExtension(testingResult.getTestingCase().getExtension()) << "\t" 
              <<  testingResult.getTestingCase().getArraySize()
              << "  " << testingResult.getExecutionTime().count() << "s" << std::endl;
}

void Application::showAllTestingResultsSummary(std::vector<TestingResult> & results)
{
    for (auto & result : results)
    {
        this->showTestingResultSummary(result);
    }
}
