#ifndef ARGMANANGER_H_
#define ARGMANANGER_H_
#include <iostream>
#include <string.h>
#include <fstream>

/**
 * ArgManager takes care of arguments passed from command line to the application.
 **/
class ArgManager
{
public:
    // Constructor which takes argument count and arguments from commands line.
    ArgManager(int, char*[]);

    // Gets name of the input file passed to the application.
    std::string getInputFileName();

    // Gets name of the output file passed to the application.
    std::string getOutputtFileName();

    // Returns true if "-p" flag was passed to the application.
    bool shouldRunPerformanceTests();

    // Returns true if "-test" flag was passed to the application.
    bool shouldRunUnitTests();

    // Returns true if "-help" flag was passed to the application.
    bool shouldShowHelp();
    
private:
    int size;
    char** arguments;
};

#endif