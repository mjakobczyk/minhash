#include "addition.h"

void TestStructuralAddImpl(uint64_t* input, uint64_t* output, int size)
{
    for (unsigned int i = 0; i < size; i += 1)
    {
        uint64_t h, h1, h2;

        h1 = input[i];
        h2 = 0x4cf5ad432745937full;

        h1 += h2;

        output[i] = h1;
    }
}

void TestSSE2AddImpl(uint64_t* input, uint64_t* output, int size)
{   
    for (unsigned int i = 0; i < size; i += 2)
    {
        // uint64_t out[2];

        __m128i h, h1, h2, h3;
        h1 = _mm_set_epi64x(*(input + i + 1), *(input + i));
        h2 = _mm_set1_epi64x(0x4cf5ad432745937full);

        h3 = _mm_add_epi64(h1, h2);

        _mm_store_si128((__m128i*)&output[i], h3);

        // *(output + i) = out[1];
        // *(output + i + 1) = out[0];
    }
}

void TestAllAddImpl()
{
    ArrayGenerator * arrayGenerator = new ArrayGenerator();
    int size = 1000000;
    uint64_t* input = arrayGenerator->generateRandomUint64Array(size);
    uint64_t* output = new uint64_t[size];

    auto start = std::chrono::high_resolution_clock::now();
    TestStructuralAddImpl(input, output, size);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << output[0] << "\t" << output[1] << std::endl;
    std::cout << "Structural addition " << size << " elements: " << elapsed.count() << " s" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    TestSSE2AddImpl(input, output, size);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << output[0] << "\t" << output[1] << std::endl;
    
    std::cout << "SSE2\t   addition " << size << " elements: " << elapsed.count() << " s" << std::endl;
    std::cout << std::endl;

    delete [] input;
    delete [] output;
}