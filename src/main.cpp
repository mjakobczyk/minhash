#include "osdetector.h"
#include "extensiondetector.h"
#include <iostream>
#include <immintrin.h>

int main()
{
	std::cout << "Hello world!" << std::endl;

	OSDetector osDetector;
	osDetector.checkOS();

	ExtensionDetector exDetector;
	exDetector.checkAvailableExtensions();

	__m128i v1 = _mm_set_epi32(1, 1, 1, 1);
	__m128i v2 = _mm_set1_epi32(2);
	__m128i v3 = _mm_add_epi32(v1, v2);

	int tab[4];

	char stopper;
	std::cin >> stopper;
	
	return 0;
}
