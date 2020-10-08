#include "localVar.h"
#include <iostream>

int max(int x, int y) //x, y enter scope here, created and initilized
{
	int max{ x > y ? x : y }; // max enter scope here, created and initilized

	{
		int n{ 100 }; //n enter scope, created 

		int x{ 1000 }; //new x enter scope, not the x outside this scope

	}// n and x out of scope and are destroyed

	return max;
} //x, y, and max leave scope here and are destroyed

int enter2int(int smaller, int larger)
{
	if (larger < smaller)
	{
		int tmp{ smaller };

		smaller = larger;

		larger = tmp;
	} //tmp die

	std::cout << "larger: " << larger << '\n';
	std::cout << "smaller: " << smaller << '\n';

	return 0;
} // smaller and larger die
