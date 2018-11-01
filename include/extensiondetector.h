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

// std::ostream& operator<<(std::ostream& os, Extension e)
// {
//     switch(e)
//     {
//         case SSE2   : os << "SSE2";    break;
//         case AVX    : os << "AVX" ;    break;
//         case AVX2   : os << "AVX2";    break;
//         case NONE   : os << "NONE";    break;
//         // default    : os.setstate(std::ios_base::failbit);
//         default     : os << "NONE";    break;
//     }
//     return os;
// }

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
