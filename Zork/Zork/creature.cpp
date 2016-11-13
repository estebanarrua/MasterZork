#include "creature.h"



Creature::Creature(const char* name, const char* description, Room* location):
Entity(name,description), location(location)
{
	type = CREATURE;
}


Creature::~Creature()
{
}
