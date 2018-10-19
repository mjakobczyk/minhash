#ifndef EXTENSIONDETECTOR_H_
#define EXTENSIONDETECTOR_H_

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
    std::vector<Extension> checkAvailableExtensions();
    Extension chooseExtension();


private:
    bool isSSE2Available(int);
    bool isAVXAvailable(int);
    bool isAVX2Available(int);
};

#endif
