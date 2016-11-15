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
		for (list<Entity*>::iterator it = container.begin(); it != container.end() && !found; ++it)
		{
			if (Equal((*it)->name, arguments[1]) && (*it)->type == ITEM) {
				found = true;
				((Item*)(*it))->Look();
				break;
			}
		}
		for (list<Entity*>::iterator it = location->container.begin(); it != location->container.end() && !found; ++it)
		{
			if (Equal((*it)->name, arguments[1]) && (*it)->type == ITEM) {
				found = true;
				((Item*)(*it))->Look();
				break;
			}
		}
		if (!found) {
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
		bool found = false;
		for (list<Entity*>::iterator it = location->container.begin(); it != location->container.end() && !found; ++it)
		{
			if (Equal((*it)->name, arguments[1]) && (*it)->type == ITEM) {
				found = true;
				Item* itemAux = ((Item*)(*it));
				if (itemAux->isStorable)
				{
					container.push_back(itemAux);
					location->container.remove(itemAux);
					cout << "You took the item with name " + itemAux->name + ".\n";
				}
				else
				{
					cout << "The item with name " + itemAux->name + " is not storable. So you can not take it.\n";
				}
			}
		}
		if (!found) {
			cout << "There are not any item with name " + arguments[1] + " in the room.\n";
		}
	}
	else
	{

	}
}
