#include "application.h"
#include "extension.h"
#include "minhasher.h"
#include "structural.h"
#include "sse2.h"
#include <inttypes.h>

Application::Application() :
    arraySize(ARRAY_SIZE)
{
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
    this->input = this->arrGenerator.generateRandomUint64Array(this->arraySize);
    // this->output = (uint64_t*)std::_aligned_malloc(this->arraySize * sizeof(uint64_t), 16);
    this->output = new uint64_t[this->arraySize];
}

Application::Application(int arraySize_)
{
    this->arraySize = arraySize_;
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
    this->input = this->arrGenerator.generateRandomUint64Array(this->arraySize);
    this->output = new uint64_t[this->arraySize];
}

Application::Application(uint64_t* input_, uint64_t* output_, int arraySize_)
{
    this->arraySize = arraySize_;
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
    this->input = input_;
    this->output = output_;
}

Application::~Application()
{
    // Not working on MacOS
    // _aligned_free(this->input);
    // _aligned_free(this->output);
    delete [] this->input;
    delete [] this->output;
}

void Application::run()
{
    std::cout << "Starting algorithm..." << std::endl;

    // Choose which Extension to run app with
    // Scalar
    minhash::MinHash * minHash;
    minHash = this->getMinHashInstance(Extension::NONE);
    this->extension = Extension::NONE;
    auto start = std::chrono::high_resolution_clock::now();
	minHash->count(this->input, this->output, this->arraySize);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    this->executionTime = elapsed;

    // this->showResults();
	this->showSummary();

    // SSE2
    minHash = this->getMinHashInstance(Extension::SSE2);
    this->extension = Extension::SSE2;
    start = std::chrono::high_resolution_clock::now();
	minHash->count(this->input, this->output, this->arraySize);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    this->executionTime = elapsed;

    // this->showResults();
	this->showSummary();
    std::cout << std::endl << "Ending algorithm..." << std::endl;
}

minhash::MinHash *Application::getMinHashInstance(Extension extension)
{
    minhash::MinHasher *minHasher;

    if (extension == Extension::AVX2)
    {
        // TODO: change mocked implementation
        minHasher = new minhash::Structural();
    }
    else if (extension == Extension::AVX)
    {
        // TODO: change mocked implementation
        minHasher = new minhash::Structural();
    }
    else if (extension == Extension::SSE2)
    {
        minHasher = new minhash::SSE2();
    }
    else
    {
        minHasher = new minhash::Structural();
    }

    return new minhash::MinHash(minHasher);
}

void Application::showResults()
{
    std::cout << std::endl << "Input array:" << std::endl;
    for (unsigned int i = 0; i < this->arraySize; ++i)
    {
        printf("%" PRIu64 "\n", this->input[i]);
    }

    std::cout << std::endl << "Output array:" << std::endl;
    for (unsigned int i = 0; i < this->arraySize; ++i)
    {
        printf("%" PRIu64 "\n", this->output[i]);
    }
}

void Application::showSummary()
{
    std::cout << "[SUMMARY INFO]" << std::endl;
    std::cout << "Array size = " << this->arraySize << std::endl;
    std::cout << "Extension: " << this->extension << std::endl;
    std::cout << "Execution time: " << this->executionTime.count() << std::endl << std::endl;
}