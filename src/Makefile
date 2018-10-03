
# Directory of the project
ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Directory of Boost library
ROOT_BOOST := $(ROOT_DIR)libs/boost_1_68_0

CXX=g++
CXXFLAGS=-std=c++11

output: main.o osdetector.o
	$(CXX) main.o osdetector.o -o output
	
main.o: main.cpp
	$(CXX) -c main.cpp
	
osdetector.o: osdetector.cpp osdetector.h
	$(CXX) -I $(ROOT_BOOST) $(CXXFLAGS) -c osdetector.cpp
	
clean:
	rm *.o
