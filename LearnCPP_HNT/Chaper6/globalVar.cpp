#include "globalVar.h"
#include <iostream>

int g_var{100};

namespace globalVar
{
	int g_ns_var{101};
	void doSomething()
	{
		g_var =10 ;

		std::cout << g_var << '\n';
	}
}

void doNextThing()
{
	std::cout << "Global variable g_var: " << g_var << '\n';
	std::cout << "Global namespace variable globalVar g_ns_var: " << globalVar::g_ns_var << '\n';
}

