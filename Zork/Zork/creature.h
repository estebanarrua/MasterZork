#ifndef __Creature__
#define __Creature__

#include "entity.h"
class Creature : public Entity
{
public:
	Creature(const char* name, const char* description);
	~Creature();
};

#endif
