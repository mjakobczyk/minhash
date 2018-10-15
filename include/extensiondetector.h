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
    AVX2
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

private:
    bool isSSE2Available(int);
    bool isAVXAvailable(int);
    bool isAVX2Available(int);
};

#endif
