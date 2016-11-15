#include "entity.h"
#include "utilities.h"

Entity::Entity(const char* name, const char* description):
	name(name), description(description)
{
	type = ENTITY;
}

Entity::~Entity()
{
}

Entity * Entity::Find(const string & name, EntityType type)
{
	Entity* res = NULL;
	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		if ((*it)->type == type)
		{
			if (Equal((*it)->name, name)) {
				res = (*it);
				break;
			}
		}
	}
	return res;
}
