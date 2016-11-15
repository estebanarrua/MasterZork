#include "item.h"

#include <iostream>

Item::Item(const char * name, const char * description, const bool isCatchable, const bool isContainer, const bool isStorable):
Entity(name, description), isCatchable(isCatchable), isContainer(isContainer), isStorable(isStorable)
{
	type = ITEM;
}

Item::~Item()
{
}

void Item::Look()
{
	cout << description << "\n";
	string items = "";

	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		switch ((*it)->type)
		{
		case ITEM:
			if (items == "")
				items += "There are the following items inside: \n";
			items += " - " + (*it)->name + ".\n";
			break;
		default:
			break;
		}
	}
	cout << items;
}
