#include "person.h"
#include "utilities.h"


Person::Person(const char * name, const char * description, Room * location, const bool isSuspect, const bool isWitness, const string statement, const vector<Answers> answers):
Creature(name, description, location), isSuspect(isSuspect), isWitness(isWitness), statement(statement), answers(answers)
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
	return "I do not have idea about it";
}
