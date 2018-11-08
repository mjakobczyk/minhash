#ifndef STRUCTURAL_H_
#define STRUCTURAL_H_
#include <iostream>
#include "minhasher.h"
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#define DEBUG 0

namespace minhash
{
    class Structural : public minhash::MinHasher
    {
    public:
        Structural();
        virtual ~Structural();

        virtual void minHash(uint64_t* input, uint64_t* output, int size) override
        {
            for (unsigned int i = 0; i < size; i += this->getElementsInOneCall())
            {
                this->countPack(input, output, i);
            }
        }

    private:
        void inline countPack(uint64_t* input, uint64_t* output, int offset)
        {
            uint64_t x = input[offset];

            // Hashes in between the process to calculate
            uint64_t h, h1, h2;

            h = x;

            h *= 0x87c37b91114253d5ull;

            h = this->rotl64(h, 31);

            h *= 0x4cf5ad432745937full;

            h1 = 42 ^ h;

            h1 ^= this->k_div_4; //ceil(k / 4);

            h2 = this->c42_xor_k_div_4; // 42 ^ ceil(k / 4);

            h1 += h2;

            h2 += h1;

            // this->printValue(h1); // Dotad jest to samo
            h1 = fmix64(h1);
            // std::cout << "h1 = ";
            // this->printValue(h1);

            // h2 = fmix64(h2);
            // std::cout << "h2 = ";
            // this->printValue(h2);

            h1 += h2;

            h2 += h1;

            // Return XOR as a final hash
            output[offset] = h1 ^ h2;

            // std::cout << "Final: " << output[offset] << std::endl;
            std::cout << std::endl;
        }

        uint64_t inline fmix64(uint64_t k)
        {
            // std::cout << "Fmix IN" << std::endl;
            this->printValue(k);
            k ^= k >> 33;
            k *= 0xff51afd7ed558ccdull;
            this->printValue(k);
            k ^= k >> 33;
            k *= 0xc4ceb9fe1a85ec53ull;
            k ^= k >> 33;
            // this->printValue(k);
            // std::cout << "Fmix OUT" << std::endl;

            return k;
        }

        uint64_t rotl64(uint64_t x, int32_t offset)
        {
            return (x << offset) | (x >> (64 - offset));
        }

        void printValue(uint64_t);

    };
};


    #endif