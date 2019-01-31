#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "arraymanager.h"
#include "extensiondetector.h"
#include "osdetector.h"
#include "minhasher.h"
#include "minhash.h"
#include "argmanager.h"
#include "testingmanager.h"
#include "filemanager.h"
#include <chrono>

#define DEFAULT_ARRAY_SIZE 10000000
#define DEBUG 0

/**
 * Application class manages entire project.
 **/
class Application
{
public:
    // Constructor which takes argument count and arguments from commands line.
    Application(int, char*[]);
    ~Application();

    // Starts the application.
    void run();

    // Runs default tests for every MinHash implementation.
    void runDefaultTests();

    // Runs series of performance tests for every MinHash implementation
    // and custom array lengths.
    void runPerformanceTests();

private:
    // Runs specific performance test with custom conditions.
    TestingResult runSpecificPerformanceTest(TestingCase, int, const std::string &);

    // Shows summary for a specific testing result.
    void showTestingResultSummary(TestingResult testingResult);

    // Shows summary for all gathered testing results.
    void showAllTestingResultsSummary(std::vector<TestingResult> &);

    // Gets string representation of specific extension.
    std::string getStringFromExtension(Extension extension);

    ArgManager * argManager;
    ExtensionDetector * extensionDetector;
    FileManager * fileManager;
    OSDetector * osDetector;
    TestingManager * testingManager;
};

#endif