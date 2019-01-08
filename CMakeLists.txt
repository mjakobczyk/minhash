# Last stable version of CMake set as 3.12
cmake_minimum_required(VERSION 3.12)

# Name of the project is minhash
project (MinHash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfma")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")  

set(MINHASH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/minhash)

add_subdirectory(minhash)

include_directories(
    include
    ${MINHASH_INCLUDE_DIR}
)

set(SOURCES
    src/main.cpp
    src/argmanager.cpp
    src/extensiondetector.cpp
    src/extensionmanager.cpp
    src/osdetector.cpp
    src/filemanager.cpp
    src/arraygenerator.cpp
    src/application.cpp
    src/arraymanager.cpp
    src/testingcase.cpp
    src/testingresult.cpp
    src/testingmanager.cpp
    src/instrset_detect.cpp # GNU license
)

set (TESTS
    src/test/addition.cpp
    src/test/multiplication.cpp
    src/test/xor.cpp
    src/test/rotl.cpp
)

add_executable(program ${SOURCES} ${TESTS})

target_link_libraries(program minhash_lib)