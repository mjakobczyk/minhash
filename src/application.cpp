#include "application.h"
#include "structural.h"
#include "extension.h"
#include "minhasher.h"

Application::Application() :
    arraySize(ARRAY_SIZE)
{
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
    this->input = this->arrGenerator.generateRandomUint64Array(this->arraySize);
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
    this->output = input_;
}

Application::~Application()
{
    delete [] this->input;
    delete [] this->output;
}

void Application::run()
{
    std::cout << "Starting algorithm..." << std::endl;

    minhash::MinHash * minHash = this->getMinHashInstance(extension);

    auto start = std::chrono::high_resolution_clock::now();
	minHash->count(this->input, this->output, this->arraySize);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    this->executionTime = elapsed;

    std::cout << "Ending algorithm..." << std::endl;
	this->showSummary();
}

minhash::MinHash *Application::getMinHashInstance(Extension extension)
{
    minhash::MinHasher *minHasher;

    if (extension == Extension::AVX2)
    {
        // TODO: change mocked implementation
        minHasher = new minhash::Structural;
    }
    else if (extension == Extension::AVX)
    {
        // TODO: change mocked implementation
        minHasher = new minhash::Structural;    }
    else if (extension == Extension::SSE2)
    {
        // TODO: change mocked implementation
        minHasher = new minhash::Structural;
    }
    else
    {
        minHasher = new minhash::Structural;
    }

    return new minhash::MinHash(minHasher);
}

void Application::showResults()
{
    std::cout << std::endl << "Input array:" << std::endl;
    for (unsigned int i = 0; i < this->arraySize; ++i)
    {
        std::cout << this->input[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << std::endl << "Output array:" << std::endl;
    for (unsigned int i = 0; i < this->arraySize; ++i)
    {
        std::cout << this->output[i] << std::endl;
    }
    std::cout << std::endl;
}

void Application::showSummary()
{
    std::cout << "[SUMMARY INFO]" << std::endl;
    std::cout << "Array size = " << this->arraySize << std::endl;
    std::cout << "Extension: " << this->extension << std::endl;
    std::cout << "Execution time: " << this->executionTime.count() << std::endl << std::endl;
}