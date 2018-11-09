set(MINHASH_SRC
    extension.cpp
    minhash.cpp
    minhasher.cpp
    structural.cpp
    sse2.cpp
    avx2.cpp
)

set(LIB_TYPE STATIC)

add_library(minhash ${LIB_TYPE} ${MINHASH_SRC})