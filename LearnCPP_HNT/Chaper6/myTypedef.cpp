int main()
{
	typedef long myLong;

	using myInt = int;

	myLong longVar{ 123 };

	myInt intVar{ 456 };

	return (int)longVar;
}
