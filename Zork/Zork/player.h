#ifndef __Player__
#define __Player__

#include "creature.h"
class Player : public Creature
{
public:
	Player(const char* name, const char* description);
	~Player();
};

#endif
