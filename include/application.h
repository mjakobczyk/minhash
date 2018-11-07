#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "arraymanager.h"
#include "extensiondetector.h"
#include "osdetector.h"
#include "minhasher.h"
#include <chrono>
#include "minhash.h"

#define DEFAULT_ARRAY_SIZE 1000
#define DEBUG 0

class Application
{
public:
    Application();
    Application(int);
    ~Application();

    void run();

private:
    minhash::MinHash *getMinHashInstance(Extension);
    std::chrono::duration<double> getExecutionTime();
    void showSummary();

private:
    OSDetector osDetector;
    ExtensionDetector exDetector;
    ArrayManager arrayManager;
    Extension extension;
    std::chrono::duration<double> executionTime;
};

#endif