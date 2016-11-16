#include "person.h"
#include "utilities.h"

#include <iostream>

Person::Person(const char * name, const char * description, Room * location, const bool isGuilty, const string statement, const vector<Answers> answers):
Creature(name, description, location), isGuilty(isGuilty), statement(statement), answers(answers)
{
	type = PERSON;
}

Person::~Person()
{
}

string Person::GetAnswerAbout(const string & key) const
{
	for (unsigned int i = 0; i < answers.size(); ++i) 
	{
		Answers ans = answers[i];
		if (Equal(key, ans.key)) 
		{
			return ans.answer;
		}
	}
	return "I do not have a clue about it";
}

void Person::Look()
{
	string items = "";

	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		switch ((*it)->type)
		{
		case ITEM:
			if (items == "")
				items += "She/He has the following items: \n";
			items += " - " + (*it)->name + ".\n";
			break;
		default:
			break;
		}
	}
	cout << name + "\n" + description + "\n" + items;
}
