#include "osdetector.h"
#include "extensiondetector.h"

int main()
{
	OSDetector osDetector;
	osDetector.checkOS();

	ExtensionDetector exDetector;
	exDetector.checkAvailableExtensions();
	
	return 0;
}
