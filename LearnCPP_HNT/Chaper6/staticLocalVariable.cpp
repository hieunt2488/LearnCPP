//#include "staticLocalVariable.h"

namespace staticLocalVariable
{
	int doSomething()
	{
		static int mylocalVar{ 0 };
		++mylocalVar;
		return mylocalVar;
	}
}