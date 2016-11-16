#ifndef __Item__
#define __Item__

#include "entity.h"

class Item : public Entity
{
public:
	bool isContainer;
	bool isStorable;

public:
	Item(const char* name, const char* description, const bool isContainer, const bool isStorable);
	~Item();

	void Look() const;
};

#endif
