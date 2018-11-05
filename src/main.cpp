#include "application.h"
#include <iostream>
#include "test/addition.h"
#include "test/multiplication.h"
#include "test/xor.h"
#include "test/rotl.h"

int main()
{	
	TestAllAddImpl();
	TestAllMulImpl();
	TestAllXorImpl();
	TestAllRotlImpl();

	// Application application;
	// application.run();

    char stopper;
	std::cin >> stopper;

	return 0;
}
