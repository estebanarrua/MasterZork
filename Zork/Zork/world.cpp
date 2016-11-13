#include "world.h"
#include "room.h"
#include "exit.h"
#include "player.h"
#include "utilities.h"

World::World()
{
	//Rooms
	Room* bedroom1 = new Room("Bedroom_101", "Bedroom of the Room 101");
	Room* bathroom1 = new Room("Bathroom_101", "Bathroom of the Room 101");
	entities.push_back(bedroom1);
	entities.push_back(bathroom1);

	//Exits
	Exit* exit1 = new Exit("NORTH", "Door to go form the bedroom to the bathroom.", bedroom1, bathroom1);
	Exit* exit2 = new Exit("SOUTH", "Door to go from the bathroom to the bedroom.", bathroom1, bedroom1);
	entities.push_back(exit1);
	entities.push_back(exit2);

	//Player
	Player* player = new Player("Player", "Player", bathroom1);
	entities.push_back(player);

}


World::~World()
{
}

bool World::ExecuteCommand(const vector<string>& arguments)
{
	
	return ParceCommand(arguments);
}

bool World::ParceCommand(const vector<string>& arguments)
{
	if (Equal(arguments[0], "look"))
	{
		return true;
	}
	return false;
}
