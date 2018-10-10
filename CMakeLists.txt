# Last stable version of CMake set as 3.12
cmake_minimum_required(VERSION 3.12)

# Name of the project is minhash
project (minhash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set the output folder where your program will be created
# set(CMAKE_BINARY_DIR ${{PROJECT_SOURCE_DIR}/bin)
# set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Boost variables
# Indicates Boost root directory containg include and lib directories
# set(BOOST_ROOT C:/local/boost-build)
# Indicates Boost include directory containg .h / .hpp files
# set(BOOST_INCLUDEDIR C:/local/boost-build/include)
# Indicates Boost include directory containg .a files
# set(BOOST_LIBRARYDIR C:/local/boost-build/lib)

set(Boost_DEBUG                  ON) # Debug mode
set(Boost_USE_STATIC_LIBS        ON) # Only find static libs
set(Boost_USE_RELEASE_LIBS       ON) # Only find release libs 
set(Boost_USE_MULTITHREADED      ON) # Use multithreaded libs
set(Boost_USE_DEBUG_LIBS        OFF) # Ignore debug libs
set(Boost_USE_STATIC_RUNTIME    OFF) # Use libs linked statically
set(Boost_ADDITIONAL_VERSIONS   OFF) # Boost versions in diff locations

# Find Boost package
find_package(
    Boost
)

if(Boost_FOUND)   
    message("##########################################")
    message("#       Boost library was found!         #")
    message("##########################################")

    include_directories(include)
    file(GLOB SOURCES "src/*.cpp")
    add_executable(program ${SOURCES})

    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
    target_link_libraries(program ${Boost_LIBRARIES})
else()
    message("############################################")
    message("#       Boost library was NOT found!       #")
    message("############################################")
endif()
