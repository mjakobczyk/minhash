#include "extensiondetector.h"
#include <iostream>
#include <vector>
#include "instrset.h"

std::vector<Extension> ExtensionDetector::checkAvailableExtensions()
{
    std::cout << "> [SIMD]:" << std::endl;
    std::vector<Extension> availableExtensions;

    int extensionSupport = instrset_detect();
    
    if (isSSE2Available(extensionSupport))
    {
        std::cout << ">>> [SSE2] available" << std::endl;
        availableExtensions.push_back(Extension::SSE2);
    }
    else
    {
        std::cout << ">>> [SSE2] not available" << std::endl;

    }
    if (isAVXAvailable(extensionSupport))
    {
        std::cout << ">>> [AVX]  available" << std::endl;
        availableExtensions.push_back(Extension::AVX);
    }
    else
    {
        std::cout << ">>> [AVX]  not available" << std::endl;
    }
    if (isAVX2Available(extensionSupport))
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

bool ExtensionDetector::isSSE2Available(int extensionSupport)
{
    if (extensionSupport >=2)
    {
        return true;
    }

    return false;
}

bool ExtensionDetector::isAVXAvailable(int extensionSupport)
{
    if (extensionSupport >=7)
    {
        return true;
    }

    return false;
}

bool ExtensionDetector::isAVX2Available(int extensionSupport)
{
    if (extensionSupport >=8)
    {
        return true;
    }

    return false;
}