#ifndef __Room__
#define __Room__

#include "entity.h"

class Room : public Entity
{

public:
	Room(const char* name, const char* description);
	~Room();
	void Look();
	Room* Go(const string& direction);

};

#endif

