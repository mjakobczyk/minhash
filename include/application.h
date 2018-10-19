#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "osdetector.h"
#include "extensiondetector.h"
#include "minhasher.h"
#include "minhash.h"

#define ARRAY_SIZE 10

class Application
{
public:
    Application();
    void run();

private:
    Extension chooseExtension(std::vector<minhash::Extension>);

private:
    OSDetector osDetector;
    ExtensionDetector exDetector;

    minhash::MinHasher *minHasher;

    uint64_t *input, *output;
    unsigned int arraySize;
};

#endif