#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

const enum EntityType {
	ENTITY,
	ROOM,
	CREATURE,
	PLAYER,
	EXIT,
	ITEM,
	PERSON,
};

class Entity
{
public:
	EntityType type;
	string name;
	string description;

	list<Entity*> container;

public:
	Entity(const char* name, const char* description);
	~Entity();
	Entity* Find(const string& name, EntityType type);
};

#endif


