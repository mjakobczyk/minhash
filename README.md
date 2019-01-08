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

Second, run CMake with a compiler that you like. On Windows the default compiler will be the one from Visual Studio IDE if it is installed on the machine. Suggested solution is to use GCC.

### Windows 10

```cd build/; cmake ../. -G "MinGW Makefiles" .; make;```

### MacOS

```cd build/; cmake ../.; make;```

Finally, run the application using generated target file:

``` ./program```

## Requirements

1. Implementation in C++
2. Multiplatform (Windows, Linux)
3. Detecting available processor instructions (SSE2, AVX, AVX2 etc.), each cpp file compiled with different parameters
4. Using Intel Intrinsics
5. Testing
    * scalar operation
    * SIMD operation
    * count and compare execution times