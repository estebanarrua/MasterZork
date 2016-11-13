#include "utilities.h"

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
	} while (0 != *str++);
}
