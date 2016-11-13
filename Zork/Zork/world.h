#ifndef __World__
#define __World__

#include "entity.h"
#include "player.h"

#include <list>
#include <string>
#include <vector>

using namespace std;

class World
{

public:
	World();
	~World();
	bool ExecuteCommand(const vector<string>& arguments);
	bool ParceCommand(const vector<string>& arguments);

public:
	list<Entity*> entities;
	Player* player;
};

#endif

