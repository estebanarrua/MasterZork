#include "player.h"
#include "utilities.h"
#include "item.h"

#include <iostream>

Player::Player(const char* name, const char* description, Room* location):
Creature(name,description, location)
{
	type = PLAYER;
}


Player::~Player()
{
}

void Player::Look(const vector<string>& arguments)
{
	if (arguments.size() > 1)
	{
		bool found = false;
		Item* item = (Item*) this->Find(arguments[1], ITEM);
		if(item == NULL)
			item = (Item*) location->Find(arguments[1], ITEM); 
		if (item != NULL)
		{
			item->Look();
		}
		else
		{
			cout << "There are not any item with name " + arguments[1] +".\n";
		}
	}
	else
	{
		location->Look();
	}
	
}

void Player::Go(const string& direction)
{
	Room* dest = location->Go(direction);
	if (dest != NULL) {
		location = dest;
	}
}

void Player::Take(const vector<string>& arguments)
{
	if (arguments.size() == 2)
	{
		Item* item = (Item*) location->Find(arguments[1], ITEM);
		if (item != NULL)
		{
			if (item->isStorable)
			{
				container.push_back(item);
				location->container.remove(item);
				cout << "You took the item with name " + item->name + ".\n";
			}
			else
				cout << "The item with name " + item->name + " is not storable. So you can not take it.\n";
		}
		else
			cout << "There are not any item with name " + arguments[1] + " in the room.\n";
	}
	else
	{
		Item* containerItem = (Item*)location->Find(arguments[3], ITEM);
		if (containerItem == NULL)
			cout << "There are not any item with name " + arguments[3] + " in the romm.\n";
		else
		{
			Item* item = (Item*)containerItem->Find(arguments[1], ITEM);
			if (item == NULL)
				cout << "There are not any item with name " + arguments[1] + "in the item with name " + arguments[3] + ".\n";
			else
			{
				if (item->isStorable)
				{
					container.push_back(item);
					containerItem->container.remove(item);
					cout << "You took the item with name " + item->name + ".\n";
				}
				else
					cout << "The item with name " + item->name + " is not storable. So you can not take it.\n";
			}
		}

	}
}
