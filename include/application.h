#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "arraymanager.h"
#include "extensiondetector.h"
#include "osdetector.h"
#include "minhasher.h"
#include <chrono>
#include "minhash.h"

#define DEFAULT_ARRAY_SIZE 10000000
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
    void minhashWithExtension(Extension);
    void showSummary(Extension, std::chrono::duration<double>);

private:
    ArrayManager * arrayManager;
    ExtensionDetector exDetector;
    Extension extension;
    minhash::MinHash * minHash;
    OSDetector osDetector;
};

#endif