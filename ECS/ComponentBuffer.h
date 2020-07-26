#pragma once

#include <unordered_map>

#include "ComponentInfo.h"
#include "ByteBuffer.h"
#include "Archetype.h"
#include "Entity.h"

class ComponentBuffer 
{
private:
	Archetype m_Archetype;
	ByteBuffer m_ByteBuffer;

	std::unordered_map<Entity, uint64> m_EntityOffsets;
	std::unordered_map<ComponentInfo, uint64> m_ComponentOffsets;
public:
	ComponentBuffer(const Archetype& archetype);

	Archetype GetArchetype() const { return m_Archetype; }
};