#include <iostream>
#include  "boo.h"
#include "foo.h"
#include "localVar.h"
#include "globalVar.h"
#include "internalLinkage.h"
#include "staticLocalVariable.h"

int doExternalLinkage();
int doSomething();

int main()
{
	//std::cout << boo::addNumber(1, 2) << '\n';
	//std::cout << foo::addNumber(1, 2) << '\n';

	//// namespace alias
	//namespace aliasBoo = boo;

	//std::cout << aliasBoo::addNumber(1, 2) << '\n';

	//std::cout << "Please enter 2 integer numbers\n";
	//std::cout << "Enter the first number: ";
	//int firstNumber{};
	//std::cin >> firstNumber;
	//std::cout << '\n';
	//int secondNumber{};
	//std::cout << "Enter the second number: ";
	//std::cin >> secondNumber;
	//std::cout << '\n';

	//enter2int(firstNumber, secondNumber);

	//doNextThing();
	//
	//doSomething();

	//int i = g_int;

	//doExternalLinkage();

	std::cout << staticLocalVariable::doSomething() << '\n';
	std::cout << staticLocalVariable::doSomething() << '\n';

	return 0;
}