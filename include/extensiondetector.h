#ifndef EXTENSIONDETECTOR_H_
#define EXTENSIONDETECTOR_H_
#include <iostream>
#include <vector>

/*
 Extension represents increment to the x86 instruction set architecture.
*/
enum Extension
{
    SSE2 = 0,
    AVX,
    AVX2,
    NONE,
};

/*
 ExtensionDetector checks SIMD availability. In case processor supports
 SIMD instructions then it validates support for certain extensions
 listed in Extension enum.
*/
class ExtensionDetector
{
public:
    // Checks extensions supported by processor.
    // Returns vector containing list of them.
    std::vector<Extension> checkAvailableExtensions();

    // Runs algorithm performing decision for choosing extension.
    Extension chooseExtension();

private:
    bool isSSE2Available(int);
    bool isAVXAvailable(int);
    bool isAVX2Available(int);
};

#endif
