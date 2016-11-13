#include "creature.h"



Creature::Creature(const char* name, const char* description):
Entity(name,description)
{
	type = CREATURE;
}


Creature::~Creature()
{
}
