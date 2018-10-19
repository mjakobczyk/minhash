#include "application.h"
#include "structural.h"
#include "extension.h"

Application::Application() : 
    arraySize(ARRAY_SIZE)
{

}

void Application::run()
{
	this->osDetector.checkOS();
	// Extension extension = this->
    //this->exDetector.checkAvailableExtensions();

    minhash::MinHash minHash(this->minHasher);
	minHash.count(this->input, this->output, this->arraySize);
}

minhash::Extension Application::chooseExtension(std::vector<minhash::Extension> availableExtensions)
{
    if (!availableExtensions.empty)
    {

    }
    else
    {
        minhash::Structural structural;
    }
}
