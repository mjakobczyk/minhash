#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <string>
#include <vector>

class FileManager
{
    const std::string fileName;
    std::vector<std::string> data;

public:
    FileManager(const std::string &);
    bool readDataFromFile();
};

#endif