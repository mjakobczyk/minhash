#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_
#include "arraygenerator.h"
#include <cmath>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <emmintrin.h> // SSE2
#include <immintrin.h> // AVX2

#define MUL_DEBUG 0

__m128i SSE2Multiply64Bit(__m128i a, __m128i b);
__m256i AVX2multiply64Bit(__m256i a, __m256i b);

void TestStructuralMulImpl(uint64_t* input, uint64_t* output, int size);
void TestSSE2MulImpl(uint64_t* input, uint64_t* output, int size);
void TestAVXMulImpl(uint64_t* input, uint64_t* output, int size);
void TestAVX2MulImpl(uint64_t* input, uint64_t* output, int size);
void TestAllMulImpl();

#endif