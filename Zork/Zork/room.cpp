#include "room.h"
#include "utilities.h"
#include "exit.h"

#include <iostream>

Room::Room(const char* name, const char* description):
Entity(name,description)
{
	type = ROOM;
}


Room::~Room()
{
}

void Room::Look()
{
	cout << description << "\n";
	string exits = "";
	string items = "";

	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		switch ((*it)->type)
		{
		case EXIT:
			exits += "Direction " + ((Exit*)(*it))->name + ": " + ((Exit*)(*it))->destination->name + ".\n";
			break;
		case ITEM:
			if (items == "")
				items += "There are the following items here: \n";
			items += " - " + (*it)->name + ".\n";
			break;
		default:
			break;
		}
	}
	cout << exits << items;
}

Room* Room::Go(const string& direction)
{
	Exit* exit = (Exit*)this->Find(direction, EXIT);
	if (exit != NULL)
	{
		return exit->destination;
	}
	else 
	{
		return NULL;
	}
}
