#include "multiplication.h"

void TestStructuralMulImpl(uint64_t* input, uint64_t* output, int size)
{
    for (unsigned int i = 0; i < size; i += 1)
    {
        uint64_t h, h1, h2;

        h1 = input[i];
        h2 = 0x4cf5ad432745937full;

        h1 *= h2;

        output[i] = h1;
    }
}

inline __m128i multiply64Bit(__m128i a, __m128i b)
{
    // auto ax0_ax1_ay0_ay1 = a;
    // auto bx0_bx1_by0_by1 = b;
    
    // _mm_shuffle
    // auto ax1_i_ay1_i = _mm_shuffle_epi32(ax0_ax1_ay0_ay1, _MM_SHUFFLE(3, 3, 1, 1));
    // auto bx1_i_by1_i = _mm_shuffle_epi32(bx0_bx1_by0_by1, _MM_SHUFFLE(3, 3, 1, 1));

    // auto ax0bx0_ay0by0 = _mm_mul_epi32(ax0_ax1_ay0_ay1, bx0_bx1_by0_by1);
    // auto ax0bx1_ay0by1 = _mm_mul_epi32(ax0_ax1_ay0_ay1, bx1_i_by1_i);
    // auto ax1bx0_ay1by0 = _mm_mul_epi32(ax1_i_ay1_i, bx0_bx1_by0_by1);

    // auto ax0bx1_ay0by1_32 = _mm_slli_epi64(ax0bx1_ay0by1, 32);
    // auto ax1bx0_ay1by0_32 = _mm_slli_epi64(ax1bx0_ay1by0, 32);

    // return _mm_add_epi64(ax0bx0_ay0by0, _mm_add_epi64(ax0bx1_ay0by1_32, ax1bx0_ay1by0_32));
    return  _mm_set1_epi64x(0x4cf5ad432745937full);
}

void TestSSE2MulImpl(uint64_t* input, uint64_t* output, int size)
{
    for (unsigned int i = 0; i < size; i += 2)
    {
        __m128i h, h1, h2;
        h1 = _mm_set_epi64x(*(input + i + 1), *(input + i));
        h2 = _mm_set1_epi64x(0x4cf5ad432745937full);

        h1 = multiply64Bit(h1, h2);

        _mm_store_si128((__m128i*)&output[i], h1);
    }
}

void TestAllMulImpl()
{
    ArrayGenerator * arrayGenerator = new ArrayGenerator();
    int size = 1000000;
    uint64_t* input = arrayGenerator->generateRandomUint64Array(size);
    uint64_t* output = new uint64_t[size];

    auto start = std::chrono::high_resolution_clock::now();
    TestStructuralMulImpl(input, output, size);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << output[0] << "\t" << output[1] << std::endl;
    std::cout << "Structural multiplication " << size << " elements: " << elapsed.count() << " s" << std::endl;
    
    uint64_t* sse2Store = new uint64_t[3];
    start = std::chrono::high_resolution_clock::now();
    TestSSE2MulImpl(input, output, size);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << output[0] << "\t" << output[1] << std::endl;
    std::cout << "SSE2\t   multiplication " << size << " elements: " << elapsed.count() << " s" << std::endl;
    std::cout << std::endl;

    delete [] input;
    delete [] output;
}