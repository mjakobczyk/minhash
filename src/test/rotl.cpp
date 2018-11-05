#include "rotl.h"

uint64_t StructuralRotl64(uint64_t x, int32_t offset)
{
    return (x << offset) | (x >> (64 - offset));
}

void TestStructuralRotlImpl(uint64_t* input, uint64_t* output, int size)
{
    for (unsigned int i = 0; i < size; i += 1)
    {
        uint64_t h, h1, h2;

        h1 = input[i];
        
        StructuralRotl64(h1, 31);

        output[i] = h1;
    }
}

__m128i SSE2Rotl64(__m128i x, int32_t offset)
{
    return _mm_or_si128( _mm_slli_epi64(x, offset), _mm_srli_epi64(x, 64 - offset));
}

void TestSSE2RotlImpl(uint64_t* input, uint64_t* output, int size)
{
    for (unsigned int i = 0; i < size; i += 2)
    {
        __m128i h, h1;
        h1 = _mm_set_epi64x(*(input + i + 1), *(input + i));

        SSE2Rotl64(h1, 31);

        _mm_store_si128((__m128i*)&output[i], h1);
    }
}

void TestAllRotlImpl()
{
    ArrayGenerator * arrayGenerator = new ArrayGenerator();
    int size = 1000000;
    uint64_t* input = arrayGenerator->generateRandomUint64Array(size);
    uint64_t* output = new uint64_t[size];

    auto start = std::chrono::high_resolution_clock::now();
    TestStructuralRotlImpl(input, output, size);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << output[0] << "\t" << output[1] << std::endl;
    std::cout << "Structural Rotl " << size << " elements: " << elapsed.count() << " s" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    TestSSE2RotlImpl(input, output, size);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;

    std::cout << output[0] << "\t" << output[1] << std::endl;
    std::cout << "SSE2\t   Rotl " << size << " elements: " << elapsed.count() << " s" << std::endl;
    std::cout << std::endl;

    delete [] input;
    delete [] output;
}