#ifndef EXTENSION_H_
#define EXTENSION_H_
#include <iostream>

namespace MinHash
{
    class Extension
    {
    public:
        virtual ~Extension() {}
        
        void setElementsInSingleVariable(const int);
        int getElementsInSingleVariable();

    private:
        int elementsInSingleVariable;
    };
};

#endif