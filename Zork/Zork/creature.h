#ifndef __Creature__
#define __Creature__

#include "entity.h"
#include "room.h"

class Creature : public Entity
{

public:
	Room* location;

public:
	Creature(const char* name, const char* description, Room* location);
	~Creature();

};

#endif
