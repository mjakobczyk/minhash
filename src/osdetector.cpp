#include "osdetector.h"
#include <iostream>
#include <boost/predef.h>

OSType OSDetector::checkOS()
{
	std::cout << "Operating system: ";	

	if(BOOST_OS_WINDOWS)
	{
        std::cout << "Windows" << std::endl;
		return OSType::WINDOWS;
    }
	else if(BOOST_OS_LINUX)
	{
        std::cout << "Linux" << std::endl;
    	return OSType::LINUX;
	}
	else if(BOOST_OS_MACOS)
	{	
		std::cout << "MacOS" << std::endl;
		return OSType::MACOS;
	}
	else
	{
        std::cout << "Unknown" << std::endl;
		return OSType::UNKNOWN;
	}	
};
