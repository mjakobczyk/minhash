#ifndef XOR_H_
#define XOR_H_
#include "arraygenerator.h"
#include <cmath>
#include <emmintrin.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#define XOR_DEBUG 0

void TestStructuralXorImpl(uint64_t* input, uint64_t* output, int size);
void TestSSE2XorImpl(uint64_t* input, uint64_t* output, int size);
void TestAllXorImpl();

#endif