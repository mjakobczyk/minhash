#ifndef XOR_H_
#define XOR_H_
#include "arraygenerator.h"
#include <cmath>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <emmintrin.h> // SSE2
#include <immintrin.h> // AVX2

#define XOR_DEBUG 1

void TestStructuralXorImpl(uint64_t* input, uint64_t* output, int size);
void TestSSE2XorImpl(uint64_t* input, uint64_t* output, int size);
void TestAVXXorImpl(uint64_t* input, uint64_t* output, int size);
void TestAVX2XorImpl(uint64_t* input, uint64_t* output, int size);
void TestAllXorImpl();

#endif