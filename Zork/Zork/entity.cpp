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

Entity * Entity::Find(const string & name, EntityType type) const
{
	Entity* res = NULL;
	for (list<Entity*>::const_iterator it = container.cbegin(); it != container.cend(); ++it)
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
