#include "filemanager.h"
#include <iostream>
#include <fstream>
#include <string>

FileManager::FileManager(const std::string & fileName_) : fileName(fileName_) {}

bool FileManager::readDataFromFile()
{
	std::ifstream inputFile;
	inputFile.open(this->fileName, std::ios::in);

	if (!inputFile.good())
	{
		std::cout << "Error with file in directory:" << std::endl;
		return false;
	}

	int lineNumber = 1;

	while (!inputFile.eof())
	{
		std::string line;
		std::getline(inputFile, line, '\n');

		if (!line.length())
		{
			std::cout << "Error with string in line number " << lineNumber << " !" << std::endl;
			++lineNumber; 
            continue;
		}

        
		++lineNumber; // Inkrementacja licznika linii
	}

	inputFile.close(); // Na koniec zamykamy plik

    return true;
}