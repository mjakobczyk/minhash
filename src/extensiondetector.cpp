#include "extensiondetector.h"
#include <boost/predef/hardware/simd.h>
#include <iostream>
#include <vector>

std::vector<Extension> ExtensionDetector::checkAvailableExtensions()
{
    std::cout << "Checking available extensions... ";
    std::vector<Extension> availableExtensions;
    
    if (isSIMDAvailable())
    {
        if (isAVXAvailable())
        {
                    std::cout << "AVX is available!" << std::endl;
                    availableExtensions.push_back(Extension::AVX);
        }
        else
        {
                    std::cout << "AVX is not available!" << std::endl;
        }
        if (isSSEAvailable())
        {
                    std::cout << "SSE is available!" << std::endl;
                    availableExtensions.push_back(Extension::SSE);

        }
        else
        {
                    std::cout << "SSE is not available!" << std::endl;

        }
        if (isSSE2Available())
        {
                    std::cout << "SSE2 is available!" << std::endl;
                    availableExtensions.push_back(Extension::SSE2);

        }
        else
        {
                    std::cout << "SSE2 is not available!" << std::endl;

        }
    }

    return availableExtensions;
}

bool ExtensionDetector::isSIMDAvailable()
{
    #if defined(BOOST_HW_SIMD_AVAILABLE)
        std::cout << "SIMD detected!" << std::endl;
        return true;
    #endif

    std::cout << "SIMD not detected!" << std::endl;
    return false;
}

bool ExtensionDetector::isAVXAvailable()
{
    #if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_AVX_VERSION
        return true;
    #endif

    return false;
}

bool ExtensionDetector::isSSEAvailable()
{
    #if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_SSE_VERSION
        return true;
    #endif

    return false;
}

bool ExtensionDetector::isSSE2Available()
{
    #if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_SSE2_VERSION
        return true;
    #endif

    return false;
}