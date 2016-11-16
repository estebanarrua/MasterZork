#include "room.h"
#include "utilities.h"
#include "exit.h"
#include "person.h"

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
	string exits = "";
	string items = "";
	string persons = "";

	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		switch ((*it)->type)
		{
		case EXIT:
			exits += "Direction " + ((Exit*)(*it))->name + ": " + ((Exit*)(*it))->destination->name + ".\n";
			break;
		case ITEM:
			if (items == "")
				items += "There are the following items: \n";
			items += " - " + (*it)->name + ".\n";
			break;
		case PERSON:
			if (persons == "")
				persons += "The following people are here: \n";
			persons += " - " + (*it)->name + ".\n";
			break;
		default:
			break;
		}
	}
	cout << name + "\n" + description + "\n" + exits + items + persons;
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