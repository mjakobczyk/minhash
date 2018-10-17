#include "osdetector.h"
#include "extensiondetector.h"
#include <iostream>
#include <immintrin.h>
#include "structural.h"
#include "minhash.h"
using namespace minhash;

int main()
{
	OSDetector osDetector;
	osDetector.checkOS();

	ExtensionDetector exDetector;
	exDetector.checkAvailableExtensions();

	char stopper;
	std::cin >> stopper;

	MinHasher* minHasher = new Structural();
	MinHash minHash(minHasher);
	uint64_t* in, *out;
	int size;
	minHash.count(in, out, size);
	
	return 0;
}
