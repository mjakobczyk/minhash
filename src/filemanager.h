#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <string>

class FileManager
{
    const string fileName;
    std::vector<string> data;

public:
    FileManager(const std::string &);
    bool readDataFromFile();
};

#endif