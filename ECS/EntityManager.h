#pragma once

#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Archetype.h"
#include "ByteBuffer.h"

class EntityManager
{
private:
	std::vector<Entity> m_Entities;

	std::unordered_map<Entity, Archetype> m_EntityArchetypes;
	std::unordered_map<Archetype, ByteBuffer> m_ComponentBuffers;
public:
	Entity CreateEntity();

	template<typename T>
	void AddComponent(Entity entity, const T& component);
};

template<typename T>
void EntityManager::AddComponent(Entity entity, const T& component)
{
	Archetype& archetype = m_EntityArchetypes[entity];
	archetype.AddComponentType<T>();
	
	if (m_ComponentBuffers.count(archetype) > 0)
	{
		ByteBuffer& buffer = m_ComponentBuffers[archetype];
		//buffer.Add()
	}
	else
	{
	
	}


	//auto iter = m_ComponentBuffers.find(archetype);
	//if (iter != m_ComponentBuffers.end())
	//{
	//	iter->second
	//}
	//else
	//{
	//
	//}
}