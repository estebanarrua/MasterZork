#ifndef __Player__
#define __Player__

#include "creature.h"

#include <string>
#include <vector>

const enum GameState {
	PLAYING,
	ARREST_OK,
	ARREST_FAIL,
	ARREST_WITHOUT_PROOF,
	KILLER_CONFESS,
	EXIT_GAME,
};

class Player : public Creature
{
public:
	GameState state;
public:
	Player(const char* name, const char* description, Room* location, const GameState state);
	~Player();
	void Look(const vector<string>& arguments);
	void Go(const string& direction);
	void Take(const vector<string>& arguments);
	void Drop(const vector<string>& arguments);
	void Inventory();
	void Ask(const vector<string>& arguments);
	void Pay(const vector<string>& arguments);
	void Arrest(const string& name);
};

#endif
