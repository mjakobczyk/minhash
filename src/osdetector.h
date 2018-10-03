#ifndef OSDETECTOR_H
#define OSDETECTOR_H

enum OSType
{
	WINDOWS = 0,
	LINUX,
	MACOS,
	UNKNOWN
};

class OSDetector
{
public:
	OSType checkOS();
};

#endif
