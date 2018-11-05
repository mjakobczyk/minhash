#ifndef ROTL_H_
#define ROTL_H_
#include "arraygenerator.h"
#include <cmath>
#include <emmintrin.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

void TestStructuralRotlImpl(uint64_t* input, uint64_t* output, int size);
void TestSSE2RotlImpl(uint64_t* input, uint64_t* output, int size);
void TestAllRotlImpl();

#endif