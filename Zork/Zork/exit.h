#ifndef __Exit__
#define __Exit__

#include "entity.h"
#include "room.h"

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, Room* source, Room* detination);
	~Exit();

public:
	Room* source;
	Room* destination;
};

#endif