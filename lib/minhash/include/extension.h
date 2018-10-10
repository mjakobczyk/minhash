#ifndef EXTENSION_H_
#define EXTENSION_H_
#include <iostream>

namespace MinHash
{
    class Extension
    {
    public:
        virtual ~Extension() {}
        virtual void addition(uint64_t[], int) = 0;
        virtual void substraction(uint64_t[], int) = 0;
    };
};

#endif