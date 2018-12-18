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
    this->osDetector = new OSDetector();
    this->extensionDetector = new ExtensionDetector();
}

Application::~Application() 
{
    delete this->argManager;
    delete this->testingManager;
}

void Application::run()
{
    this->osDetector->checkOS();
    this->extensionDetector->checkAvailableExtensions();

    std::string inputFile = this->argManager->getInputFileName();
    std::string outputFile = this->argManager->getOutputtFileName();

    if (inputFile == "")
    {
        std::cout << "No input file provided. Running default tests." << std::endl;
        this->runDefaultTests();
    }
    else
    {
        // ...
    }
}

void Application::runDefaultTests()
{
    std::vector<TestingCase> tests;
    TestingCase case4 = TestingCase(Extension::AVX2, 10);
    TestingCase case1 = TestingCase(Extension::NONE, 10000000);
    TestingCase case2 = TestingCase(Extension::SSE2, 10000000);
    TestingCase case3 = TestingCase(Extension::AVX2, 10000000);
    tests.push_back(case1);
    tests.push_back(case2);
    tests.push_back(case3);
    this->testingManager->runAllTests(tests);
    auto results = testingManager->getTestingResults();
    for (auto & result : results)
    {
        std::cout << result.getExecutionTime().count() << std::endl;
    }
}

// void Application::showSummary(Extension extension, std::chrono::duration<double> elapsed)
// {
//     std::cout << "[SUMMARY INFO]" << std::endl;
//     std::cout << "Array size = " << this->arrayManager->getSize() << std::endl;
//     std::string ext;
//     switch (extension)
//     {
//         case Extension::SSE2:
//             ext = "SSE2";
//             break;
//         case Extension::AVX:
//         case Extension::AVX2:
//             ext = "AVX2";
//             break;
//         case Extension::NONE:
//         default:
//             ext = "Scalar";
//             break;
//     }
//     std::cout << "Extension: " << ext << std::endl;
//     std::cout << "Execution time: " << elapsed.count() << "s" << std::endl << std::endl;
// }