#ifndef __Exit__
#define __Exit__

#include "entity.h"
#include "room.h"

class Exit : public Entity
{
public:
	Room* source;
	Room* destination;

public:
	Exit(const char* name, const char* description, Room* source, Room* detination);
	~Exit();

};

#endif