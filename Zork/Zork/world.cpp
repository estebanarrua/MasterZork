#include "world.h"
#include "room.h"
#include "exit.h"
#include "utilities.h"

World::World()
{
	//Rooms
	Room* bedroom1 = new Room("Bedroom_101", "You are in teh bedroom of Room 101.");
	Room* bathroom1 = new Room("Bathroom_101", "You are in the bathromm of room 101. There is a body in the bath.");
	entities.push_back(bedroom1);
	entities.push_back(bathroom1);

	//Exits
	Exit* exit1 = new Exit("SOUTH", "Door to go form the bedroom to the bathroom.", bedroom1, bathroom1);
	Exit* exit2 = new Exit("NORTH", "Door to go from the bathroom to the bedroom.", bathroom1, bedroom1);
	entities.push_back(exit1);
	bedroom1->container.push_back(exit1);
	entities.push_back(exit2);
	bathroom1->container.push_back(exit2);
	

	//Player
	player = new Player("Player", "Player", bathroom1);
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
	bool result = true;
	if (Equal(arguments[0], "look"))
	{
		if (arguments.size() == 1)
		{
			player->Look(arguments);
		}
	}
	else if (Equal(arguments[0], "go"))
	{
		if (arguments.size() == 2) {
			player->Go(arguments[1]);
			player->location->Look();
		}
		else
		{
			result = false;
		}
	}
	else
	{
		result = false;
	}
	return result;
}
