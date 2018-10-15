#include "extensiondetector.h"
#include <iostream>
#include <vector>

std::vector<Extension> ExtensionDetector::checkAvailableExtensions()
{
    std::cout << "> [SIMD]:" << std::endl;
    std::vector<Extension> availableExtensions;
    
    if (isSSE2Available())
    {
                std::cout << ">>> [SSE2] available" << std::endl;
                availableExtensions.push_back(Extension::SSE2);
    }
    else
    {
                std::cout << ">>> [SSE2] not available" << std::endl;

    }
    if (isAVXAvailable())
    {
                std::cout << ">>> [AVX]  available" << std::endl;
                availableExtensions.push_back(Extension::AVX);
    }
    else
    {
                std::cout << ">>> [AVX]  not available" << std::endl;
    }
    if (isAVX2Available())
    {
                std::cout << ">>> [AVX2] available" << std::endl;
                availableExtensions.push_back(Extension::AVX2);
    }
    else
    {
                std::cout << ">>> [AVX2] not available" << std::endl;
    }

    return availableExtensions;
}

bool ExtensionDetector::isSIMDAvailable()
{
    // #if defined(BOOST_HW_SIMD_X86_AVAILABLE)
    //     return true;
    // #endif

    return false;
}

bool ExtensionDetector::isSSE2Available()
{
    // #if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE2_VERSION
    //     return true;
    // #endif

    return false;
}

bool ExtensionDetector::isAVXAvailable()
{
    // #if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION    
    //     return true;
    // #endif

    return false;
}

bool ExtensionDetector::isAVX2Available()
{
    // #if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX2_VERSION
    //     return true;
    // #endif

    return false;
}