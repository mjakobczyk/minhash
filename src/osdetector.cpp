#include "osdetector.h"
#include <iostream>

OSType OSDetector::checkOS()
{
	std::cout << "Operating system: ";

	#if defined(_WIN64)
	{
        std::cout << "Windows" << std::endl;
		return OSType::WINDOWS;
	}
 	#elif defined(__linux__)
	{
        std::cout << "Linux" << std::endl;
    	return OSType::LINUX;
	}
	#elif defined(__APPLE__)
	{	
		std::cout << "MacOS" << std::endl;
		return OSType::MACOS;
	}
	#else
	{
     	std::cout << "Unknown" << std::endl;
		return OSType::UNKNOWN;
	}	
	#endif
};
