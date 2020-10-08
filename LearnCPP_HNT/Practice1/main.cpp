#include <iostream>

int add(int x, int y);

// used forward declaration

extern int g_ex_i; // forwar declaration for external non-const variable in a.cpp 

extern const int g_ex_x;

// Warning
// don't used uninitilized non-const variable with extern

//extern constexpr int g_ex_y; // constexper cannot be used in other files even though declared extern

int main()
{
	//std::cout << g_i;
	//std::cout << g_x;
	//std::cout << g_y;

	//std::cout << add(1, 2);

	std::cout << g_ex_i;
	std::cout << g_ex_x;
	//std::cout << g_ex_y; //useless


	return 0;
}