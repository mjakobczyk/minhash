#include "application.h"
#include "extension.h"
#include "minhasher.h"
#include "structural.h"
#include "sse2.h"
#include "avx2.h"
#include <inttypes.h>
#include <string.h>

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

    // Scalar implementation
    this->minhashWithExtension(Extension::NONE);

    // SSE2 implementation
    this->minhashWithExtension(Extension::SSE2);

    // AVX2 implementation
    this->minhashWithExtension(Extension::AVX2);

    // // SSE2 implementation
    // this->minhashWithExtension(Extension::SSE2);

    // // AVX2 implementation
    // this->minhashWithExtension(Extension::AVX2);

    // // AVX2 implementation
    // this->minhashWithExtension(Extension::AVX2);
}

minhash::MinHash *Application::getMinHashInstance(Extension extension)
{
    minhash::MinHasher *minHasher;

    if (extension == Extension::AVX2)
    {
        // TODO: change mocked implementation
        minHasher = new minhash::AVX2();
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

    auto start = std::chrono::high_resolution_clock::now();
	minHash->count(
        this->arrayManager->getInputArray(),
        this->arrayManager->getOutputArray(),
        this->arrayManager->getSize()
    );

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    uint64_t * out = this->arrayManager->getOutputArray();
	this->showSummary(extension, elapsed);

    delete minHash;
    minHash = nullptr;
}


void Application::showSummary(Extension extension, std::chrono::duration<double> elapsed)
{
    std::cout << "[SUMMARY INFO]" << std::endl;
    std::cout << "Array size = " << this->arrayManager->getSize() << std::endl;
    std::string ext;
    switch (extension)
    {
        case Extension::SSE2:
            ext = "SSE2";
            break;
        case Extension::AVX:
        case Extension::AVX2:
            ext = "AVX2";
            break;
        case Extension::NONE:
        default:
            ext = "Scalar";
            break;
    }
    std::cout << "Extension: " << ext << std::endl;
    std::cout << "Execution time: " << elapsed.count() << "s" << std::endl << std::endl;
}