cmake_minimum_required(VERSION 3.12)
project (minhash)

# Set the output folder where your program will be created
# set(CMAKE_BINARY_DIR ${{PROJECT_SOURCE_DIR}/bin)
# set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(BOOST_ROOT C:/local/boost-build)
set(BOOST_INCLUDEDIR C:/local/boost-build/include)
set(BOOST_LIBRARYDIR C:/local/boost-build/lib)

set(Boost_DEBUG 1)
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and 
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs 
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF) 
set(Boost_ADDITIONAL_VERSIONS   OFF)
set(Boost_NO_SYSTEM_PATHS       OFF)
set(Boost_DEBUG                  ON)

find_package(
    Boost 
    1.68.0
)

if(Boost_FOUND)   
    message("############################################")
    message ("> Boost library was found!")
    message("############################################")

    include_directories(include)
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

    # file(GLOB SOURCES "src/main.cpp")
    file(GLOB SOURCES "src/*.cpp")

    add_executable(app ${SOURCES})

    target_link_libraries(app${Boost_LIBRARIES})
else()
    message("############################################")
    message ("> Boost library was not found!")
    message(">>> BOOST_ROOT \t = \t" ${BOOST_ROOT})
    message(">>> BOOST_INCLUDEDIR = \t" ${BOOST_INCLUDEDIR})
    message(">>> BOOST_LIBRARYDIR = \t" ${BOOST_LIBRARYDIR})
    message("############################################")
endif()
