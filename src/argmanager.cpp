#include "argmanager.h"

ArgManager::ArgManager(int size_, char* arguments_[])
{
    this->size = size_;
    *(this->arguments) = *(arguments_);
    std::cout << "argc = " << size_ << std::endl;
}

std::string & ArgManager::getInputFileName()
{
    std::string name = "";

    for (unsigned int i = 1; i < this->size; ++i)
    {
        std::string arg = std::string(this->arguments[i]);

        if (arg == "-i")
        {
            if (i + 1 < this->size)
            {
                name = std::string(arguments[i + 1]);
				std::ifstream file;
                // TODO: what ios:: type should be used?
                file.open(name, std::ios::trunc); //PrÛba otwarcia pliku wyjúciowego
				if (file.good())
                {
                    name = std::string(arguments[i + 1]);
                }
            }
        }
    }

    return name;
}

std::string & ArgManager::getOutputtFileName()
{
    std::string name = "";

    // for (unsigned int i = 1; i < this->size; ++i)
    // {
    //     std::string arg = std::string(this->arguments[i]);

    //     if (arg == "-o")
    //     {
    //         if (i + 1 < this->size)
    //         {
	// 			ofstream file;
    //             file.open(filename, ios::trunc | ios::ate); //PrÛba otwarcia pliku wyjúciowego
	// 			if (file.good())
    //             {
    //                 name = std::string(arguments[i + 1);
    //             }
    //         }
    //     }
    // }

    return name;
}