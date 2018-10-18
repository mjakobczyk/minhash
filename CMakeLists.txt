# Last stable version of CMake set as 3.12
cmake_minimum_required(VERSION 3.12)

# Name of the project is minhash
project (minhash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(MINHASH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/minhash)

add_subdirectory(minhash)

# Set the output folder where your program will be created
# set(CMAKE_BINARY_DIR ${{PROJECT_SOURCE_DIR}/bin)
# set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(
    include
    ${MINHASH_INCLUDE_DIR}
)

set(SOURCES 
    src/main.cpp
    src/extensiondetector.cpp
    src/osdetector.cpp
    src/filemanager.cpp
    src/instrset_detect.cpp # GNU license
    src/simdpoc.cpp # DELETE only for testing purposes
)

add_executable(program ${SOURCES})

target_link_libraries(program minhash)

add_dependencies(program minhash)

# install(TARGETS program DESTINATION bin)