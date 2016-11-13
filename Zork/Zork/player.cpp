#include "player.h"



Player::Player(const char* name, const char* description, Room* location):
Creature(name,description, location)
{
	type = PLAYER;
}


Player::~Player()
{
}
