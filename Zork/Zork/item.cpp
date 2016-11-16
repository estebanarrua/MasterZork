#include "item.h"

#include <iostream>

Item::Item(const char * name, const char * description, const bool isContainer, const bool isStorable):
Entity(name, description), isContainer(isContainer), isStorable(isStorable)
{
	type = ITEM;
}

Item::~Item()
{
}

void Item::Look() const
{
	string items = "";

	for (list<Entity*>::const_iterator it = container.cbegin(); it != container.cend(); ++it)
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
	cout << name + "\n" + description + "\n" + items;
}