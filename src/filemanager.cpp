#include "filemanager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

FileManager::FileManager(const std::string & input, const std::string & output)
	: inputFileName(input), outputFileName(output) {}

std::vector<TestingCase> FileManager::readDataFromInputFile()
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
            continue;
		}

		auto splitted = this->split(line, ' ');
		if (splitted.size() == 2)
		{
			auto extension = this->getExtension(splitted.at(0));
			auto size = this->getSize(splitted.at(1));

			if (size == -1)
			{
				std::cout << "Error with line " << lineNumber << ". - incorrect array size." << std::endl;
            	continue;
			}

			TestingCase testingCase = TestingCase(extension, size);
			testingCases.push_back(testingCase);
		}
	}

	inputFile.close(); 
    return testingCases;
}

bool FileManager::writeDataToOutputFile(std::vector<TestingResult> & results)
{
	std::ofstream outputFile;
	outputFile.open(this->outputFileName, std::ios::trunc | std::ios::out);

	if (!outputFile.good())
	{
		std::cout << "Error with output file." << std::endl;
		return false;
	}

	for (auto & result : results)
	{
		Extension extension = result.getTestingCase().getExtension();

		if (extension == Extension::SSE2)
		{
			outputFile << "SSE2\t";
		}
		else if (extension == Extension::AVX || extension == Extension::AVX2)
		{
			outputFile << "AVX2\t";
		}
		else
		{
			outputFile << "Scalar\t";
		}

		outputFile << result.getTestingCase().getArraySize() << "\t";
		outputFile << result.getExecutionTime().count() << "s" << std::endl;
	}

	return true;
}

std::vector<std::string> FileManager::split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

Extension FileManager::getExtension(const std::string & word)
{
	if (word == "SSE2")
	{
		return Extension::SSE2;
	}
	else if (word == "AVX" || word == "AVX2")
	{
		return Extension::AVX2;
	}
	else
	{
		return Extension::NONE;
	}
}

int FileManager::getSize(const std::string & word)
{
	if (this->isNumber(word))
	{
		return std::stoi(word);
	}

	return -1;
}

bool FileManager::isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}