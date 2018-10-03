#ifndef EXTENSIONDETECTOR_H_
#define EXTENSIONDETECTOR_H_

#include <vector>

enum Extension
{
    AVX = 0,
    SSE,
    SSE2
};

class ExtensionDetector
{

public:
    std::vector<Extension> checkAvailableExtensions();

private:
    bool isSIMDAvailable();
    bool isAVXAvailable();
    bool isSSEAvailable();
    bool isSSE2Available();
};

#endif
