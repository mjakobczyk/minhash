#ifndef OSDETECTOR_H
#define OSDETECTOR_H

/*
 OSType describes types of operating systems that application 
*/
enum OSType
{
	WINDOWS = 0,
	LINUX,
	MACOS,
	UNKNOWN
};

/*
 OSDetector checks operating system that application runs on.
*/
class OSDetector
{
public:
	OSType checkOS();
};

#endif
