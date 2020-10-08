// static global variable internal linkage. This variable can only be used in this file
static int g_i{ 1 }; 

// const global variable linkage. This variable can only be used in this file

const int g_x{ 2 };

// constexpr global variable  linkage. This variable can only be used in this file

constexpr int g_y{ 3 };

// global variable external linkage by default. Can be used in other files.
int g_ex_i{ 1 };

// const global variable external linkage. Can be used in other files.

extern const int g_ex_x{ 2 };

// constexpr global variable external linkage. Can be used in other files.

extern constexpr int g_ex_y{ 3 };

static int add(int x, int y)
{
	return x + y;
}