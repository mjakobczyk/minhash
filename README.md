# MinHash
Library for performing MinHash algorithm using SIMD

Requirements
1. Implementation in C++
2. Multiplatform (Windows, Linux)
3. Detecting available processor instructions (SSE2, AVX, AVX2 etc.), each cpp file compiled with different parameters
4. Using Intel Intrinsics
5. Testing:
	- scalar operation
	- SIMD operation
	- count and compare execution times
	
MVP
1. As a user I want to run the application on Windows and detect processor extensions.
	1.1 Create Visual Studio Project
	1.2 Choose C++ as a default language
	1.3 Setup library project 
	1.4 Research on libraries in C++
