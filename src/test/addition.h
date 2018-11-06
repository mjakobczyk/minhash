#ifndef ADDITION_H_
#define ADDITION_H_
#include "arraygenerator.h"
#include <cmath>
#include <emmintrin.h> // SSE2
#include <immintrin.h> // AVX2

#define ADD_DEBUG 0

void TestStructuralAddImpl(uint64_t* input, uint64_t* output, int size);
void TestSSE2AddImpl(uint64_t* input, uint64_t* output, int size);
void TestAVXAddImpl(uint64_t* input, uint64_t* output, int size);
void TestAVX2AddImpl(uint64_t* input, uint64_t* output, int size);
void TestAllAddImpl();

#endif