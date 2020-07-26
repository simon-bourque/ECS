#include "Entity.h"

const Entity Entity::Null;

Entity::Entity(uint64 id) : Id(id)
{
}

Entity::Entity(const Entity& entity) : Id(entity.Id)
{
}

Entity& Entity::operator=(const Entity& entity)
{
	if (&entity == this)
	{
		return *this;
	}

	Id = entity.Id;
	return *this;
}