#ifndef __Creature__
#define __Creature__

#include "entity.h"
#include "room.h"

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* location);
	~Creature();

public:
	Room* location;
};

#endif
