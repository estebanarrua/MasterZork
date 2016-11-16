#include "player.h"
#include "utilities.h"
#include "item.h"
#include "person.h"

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
			Person* person = (Person*)location->Find(arguments[1], PERSON);
			if (person != NULL)
				person->Look();
			else
				cout << "There is not an item or person with name " + arguments[1] +".\n";
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
			cout << "There is not an item with name " + arguments[1] + " in the room.\n";
	}
	else
	{
		Item* containerItem = (Item*)location->Find(arguments[3], ITEM);
		if (containerItem == NULL)
			containerItem = (Item*)this->Find(arguments[3], ITEM);
		if (containerItem == NULL)
			cout << "There is not an item with name " + arguments[3] + " in the romm or in your inventory.\n";
		else
		{
			Item* item = (Item*)containerItem->Find(arguments[1], ITEM);
			if (item == NULL)
				cout << "There is not an item with name " + arguments[1] + " in the item with name " + arguments[3] + ".\n";
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

void Player::Drop(const vector<string>& arguments)
{
	if (arguments.size() == 2)
	{
		Item* item = (Item*)this->Find(arguments[1], ITEM);
		if (item != NULL)
		{
			location->container.push_back(item);
			container.remove(item);
			cout << "You droped the item with name " + item->name + ".\n";
		}
		else
			cout << "There is not an item with name " + arguments[1] + " in your inventory.\n";
	}
	else
	{
		Item* containerItem = (Item*)location->Find(arguments[3], ITEM);
		if (containerItem == NULL)
			containerItem = (Item*)this->Find(arguments[3], ITEM);
		if (containerItem == NULL)
			cout << "There is not an item with name " + arguments[3] + " in the romm or in your inventory.\n";
		else
		{
			if (containerItem->isContainer)
			{
				Item* item = (Item*)this->Find(arguments[1], ITEM);
				if (item == NULL)
					cout << "There is not an item with name " + arguments[1] + " in your inventory.\n";
				else
				{
						containerItem->container.push_back(item);
						container.remove(item);
						cout << "You droped the item with name " + item->name + " into " + containerItem->name + ".\n";	
				}
			}
			else
			{
				cout << "The item with name " + containerItem->name + " is not a container. So you can not drop anything into it.\n";
			}
			
		}
	}
}

void Player::Inventory()
{
	if (container.size() == 0)
		cout << "Your inventory is empty.\n";
	else
	{
		cout << "You have the following items:\n";
		for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
		{
			cout << " - " + (*it)->name + ".\n";
		}
	}
}

void Player::Ask(const vector<string>& arguments)
{
	if (arguments.size() == 2)
	{
		Person* person = (Person*)location->Find(arguments[1], PERSON);
		if (person != NULL)
		{
			cout << person->name + ": " + person->statement + ".\n";
		}
		else
			cout << "There is not a person with name " + arguments[1] + " in the room.\n";
	}
	else
	{
		Person* person = (Person*)location->Find(arguments[1], PERSON);
		if (person == NULL)
			cout << "There is not a person with name " + arguments[1] + " in the room.\n";
		else
		{
			string ans = person->GetAnswerAbout(arguments[3]);
			cout << person->name + ": " + ans + ".\n";
		}
	}
}

void Player::Pay(const vector<string>& arguments)
{
	Item* money = (Item*)this->Find("Money", ITEM);
	if (money != NULL)
	{
		Person* person = (Person*)location->Find(arguments[1], PERSON);
		if (person == NULL)
			cout << "There is not a person with name " + arguments[1] + " in the room.\n";
		else
		{
			Item* item = (Item*)person->Find(arguments[3], ITEM);
			if (item == NULL)
				cout << "The person with name " + person->name + " does not have an item with name " + arguments[3] + ".\n";
			else
			{
				person->container.remove(item);
				container.push_back(item);
				container.remove(money);
				person->container.push_back(money);
				cout << "Now you have the item with name " + item->name + " and you do not have more money.\n";
			}
		}
	}
	else
		cout << "You do not have money to pay for " + arguments[3] + ".\n";
}
