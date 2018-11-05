#include "xor.h"

void TestStructuralXorImpl(uint64_t* input, uint64_t* output, int size)
{
    for (unsigned int i = 0; i < size; i += 1)
    {
        uint64_t h, h1, h2;

        h1 = input[i];
        h2 = 0x4cf5ad432745937full;

        h1 ^= h2;

        output[i] = h1;
    }
}

void TestSSE2XorImpl(uint64_t* input, uint64_t* output, int size)
{
    for (unsigned int i = 0; i < size; i += 2)
    {
        __m128i h, h1, h2;
        h1 = _mm_set_epi64x(*(input + i + 1), *(input + i));
        h2 = _mm_set1_epi64x(0x4cf5ad432745937full);

        h1 = _mm_xor_si128(h1, h2);

        _mm_store_si128((__m128i*)&output[i], h1);
    }
}

void TestAllXorImpl()
{
    ArrayGenerator * arrayGenerator = new ArrayGenerator();
    int size = 1000000;
    uint64_t* input = arrayGenerator->generateRandomUint64Array(size);
    uint64_t* output = new uint64_t[size];

    auto start = std::chrono::high_resolution_clock::now();
    TestStructuralXorImpl(input, output, size);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << output[0] << "\t" << output[1] << std::endl;
    std::cout << "Structural XOR " << size << " elements: " << elapsed.count() << " s" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    TestSSE2XorImpl(input, output, size);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << output[0] << "\t" << output[1] << std::endl;
    std::cout << "SSE2\t   XOR " << size << " elements: " << elapsed.count() << " s" << std::endl;
    std::cout << std::endl;

    delete [] input;
    delete [] output;
}