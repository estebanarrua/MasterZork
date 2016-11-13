#ifndef __World__
#define __World__

#include <list>;
#include "entity.h";

class World
{

public:
	World();
	~World();

public:
	list<Entity*> entities;
};

#endif

