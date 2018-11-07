#include "application.h"
#include "extension.h"
#include "minhasher.h"
#include "structural.h"
#include "sse2.h"
#include <inttypes.h>

Application::Application()
{
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
    this->arrayManager = new ArrayManager(DEFAULT_ARRAY_SIZE);
    this->minHash = nullptr;
}

Application::Application(int arraySize_)
{
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
    this->arrayManager = new ArrayManager(DEFAULT_ARRAY_SIZE);
    this->minHash = nullptr;
}

Application::~Application() 
{
    delete arrayManager;
}

void Application::run()
{
    // Scalar implementation
    this->minhashWithExtension(Extension::NONE);

    // SSE2 implementation
    this->minhashWithExtension(Extension::SSE2);
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

void Application::minhashWithExtension(Extension extension)
{
    this->minHash = this->getMinHashInstance(extension);
    this->extension = extension;

    std::cout << "In ";
    auto start = std::chrono::high_resolution_clock::now();
	minHash->count(
        this->arrayManager->getInputArray(),
        this->arrayManager->getOutputArray(),
        this->arrayManager->getSize()
    );
    std::cout << " Out ";
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

	this->showSummary(elapsed);

    delete minHash;
    minHash = nullptr;
}


void Application::showSummary(std::chrono::duration<double> elapsed)
{
    std::cout << "[SUMMARY INFO]" << std::endl;
    std::cout << "Array size = " << this->arrayManager->getSize() << std::endl;
    std::cout << "Extension: " << this->extension << std::endl;
    std::cout << "Execution time: " << elapsed.count() << std::endl << std::endl;
}