#include <iostream>

using namespace std;

void Printf(const char* s)
{
	while (*s)
	{
		if (*s == '%' && *++s != '%')
			throw runtime_error("invalid format string: missing argument.\n");
		cout << *s++;
	}
}

template<typename T, typename ...Args>
void Printf(const char* s, T value, Args... args)
{
	while (*s)
	{
		if (*s == '%' && *++s != '%')
		{
			cout << value;
			return Printf(++s, args...);
		}
		cout << *s++;
	}
}

int main()
{
	Printf("hello %d. world %s\n", "world", 123);
	return 0;
}