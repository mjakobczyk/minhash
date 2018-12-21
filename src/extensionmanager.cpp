#include "extensionmanager.h"
#include "minhasher.h"
#include "sse2.h"
#include "avx2.h"
#include "structural.h"

minhash::MinHash * ExtensionManager::getMinHashInstance(Extension extension)
{
    minhash::MinHasher *minHasher;

    if (extension == Extension::AVX2)
    {
        minHasher = new minhash::AVX2();
    }
    else if (extension == Extension::AVX)
    {
        minHasher = new minhash::AVX2();
    }
    else if (extension == Extension::SSE2)
    {
        minHasher = new minhash::SSE2();
    }
    else
    {
        minHasher = new minhash::Structural();
    }

    return new minhash::MinHash(minHasher);
}