#include "application.h"
#include <iostream>
#include "argmanager.h"

// Entry point of the project.
int main(int argc, char* argv[])
{	
	Application application(argc, argv);
	application.run();

	return 0;
}
