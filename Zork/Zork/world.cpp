#include "world.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "utilities.h"

#include <iostream>

World::World()
{
	//Rooms
	Room* bedroom1 = new Room("Bedroom 101", "You are in the bedroom of Room 101.");
	Room* bathroom1 = new Room("Bathroom 101", "You are in the bathroom of room 101. There is a body in the bath.");
	Room* bedroom2 = new Room("Bedroom 102", "You are in the bedroom of Room 102.");
	Room* bathroom2 = new Room("Bathroom 102", "You are in the bathroom of Room 102.");
	Room* hall = new Room("Hall", "You are in the hall between the rooms 101 and 102.");
	Room* reception = new Room("Reception", "You are in the reception of the hotel.");
	Room* bar = new Room("Bar", "You are in the bar. Take a drink.");
	entities.push_back(bedroom1);
	entities.push_back(bathroom1);
	entities.push_back(bedroom2);
	entities.push_back(bathroom2);
	entities.push_back(hall);
	entities.push_back(reception);
	entities.push_back(bar);

	//Exits
	Exit* exit1 = new Exit("South", "Door to go form the bedroom to the bathroom.", bedroom1, bathroom1);
	entities.push_back(exit1);
	bedroom1->container.push_back(exit1);
	Exit* exit2 = new Exit("North", "Door to go from the bathroom to the bedroom.", bathroom1, bedroom1);
	entities.push_back(exit2);
	bathroom1->container.push_back(exit2);
	Exit* exit3 = new Exit("West", "Door to go out from the room 101.", bedroom1, hall);
	entities.push_back(exit3);
	bedroom1->container.push_back(exit3);
	Exit* exit4 = new Exit("East", "Door to go to the room 101.", hall, bedroom1);
	entities.push_back(exit4);
	hall->container.push_back(exit4);
	Exit* exit5 = new Exit("West", "Door to go to the room 102.", hall, bedroom2);
	entities.push_back(exit5);
	hall->container.push_back(exit5);
	Exit* exit6 = new Exit("Down", "Stairs to go down.", hall, reception);
	entities.push_back(exit6);
	hall->container.push_back(exit6);
	Exit* exit7 = new Exit("South", "Door to go form the bedroom to the bathroom.", bedroom2, bathroom2);
	entities.push_back(exit7);
	bedroom2->container.push_back(exit7);
	Exit* exit8 = new Exit("North", "Door to go from the bathroom to the bedroom.", bathroom2, bedroom2);
	entities.push_back(exit8);
	bathroom2->container.push_back(exit8);
	Exit* exit9 = new Exit("East", "Door to go out from the room 102.", bedroom2, hall);
	entities.push_back(exit9);
	bedroom2->container.push_back(exit9);
	Exit* exit10 = new Exit("East", "Door to go to the bar.", reception, bar);
	entities.push_back(exit10);
	reception->container.push_back(exit10);
	Exit* exit11 = new Exit("Up", "Stairs to go up.", reception, hall);
	entities.push_back(exit11);
	reception->container.push_back(exit11);
	Exit* exit12 = new Exit("West", "Door to go to the reception.", bar, reception);
	entities.push_back(exit12);
	bar->container.push_back(exit12);

	//Items
	Item* item1 = new Item("Desk", "A big desk of the room 101", false, true, false);
	bedroom1->container.push_back(item1);
	Item* item2 = new Item("Report", "FORENSIC REPORT\nThe body is a men between 30 and 40 years old.\nThe hour of death was between 23:00 and 00:00 yesterday.\nThe cause of death was a stab in the abdominal area.", true, false, true);
	item1->container.push_back(item2);
	Item* item3 = new Item("Wallet", "A black leather wallet", true, true, true);
	item1->container.push_back(item3);

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
		if (arguments.size() <= 2)
		{
			player->Look(arguments);
		}
		else
		{
			cout << "The command look only accept 1 or less parameters.";
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
			cout << "The command go only accept 1 parameter.";
		}
	}
	else if (Equal(arguments[0], "take"))
	{
		if (arguments.size() == 2 || arguments.size() == 4) 
		{
			player->Take(arguments);
		}
		else
		{
			cout << "The command go only accept 2 or 4 parameters.";
		}
	}
	else
	{
		result = false;
	}
	return result;
}
