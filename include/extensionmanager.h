#ifndef EXTENSIONMANAGER_H_
#define EXTENSIONMANAGER_H_
#include "minhash.h"
#include "extensiondetector.h"

/**
 * ExtensionManager manages MinHash implementation using extensions.
 **/
class ExtensionManager
{
public:
    // Returns new MinHash instance using specific extension as a parameter.
    minhash::MinHash * getMinHashInstance(Extension);
};

#endif