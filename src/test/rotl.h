#ifndef ROTL_H_
#define ROTL_H_
#include "arraygenerator.h"
#include <cmath>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <emmintrin.h> // SSE2
#include <immintrin.h> // AVX2

#define ROTL_DEBUG 0

__m128i SSE2Rotl64(__m128i x, int32_t offset);
__m256i AVX2Rotl64(__m256i x, int32_t offset);

void TestStructuralRotlImpl(uint64_t* input, uint64_t* output, int size);
void TestSSE2RotlImpl(uint64_t* input, uint64_t* output, int size);
void TestAVXRotlImpl(uint64_t* input, uint64_t* output, int size);
void TestAVX2RotlImpl(uint64_t* input, uint64_t* output, int size);
void TestAllRotlImpl();

#endif