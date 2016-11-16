#ifndef __Person__
#define __Person__

#include "creature.h"

#include <string>
#include <vector>

struct Answers 
{
	string key;
	string answer;
};

class Person : public Creature
{
public:
	bool isGuilty;
	string statement;
	vector<Answers> answers;

public:
	Person(const char* name, const char* description, Room* location, const bool isGuilty, const string statement, const vector<Answers> answers);
	~Person();
	string GetAnswerAbout(const string& key) const;
	void Look();
};

#endif
