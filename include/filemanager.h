#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <string>
#include <vector>
#include "testingcase.h"

class FileManager
{
public:
    FileManager(const std::string &, const std::string &);
    std::vector<TestingCase> & readDataFromInputFile();
    bool writeDataToOutputFile();

private:
    const std::string inputFileName;
    const std::string outputFileName;
};

#endif