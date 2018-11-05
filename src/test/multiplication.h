#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_
#include "arraygenerator.h"
#include <cmath>
#include <emmintrin.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#define MUL_DEBUG 0

void TestStructuralMulImpl(uint64_t* input, uint64_t* output, int size);
__m128i multiply64Bit(__m128i a, __m128i b);
void TestSSE2MulImpl(uint64_t* input, uint64_t* output, int size);
void TestAllMulImpl();

#endif