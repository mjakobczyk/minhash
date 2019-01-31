#include "argmanager.h"

ArgManager::ArgManager(int size_, char* arguments_[])
{
    this->size = size_;
    this->arguments = arguments_;
}

std::string ArgManager::getInputFileName()
{
    for (unsigned int i = 1; i < this->size; ++i)
    {
        std::string arg = std::string(this->arguments[i]);

        if (arg == "-i")
        {
            if (i + 1 < this->size)
            {
                std::string name = std::string(arguments[i + 1]);
				std::ifstream file;
                file.open(std::string(arguments[i + 1]), std::ios::in);
				if (file.good())
                {
                    return name;
                }
            }
        }
    }

    return "";
}

std::string ArgManager::getOutputtFileName()
{
    for (unsigned int i = 1; i < this->size; ++i)
    {
        std::string arg = std::string(this->arguments[i]);

        if (arg == "-o")
        {
            if (i + 1 < this->size)
            {
                std::string name = std::string(arguments[i + 1]);
				std::ofstream file;
                file.open(std::string(arguments[i + 1]), std::ios::trunc | std::ios::ate);
				if (file.good())
                {
                    return name;
                }
            }
        }
    }

    return "";
}

bool ArgManager::shouldRunPerformanceTests()
{
        for (unsigned int i = 1; i < this->size; ++i)
    {
        std::string arg = std::string(this->arguments[i]);

        if (arg == "-p")
        {
            return true;
        }
    }

    return false;
}

bool ArgManager::shouldRunUnitTests()
{
        for (unsigned int i = 1; i < this->size; ++i)
    {
        std::string arg = std::string(this->arguments[i]);

        if (arg == "-t")
        {
            return true;
        }
    }

    return false;
}

bool ArgManager::shouldShowHelp()
{
        for (unsigned int i = 1; i < this->size; ++i)
    {
        std::string arg = std::string(this->arguments[i]);

        if (arg == "-h")
        {
            return true;
        }
    }

    return false;
}