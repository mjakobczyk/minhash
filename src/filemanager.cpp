#include "filemanager.h"
#include <iostream>
#include <fstream>
#include <string>

FileManager::FileManager(const std::string & input, const std::string & output)
	: inputFileName(input), outputFileName(output) {}

std::vector<TestingCase> & FileManager::readDataFromInputFile()
{
	std::vector<TestingCase> testingCases;
	std::ifstream inputFile;
	inputFile.open(this->inputFileName, std::ios::in);

	if (!inputFile.good())
	{
		std::cout << "Error with input file" << std::endl;
		return testingCases;
	}

	for (unsigned int lineNumber = 0; !inputFile.eof(); ++lineNumber)
	{
		std::string line;
		std::getline(inputFile, line, '\n');

		if (!line.length())
		{
			std::cout << "Error with line number " << lineNumber << std::endl;
			++lineNumber; 
            continue;
		}
	}

	// int lineNumber = 1;

	// while (!inputFile.eof())
	// {
	// 	std::string line;
	// 	std::getline(inputFile, line, '\n');

	// 	if (!line.length())
	// 	{
	// 		std::cout << "Error with line number " << lineNumber << std::endl;
	// 		++lineNumber; 
    //         continue;
	// 	}

	// 	++lineNumber;
	// }

	inputFile.close(); 
    return testingCases;
}