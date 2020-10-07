#include <iostream>
#include <cmath>

bool isAlomostEqual(double a, double b, double epsilon);

bool approximatelyEqual(double a, double b, double epsilon);

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);

int main()
{
	double d1{ 100.0 - 99.99 };
	double d2{ 10.0 - 9.99 };

	if (d1 == d2)
	{
		std::cout << "d1 == d2" << '\n';
	}
	else if (d1 > d2)
		std::cout << "d1 > d2" << '\n';
	else if (d1 < d2)
		std::cout << "d1 < d2" << '\n';

	// Expected d1 > d2;

	// epsilon is an absolute value

	if (approximatelyEqual(d1, d2, 1e-12))
	{
		std::cout << "d1 == d2" << '\n';
	}

	return 0;
}

bool isAlomostEqual(double a, double b, double epsilon)
{
	//if the distance between a and b is less than epsilon, then a and b are "close enough"
	return std::abs(a - b) <= epsilon;
}

bool approximatelyEqual(double a, double b, double epsilon)
{
	return std::abs(a - b) <= std::max(std::abs(a), std::abs(b)) * epsilon;
}

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
	double diff{ std::abs(a - b) };
	if (diff <= absEpsilon)
		return true;
	
	return (diff <= std::max(std::abs(a), std::abs(b)) * relEpsilon);
}