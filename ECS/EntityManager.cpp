#include "EntityManager.h"

#include "Archetype.h"

Entity EntityManager::CreateEntity()
{
	static int64 id = 0;
	Entity entity = ++id;
	m_Entities.push_back(entity);

	m_EntityArchetypes[entity] = Archetype();

	return entity;
}