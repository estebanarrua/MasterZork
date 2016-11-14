#include "utilities.h"

bool Equal(const string & a, const char * b)
{
	return _stricmp(a.c_str(), b) == 0;
}

bool Equal(const string & a, const string & b)
{
	return _stricmp(a.c_str(), b.c_str()) == 0;
}

void Tokenize(const char* str, vector<string>& result)
{
	do
	{
		const char c = ' '; // Token separator.
		const char *begin = str;

		while (*str != c && *str)
			str++;

		result.push_back(string(begin, str));
		
		while (*str == c && *str)
			str++;
	} while (0 != *str);
}
