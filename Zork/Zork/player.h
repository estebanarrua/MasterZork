#ifndef __Player__
#define __Player__

#include "creature.h"

#include <string>
#include <vector>

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* location);
	~Player();
	void Look(const vector<string>& arguments);
	void Go(const string& direction);
};

#endif
