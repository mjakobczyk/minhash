#ifndef MINHASH_H_
#define MINHASH_H_
#include <iostream>
#include "minhasher.h"

namespace minhash
{
    /**
     * MinHash class is a representation of the unit counting MinHash values.
     **/
    class MinHash
    {
    public:
        // Constructor that takes MinHasher interface as parameter.
        MinHash(MinHasher*);

        // Method used for counting MinHash values. Parameters are: pointer to the
        // input array (containing values), pointer to the output values (where
        // resulting values should be stored) and size of both arrays (that has
        // to be the same).
        void count(uint64_t*, uint64_t*, int);

    private:
        MinHasher* minHasher;
    };
};

#endif