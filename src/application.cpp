#include "application.h"
#include "structural.h"
#include "extension.h"
#include <minhasher.h>

Application::Application() :
    arraySize(ARRAY_SIZE)
{
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
    this->input = this->arrGenerator.generateRandomUint64Array(this->arraySize);
    this->output = new uint64_t[this->arraySize];
}

void Application::run()
{
    minhash::MinHash * minHash = this->getMinHashInstance(extension);
	minHash->count(this->input, this->output, this->arraySize);
    // this->printResults();
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

void Application::printResults()
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
