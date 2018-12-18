#include "application.h"
#include <iostream>
#include "test/addition.h"
#include "test/multiplication.h"
#include "test/xor.h"
#include "test/rotl.h"
#include "argmanager.h"

int main(int argc, char* argv[])
{	
	// TestAllAddImpl();
	// TestAllMulImpl();
	// TestAllXorImpl();
	// TestAllRotlImpl();

	Application application(argc, argv);
	application.run();

	// ArgManager * manager = new ArgManager(argc, argv);

    char stopper;
	std::cin >> stopper;

	return 0;
}
