#ifndef ARGMANANGER_H_
#define ARGMANANGER_H_
#include <iostream>
#include <string.h>
#include <fstream>

class ArgManager
{
public:
    ArgManager(int, char*[]);
    std::string & getInputFileName();
    std::string & getOutputtFileName();
    
private:
    int size;
    char* arguments[];
};

#endif