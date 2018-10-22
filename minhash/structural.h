#ifndef STRUCTURAL_H_
#define STRUCTURAL_H_
#include <iostream>
#include "minhasher.h"

namespace minhash
{
    class Structural : public minhash::MinHasher
    {
    public:
        virtual void minHash(uint64_t[], uint64_t[], const int);

    private:
        uint64_t processElement(uint64_t);
    };
};


#endif