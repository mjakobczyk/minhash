#include "structural.h"

void minhash::Structural::minHash(uint64_t *input, uint64_t *output, const int size)
{
    std::cout << "Structural: minHash method from MinHasher interface" << std::endl;

    for (unsigned int i = 0; i < size; ++i)
    {
        uint64_t temp = input[i];
        if (temp % 2 != 0)
        {
            temp += 1;
        }

        temp /= 2;

        output[i] = temp;
    }

    std::cout << "Structural: going out" << std::endl;
}
