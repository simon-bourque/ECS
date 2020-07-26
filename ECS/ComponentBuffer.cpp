#include "ComponentBuffer.h"

ComponentBuffer::ComponentBuffer(const Archetype& archetype) : m_Archetype(archetype)
{
	const auto& components = archetype.GetComponents();
	
	uint64 offset = 0;
	for (const auto& info : components)
	{
		m_ComponentOffsets[info] = offset;
		offset += info.Size;
	}
}