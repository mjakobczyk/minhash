#ifndef EXTENSIONMANAGER_H_
#define EXTENSIONMANAGER_H_
#include "minhash.h"
#include "extensiondetector.h"

class ExtensionManager
{
public:
    minhash::MinHash * getMinHashInstance(Extension);
};

#endif