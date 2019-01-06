#include "application.h"
#include <iostream>
#include "argmanager.h"

int main(int argc, char* argv[])
{	
	Application application(argc, argv);
	application.run();

	return 0;
}
