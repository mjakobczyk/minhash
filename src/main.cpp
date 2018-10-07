#include "osdetector.h"
#include "extensiondetector.h"
#include <iostream>

int main()
{
	std::cout << "Hello world!" << std::endl;

	OSDetector osDetector;
	osDetector.checkOS();

	ExtensionDetector exDetector;
	exDetector.checkAvailableExtensions();

	char stopper;
	std::cin >> stopper;
	
	return 0;
}
