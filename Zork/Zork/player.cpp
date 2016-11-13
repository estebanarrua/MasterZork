#include "player.h"



Player::Player(const char* name, const char* description):
Creature(name,description)
{
	type = PLAYER;
}


Player::~Player()
{
}
