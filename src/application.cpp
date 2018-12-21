#include "application.h"
#include "extension.h"
#include "minhasher.h"
#include "structural.h"
#include "sse2.h"
#include "avx2.h"
#include "testingmanager.h"
#include "testingcase.h"
#include "testingresult.h"
#include <inttypes.h>
#include <string.h>

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
        this->showSummary(result);
    }
}

void Application::showSummary(TestingResult testingResult)
{
    std::string ext;
    switch (testingResult.getTestingCase().getExtension())
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

    std::cout << ext << "\t" <<  testingResult.getTestingCase().getArraySize()
              << "  " << testingResult.getExecutionTime().count() << "s" << std::endl;
}