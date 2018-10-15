# MinHash

Library for performing MinHash algorithm using SIMD.

## Gettig started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. Download listed tools and libraries.

### Tools

* [CMake](https://cmake.org/) - crossplatform tool for generating makefiles
* [gcc](http://www.mingw.org/) - compiler by the *GNU Project*

### Libraries

* [Intel Intrinsics](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#) - performing operations using SIMD instructions

### CMakeLists.txt

CMakeLists is a file that CMake looks for. Depending on specified instructions and directories CMake generates Makefile for the target application.

## Installation

### Windows 10

Download **Tools** from section **Getting started**.

### MacOS

Use *homebrew* for downloading dependencies.

```bash
brew install cmake
```

## Run

First, clone the repository using https or SSH. Example:

```git clone https://github.com/mjakobczyk/minhash.git```

Next, move to the place where project was cloned. In the main directory where **CMakeLists.txt** file is type the following:

```cmake -G "MinGW Makefiles" .; make```

Finally, run the application using generated target file:

``` ./minhash```

## Project requirements

1. Implementation in C++
2. Multiplatform (Windows, Linux)
3. Detecting available processor instructions (SSE2, AVX, AVX2 etc.), each cpp file compiled with different parameters
4. Using Intel Intrinsics
5. Testing
    * scalar operation
    * SIMD operation
    * count and compare execution times
