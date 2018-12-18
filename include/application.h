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

class Application
{
public:
    Application(int, char*[]);
    ~Application();

    void run();
    void runDefaultTests();

private:
    std::chrono::duration<double> getExecutionTime();
    void showSummary(TestingResult testingResult);

private:
    ArgManager * argManager;
    ExtensionDetector * extensionDetector;
    FileManager * fileManager;
    OSDetector * osDetector;
    TestingManager * testingManager;
};

#endif