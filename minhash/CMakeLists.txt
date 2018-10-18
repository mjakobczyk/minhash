set(MINHASH_SRC
    extension.cpp
    minhash.cpp
    structural.cpp
)

set(LIB_TYPE STATIC)

add_library(minhash ${LIB_TYPE} ${MINHASH_SRC})