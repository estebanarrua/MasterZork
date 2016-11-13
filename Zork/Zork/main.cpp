#include "world.h"
#include "utilities.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	char input[512];
	vector<string> arguments;
	while (1)
	{
		arguments.clear();
		cin.getline( input, 512);
		Tokenize(input, arguments);
		if (arguments[0] == "exit")
		{
			break;
		}
		else
		{
			cout << ">";
		}
	}
	return 0;
}