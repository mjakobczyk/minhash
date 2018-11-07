#include "application.h"
#include "extension.h"
#include "minhasher.h"
#include "structural.h"
#include "sse2.h"
#include <inttypes.h>

Application::Application() :
    arrayManager(DEFAULT_ARRAY_SIZE)
{
    std::cout << "Creating app..";
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
    std::cout << "App ready";
}

Application::Application(int arraySize_) :
    arrayManager(arraySize_)
{
    this->osDetector.checkOS();
    this->extension = this->exDetector.chooseExtension();
}

Application::~Application() 
{

}

void Application::run()
{
    // std::cout << "Starting algorithm..." << std::endl;
    // minhash::MinHash * minHash;
    std::cout << "After minhash * ";

    // Scalar
    // minHash = this->getMinHashInstance(Extension::SSE2);
    std::cout << "After getting minhash instance";
    this->extension = Extension::SSE2;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << this->arrayManager.getInputArray()[0] << std::endl;
	// minHash->count(
    //     this->arrayManager.getInputArray(),
    //     this->arrayManager.getOutputArray(),
    //     this->arrayManager.getSize()
    // );
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    this->executionTime = elapsed;
	this->showSummary();

    // SSE2
    // minHash = this->getMinHashInstance(Extension::SSE2);
    // this->extension = Extension::SSE2;
    // start = std::chrono::high_resolution_clock::now();
	// minHash->count(
    //     this->arrayManager.getInputArray(),
    //     this->arrayManager.getOutputArray(),
    //     this->arrayManager.getSize()
    // );
    // finish = std::chrono::high_resolution_clock::now();
    // elapsed = finish - start;
    // this->executionTime = elapsed;
	// this->showSummary();

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

void Application::showSummary()
{
    std::cout << "[SUMMARY INFO]" << std::endl;
    std::cout << "Array size = " << this->arrayManager.getSize() << std::endl;
    std::cout << "Extension: " << this->extension << std::endl;
    std::cout << "Execution time: " << this->executionTime.count() << std::endl << std::endl;
}