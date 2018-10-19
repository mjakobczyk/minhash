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
	Extension extension = this->chooseExtension(this->exDetector.checkAvailableExtensions());
    std::cout << "Chosen extension: " << extension << std::endl;

    //minhash::MinHash minHash(this->minHasher);
	//minHash.count(this->input, this->output, this->arraySize);
}

Extension Application::chooseExtension(std::vector<Extension> availableExtensions)
{
    if (!availableExtensions.empty)
    {
        if(std::find(availableExtensions.begin(), availableExtensions.end(), Extension::AVX2) != availableExtensions.end())
        {
            return Extension::AVX2;
        } 
        else
        {
            if(std::find(availableExtensions.begin(), availableExtensions.end(), Extension::AVX) != availableExtensions.end())
            {
                return Extension::AVX;
            } 
            else
            {
                if(std::find(availableExtensions.begin(), availableExtensions.end(), Extension::SSE2) != availableExtensions.end())
                {
                    return Extension::SSE2;
                } 
            }
        }
    }
    
    return Extension::NONE;
}
