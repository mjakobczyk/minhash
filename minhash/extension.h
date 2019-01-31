#ifndef EXTENSION_H_
#define EXTENSION_H_
#include <iostream>

namespace minhash
{
    /**
     * Extension defines the amount of counts that can be count in a single
     * iteration using specific extension.
     **/
    class Extension
    {
    public:
        virtual ~Extension() {};
        
        void setElementsInSingleVariable(const int);
        int getElementsInSingleVariable();

    private:
        int elementsInSingleVariable;
    };
};

#endif