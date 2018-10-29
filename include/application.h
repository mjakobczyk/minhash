#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "arraygenerator.h"
#include "extensiondetector.h"
#include "osdetector.h"
#include "minhasher.h"
#include "minhash.h"

#define ARRAY_SIZE 10

class Application
{
public:
    Application();
    void run();

private:
    minhash::MinHash *getMinHashInstance(Extension);
    std::chrono::duration<double> getExecutionTime();
    void showResults();
    void showSummary();

private:
    OSDetector osDetector;
    ExtensionDetector exDetector;
    ArrayGenerator arrGenerator;
    Extension extension;

    uint64_t *input, *output;
    unsigned int arraySize;
    std::chrono::duration<double> executionTime;
};

#endif