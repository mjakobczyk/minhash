#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <string>
#include <vector>
#include "testingcase.h"
#include "testingresult.h"
#include "extension.h"

/**
 * FileManager manages input and output files.
 **/
class FileManager
{
public:
    // Constructor taking as a parameter input and output files names.
    FileManager(const std::string &, const std::string &);

    // Returns vector of testing cases defined in input file.
    std::vector<TestingCase> readDataFromInputFile();

    // Writes data in a form of testing results to the output file.
    bool writeDataToOutputFile(std::vector<TestingResult> &);

    // Write data in a form of vector of execution times.
    bool writeDataToOutputFile(std::vector<std::chrono::duration<double>> &);

private:
    // Splits string into tokens using specific delimiter.
    std::vector<std::string> split(const std::string& s, char delimiter);

    // Gets extension type using its string representation.
    Extension getExtension(const std::string &);

    // Gets size array defined as a string from an input file.
    int getSize(const std::string &);

    // Checks if a string is a number.
    bool isNumber(const std::string &);

private:
    const std::string inputFileName;
    const std::string outputFileName;
};

#endif