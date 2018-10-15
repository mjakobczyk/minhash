#include "osdetector.h"
#include "extensiondetector.h"
#include <iostream>
#include <immintrin.h>

int main()
{
	OSDetector osDetector;
	osDetector.checkOS();

	ExtensionDetector exDetector;
	exDetector.checkAvailableExtensions();

	char stopper;
	std::cin >> stopper;
	
	return 0;
}
