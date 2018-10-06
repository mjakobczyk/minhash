
# Directory of the project
ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Directory of Boost library
ROOT_BOOST := $(ROOT_DIR)../lib/boost_1_68_0

CXX=g++
CXXFLAGS=-std=c++11
SIMD=-O3 -march=native
TARGET=program

$(TARGET): main.o osdetector.o extensiondetector.o filemanager.o
	$(CXX) main.o osdetector.o extensiondetector.o filemanager.o -o $(TARGET)
	
main.o: main.cpp
	$(CXX) -c main.cpp
	
osdetector.o: osdetector.cpp osdetector.h
	$(CXX) -I $(ROOT_BOOST) $(CXXFLAGS) -c osdetector.cpp

extensiondetector.o: extensiondetector.cpp extensiondetector.h
	$(CXX) -I $(ROOT_BOOST) $(CXXFLAGS) $(SIMD) -c extensiondetector.cpp

filemanager.o: filemanager.cpp filemanager.h
	$(CXX) $(CXXFLAGS) -c filemanager.cpp
	
clean:
	rm -f *.o
	