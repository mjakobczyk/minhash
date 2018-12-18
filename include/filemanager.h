#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <string>
#include <vector>
#include "testingcase.h"
#include "testingresult.h"
#include "extension.h"

class FileManager
{
public:
    FileManager(const std::string &, const std::string &);
    std::vector<TestingCase> readDataFromInputFile();
    bool writeDataToOutputFile(std::vector<TestingResult> &);

private:
    std::vector<std::string> split(const std::string& s, char delimiter);
    Extension getExtension(const std::string &);
    int getSize(const std::string &);
    bool isNumber(const std::string &);

private:
    const std::string inputFileName;
    const std::string outputFileName;
};

#endif