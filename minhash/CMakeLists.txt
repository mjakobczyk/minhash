set(MINHASH_SRC
    extension.cpp
    minhash.cpp
    minhasher.cpp
    scalar.cpp
    sse2.cpp
    avx2.cpp
)

set(LIB_TYPE STATIC)

add_library(minhash_lib ${LIB_TYPE} ${MINHASH_SRC})