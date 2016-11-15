#ifndef __Item__
#define __Item__

#include "entity.h"

class Item : public Entity
{
public:
	bool isCatchable;
	bool isContainer;
	bool isStorable;

public:
	Item(const char* name, const char* description, const bool isCatchable, const bool isContainer, const bool isStorable);
	~Item();

	void Look();
};

#endif
