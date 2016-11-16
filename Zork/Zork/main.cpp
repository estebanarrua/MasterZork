#include "world.h"
#include "utilities.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	bool playing = true;
	while (playing)
	{
		char input[512];
		vector<string> arguments;
		World* world = new World();

		cout << "Welcome to the Zork game!\n";
		while (world->player->state == PLAYING)
		{
			cout << "\n>";
			arguments.clear();
			cin.getline(input, 512);
			Tokenize(input, arguments);
			if (arguments[0] == "exit")
			{
				world->player->state = EXIT_GAME;
			}
			else
			{
				cout << "\n";

				if (!world->ExecuteCommand(arguments))
				{
					cout << "Invalid command\n";
				}
			}
		}
		switch (world->player->state)
		{
		case ARREST_OK:
			cout << "Congratulations, you found the killer and proof to incriminate him.\n";
			cout << "Press enter to finish.\n";
			cin.getline(input, 512);
			playing = false;
			break;
		case KILLER_CONFESS:
			cout << "Congratulations, you found the killer and he confessed.\n";
			cout << "Press enter to finish.\n";
			cin.getline(input, 512);
			playing = false;
			break;
		case ARREST_FAIL:
			cout << "You faild. You do not find the killer.\n";
			cout << "Press enter to play again.\n";
			cin.getline(input, 512);
			break;
		case ARREST_WITHOUT_PROOF:
			cout << "You faild. You do not find enough proof.\n";
			cout << "Press enter to play again.\n";
			cin.getline(input, 512);
			break;
		case EXIT_GAME:
			playing = false;
			break;
		default:
			playing = false;
			break;
		}
		delete world;
	}
	
	return 0;
}