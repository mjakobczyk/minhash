#ifndef OSDETECTOR_H
#define OSDETECTOR_H

enum OSType
{
	WINDOWS = 0,
	LINUX
}

class OSDetector
{
public:
	OSType checkOS();
}

#endif